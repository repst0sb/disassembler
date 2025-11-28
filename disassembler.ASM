        include '\encoding\win1251.inc'
        include '\win32w.inc'

        format PE
        entry WinMain

        include         'Units\Instructions.h'

REGISTER         =      0000_0000b
MEMORY           =      0010_0000b
CONST            =      0011_0000b
SEGMENT_REG      =      0000_1000b

STATE_MODRM      =      $01
STATE_CONST      =      $02
STATE_END        =      $ff

SIZE_8           =      0100_0000b
SIZE_16          =      1000_0000b

REG_AL           =      0100_0000b
REG_AX           =      1000_0000b

section '.code' code readable writeable executable

proc WinMain
        invoke        GetCommandLine
        invoke        CommandLineToArgvW, eax, .argvNum
        push          eax
        cmp           [.argvNum], 3
        jne           .EndProc
        mov           ebx, eax

        stdcall       ReadFileProc, [ebx+4]
        mov           edi, eax
        mov           ecx, eax
        add           ecx, [Mas]
        push          ecx
        invoke        CreateFile, [ebx+8], GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL
        test          edi,  edi
        jz            .EndProc
        push          eax
        invoke        WriteFile, eax , bom, 2,.nBytes, NULL
        pop           eax
        mov           ebx, [Mas]
        pop           ecx

.loop:
        push          ecx
        push          eax
        push          eax
        stdcall       Avto, ebx, Inst
        mov           ebx, eax
        pop           eax
        stdcall       WriteFileProc, Inst, eax
        pop           eax
        pop           ecx
        cmp           ebx, ecx
        jb            .loop
        jmp           .EndProc

.EndProc:
        pop           eax
        invoke        LocalFree, eax
        invoke        ExitProcess, 0

.argvNum                      db      ?
.nBytes                       dd      ?
endp

proc ReadFileProc, NameBIN
        invoke        CreateFile,[NameBIN], GENERIC_READ , FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL

        push          eax
        push          eax
        invoke        GetFileSize, eax, NULL
        mov           [.FileSize], eax
        invoke        GetProcessHeap
        invoke        HeapAlloc, eax, HEAP_ZERO_MEMORY, [.FileSize]
        mov           [Mas], eax
        pop           eax
        invoke        ReadFile, eax, [Mas], [.FileSize],.nBytes, NULL
        pop           eax
        invoke        CloseHandle, eax

.EndProc:
        mov           eax, [.FileSize]
        ret

.FileSize                     dd      0
.nBytes                       dd      ?

endp

proc WriteFileProc uses ebx, stru, handle
        mov           ebx, [stru]
        mov           edx, 12
        movzx         eax, word[ebx + Instructions.opcode]
        mul           edx
        add           eax, T4
        stdcall       WriteStr,eax,[handle]
        stdcall       WriteStr, space, [handle]

        stdcall       OpPrint,dword[ebx + Instructions.optype1], [handle], [stru]
        cmp           [ebx + Instructions.optype2], 0
        je            .EndProc
        stdcall       WriteStr, comma, [handle]
        stdcall       OpPrint,dword[ebx + Instructions.optype2], [handle], [stru]
.EndProc:
        stdcall       WriteStr, entstr, [handle]
        ret

endp

proc OpPrint uses ebx, optype,handle, stru
        movzx         eax, byte[optype]
        and           eax, 0011_0000b
        cmp           eax, REGISTER
        jne           .Mem
        stdcall       RegPrint, [optype], [handle], [stru]
        jmp           .EndProc
.Mem:
        cmp           eax, MEMORY
        jne           .Const
        stdcall       MemPrint, [optype], [handle], [stru]
        jmp           .EndProc

.Const:
        stdcall       ConstPrint, [optype], [handle], [stru]
.EndProc:
        ret
endp

proc ConstPrint optype, handle, stru
        mov           ebx, [stru]
        mov           eax, [ebx + Instructions.const]
        stdcall       HexPrint, eax
        stdcall       WriteStr,disp,[handle]

.EndProc:
        ret
endp

proc RegPrint uses ebx, optype, handle, stru
        movzx         eax, byte[optype]
        and           eax, 0000_1000b
        cmp           eax, SEGMENT_REG
        je            .SegReg
        movzx         eax, byte[optype]
        and           eax, 1100_0000b
        cmp           eax, SIZE_8
        jne           @F
        movzx         eax, byte[optype]
        and           ax, 0000_0111b
        shl           ax, 3
        add           eax, T2
        stdcall       WriteStr,eax,[handle]
        jmp           .EndProc

@@:
        movzx         eax, byte[optype]
        and           ax, 0000_0111b
        shl           ax, 3
        add           eax, T3
        stdcall       WriteStr,eax,[handle]
        jmp           .EndProc

.SegReg:
        movzx         eax, byte[optype]
        and           ax, 0000_0111b
        shl           ax, 3
        add           eax, T6
        stdcall       WriteStr,eax,[handle]
;        jmp           .EndProc

.EndProc:
        ret
endp

proc MemPrint uses ebx edx, optype, handle, stru
        mov           ebx, [stru]
        stdcall       WriteStr,opbr,[handle]
        mov           edx, 12
        movzx         eax, byte[optype]
        and           ax, 1100_0111b
        cmp           ax, 0000_0110b
        jne           @F
        mov           eax, [ebx + Instructions.memSh]
        jmp           .Continue

@@:
        movzx         eax, byte[optype]
        and           ax, 0000_0111b
        mul           edx
        add           eax, T5
        stdcall       WriteStr,eax,[handle]
        cmp           [ebx + Instructions.memSh], 0
        jz            .EndProc
        test          [ebx + Instructions.memSh], $80000000
        jz            @F
        stdcall       WriteStr, minus, [handle]
        mov           eax, [ebx + Instructions.memSh]
        neg           eax
        jmp           .Continue
@@:
        stdcall       WriteStr, plus, [handle]
        mov           eax, [ebx + Instructions.memSh]
        jmp           .Continue

.Continue:
        stdcall       HexPrint, eax
        stdcall       WriteStr,disp,[handle]

.EndProc:
        stdcall       WriteStr,clbr,[handle]
        ret
endp

proc HexPrint uses ebx, numHex
        mov           ebx, [numHex]
        mov           ecx, 4

@@:
        mov           ax, bx
        and           al, 0000_0000_0000_1111b
        cmp           al, $0A
        sbb           al, $69
        das
        xor           ah, ah
        mov           [disp+ecx*2], ax
        ror           ebx, 4
        loop          @B

        ret
endp

proc WriteStr str, handle
        mov           eax, [str]
        xor           ecx, ecx
.loop:
        mov           dx, [eax + ecx*2]
        test          dx, dx
        je            .EndProc
        lea           edx, [eax + ecx*2]
        push          eax ecx
        invoke        WriteFile, [handle],edx, 2,.nBytes, NULL
        pop           ecx eax
        inc           ecx
        jmp           .loop
.EndProc:
        ret

.nBytes                       dd      ?
endp

proc Avto uses esi ebx, start, stru

        locals
         state          dd      ?
        endl

        mov           esi, [start]
        movzx         ebx, byte[esi]
        mov           [state], 0
        stdcall       [T1 + ebx*4], [stru], [esi]
        mov           [state], eax
        inc           esi
        cmp           [state], STATE_MODRM
        jne           .Const
        stdcall       ModRM, esi, [stru]
        add           esi, eax
        jmp           .EndProc

.Const:
        cmp           [state], STATE_CONST
        jne           .EndProc
        stdcall       Const, esi, [stru]
        add           esi, eax

.EndProc:
        mov           eax, esi
        ret

endp

proc Const uses ebx, bt, stru

        locals
         numBt        db      ?
        endl

        mov           ebx, [stru]
        movzx         eax, byte[ebx + Instructions.optype1]
        and           ax, 1100_0000b
        cmp           ax, SIZE_8
        jne           @F
        movzx         eax, byte[esi]
        mov           [ebx + Instructions.const], eax
        mov           [numBt], 1
        jmp           .EndProc

@@:
        movzx         eax, word[esi]
        mov           [ebx + Instructions.const], eax
        mov           [numBt], 2

.EndProc:
        movzx         eax, byte[numBt]
        ret
endp

proc ModRM uses ebx esi edi, bt, stru

        locals
         numBt        db      ?
        endl

        mov           [numBt], 1
        mov           esi, [bt]
        movzx         eax, byte[esi]
        mov           ebx, [stru]
        movzx         edx, byte[ebx + Instructions.optype1]
        and           edx, 0011_0000b
        cmp           edx, REGISTER
        jne            @F
        and           eax, 0011_1000b
        shr           eax, 3
        and           [ebx + Instructions.optype1], 1111_0000b
        or            [ebx + Instructions.optype1], al
        jmp           .Optype2
@@:
        push          eax
        and           eax, 1100_0000b
        cmp           eax, 0000_0000b
        jnz           @F
        pop           eax
        and           eax, 1100_0111b
        and           [ebx + Instructions.optype1], 0011_0000b
        or            [ebx + Instructions.optype1], al
        and           eax, 0000_0111b
        cmp           eax, 0000_0110b
        je            .disp1
        mov           [ebx + Instructions.memSh], 0
        jmp           .Optype2

.disp1:
        inc           esi
        movsx         edi, word[esi]
        mov           [ebx + Instructions.memSh], edi
        add           [numBt], 2
        jmp           .Optype2

@@:
        cmp           eax, 0100_0000b
        jne           @F
        pop           eax
        and           eax, 1100_0111b
        and           [ebx + Instructions.optype1], 0011_0000b
        or            [ebx + Instructions.optype1], al
        inc           esi
        movsx         edi, byte[esi]
        mov           [ebx + Instructions.memSh], edi
        add           [numBt], 1
        jmp           .Optype2

@@:
        cmp           eax, 1000_0000b
        jne           @F
        pop           eax
        and           eax, 1100_0111b
        and           [ebx + Instructions.optype1], 0011_0000b
        or            [ebx + Instructions.optype1], al
        inc           esi
        movsx         edi, word[esi]
        mov           [ebx + Instructions.memSh], edi
        add           [numBt], 2
        jmp           .Optype2

@@:
        pop           eax
        and           eax, 0000_0111b
        and           [ebx + Instructions.optype1], 1100_0000b
        or            [ebx + Instructions.optype1], REGISTER
        and           [ebx + Instructions.optype1], 1111_0000b
        or            [ebx + Instructions.optype1], al

.Optype2:
        mov           esi, [bt]
        mov           eax, [esi]
        movzx         edx, byte[ebx + Instructions.optype2]
        and           edx, 0011_0000b
        cmp           edx, REGISTER
        jne            @F
        and           eax, 0011_1000b
        shr           eax, 3
        and           [ebx + Instructions.optype2], 1111_0000b
        or            [ebx + Instructions.optype2], al
        jmp           .EndProc
@@:
        push          eax
        and           eax, 1100_0000b
        cmp           eax, 0000_0000b
        jnz           @F
        pop           eax
        and           eax, 1100_0111b
        and           [ebx + Instructions.optype2], 0011_0000b
        or            [ebx + Instructions.optype2], al
        and           eax, 0000_0111b
        cmp           eax, 0000_0110b
        je            .disp2
        mov           [ebx + Instructions.memSh], 0
        jmp           .EndProc

.disp2:
        inc           esi
        movsx         edi, word[esi]
        mov           [ebx + Instructions.memSh], edi
        add           [numBt], 2
        jmp           .EndProc

@@:
        cmp           eax, 0100_0000b
        jne           @F
        pop           eax
        and           eax, 1100_0111b
        and           [ebx + Instructions.optype2], 0011_0000b
        or            [ebx + Instructions.optype2], al
        inc           esi
        movsx         edi, byte[esi]
        mov           [ebx + Instructions.memSh], edi
        add           [numBt], 1
        jmp           .EndProc

@@:
        cmp           eax, 1000_0000b
        jne           @F
        pop           eax
        and           eax, 1100_0111b
        and           [ebx + Instructions.optype2], 0011_0000b
        or            [ebx + Instructions.optype2], al
        inc           esi
        movsx         edi, word[esi]
        mov           [ebx + Instructions.memSh], edi
        add           [numBt], 2
        jmp           .EndProc

@@:
        pop           eax
        and           eax, 0000_0111b
        and           [ebx + Instructions.optype2], 1100_0000b
        or            [ebx + Instructions.optype2], REGISTER
        and           [ebx + Instructions.optype2], 1111_0000b
        or            [ebx + Instructions.optype2], al

.EndProc:
        movzx         eax, byte[numBt]
        ret
endp

proc ProcOp optypeN

endp

        include       'Units\Instructions.c'

section '.data' data readable writeable

Mas                          dd      ?
Inst                         Instructions

section '.idata' data import readable writeable

library kernel, 'kernel32.dll',\
        shell, 'shell32.dll'
  
import kernel,\
            GetProcessHeap, 'GetProcessHeap',\
            HeapAlloc,  'HeapAlloc',\
            HeapFree, 'HeapFree',\
            CreateFile, 'CreateFileW',\
            GetFileSize, 'GetFileSize',\
            ReadFile, 'ReadFile',\
            WriteFile, 'WriteFile',\
            CloseHandle, 'CloseHandle',\
            GetCommandLine, 'GetCommandLineW',\
            LocalFree, 'LocalFree',\
            ExitProcess, 'ExitProcess'

import shell,\
            CommandLineToArgvW, 'CommandLineToArgvW'

disp                         du      "$0000",0
bom                          dw      $FEFF
opbr                         du      "[",0
clbr                         du      "]",0
minus                        du      "-",0
plus                         du      "+",0
comma                        du      ", ",0
space                        du      " ",0
entstr                       dw      13, 10,0
T1                           dd      ADD_00,ADD_01,ADD_02,ADD_03,ADD_04,ADD_05,PUSH_SEG,POP_SEG,OR_08,OR_09,OR_0A,OR_0B,OR_0C,OR_0D,PUSH_SEG,POP_SEG,ADC_10,ADC_11,ADC_12,ADC_13,ADC_14,ADC_15,PUSH_SEG,POP_SEG,\
                                     SBB_18,SBB_19,SBB_1A,SBB_1B,SBB_1C,SBB_1D,PUSH_SEG,POP_SEG,AND_20,AND_21,AND_22,AND_23,AND_24,AND_25,0,0,SUB_28,SUB_29,SUB_2A,SUB_2B,SUB_2C,SUB_2D,0,0,\
                                     XOR_30,XOR_31,XOR_32,XOR_33,XOR_34,XOR_35,0,0,CMP_38,CMP_39, CMP_3A,CMP_3B,CMP_3C,CMP_3D,0,0,INC_REG,INC_REG,INC_REG,INC_REG,INC_REG,INC_REG,INC_REG,INC_REG,\
                                     DEC_REG,DEC_REG,DEC_REG,DEC_REG,DEC_REG,DEC_REG,DEC_REG,DEC_REG, PUSH_REG, PUSH_REG, PUSH_REG, PUSH_REG, PUSH_REG, PUSH_REG, PUSH_REG, PUSH_REG,\
                                     POP_REG, POP_REG, POP_REG, POP_REG, POP_REG, POP_REG, POP_REG, POP_REG
T2                           du      "al",0,0,"cl",0,0,"dl",0,0,"bl",0,0,"ah",0,0,"ch",0,0,"dh",0,0,"bh",0,0
T3                           du      "ax",0,0,"cx",0,0,"dx",0,0,"bx",0,0,"sp",0,0,"bp",0,0,"si",0,0,"di",0,0
T4                           du      "add",0,0,0,"or",0,0,0,0,"adc",0,0,0,"sbb",0,0,0,"and",0,0,0,"sub",0,0,0,"xor",0,0,0,"cmp",0,0,0,"push",0,0,"pop",0,0,0,"inc",0,0,0,"dec",0,0,0
T5                           du      "bx+si",0,"bx+di",0,"bp+si",0,"bp+di",0,"si",0,0,0,0,"di",0,0,0,0,"bp",0,0,0,0,"bx",0,0,0,0
T6                           du      "es",0,0,"cs",0,0,"ss",0,0,"ds",0,0