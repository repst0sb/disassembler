        include '\encoding\win1251.inc'
        include '\win32w.inc'

        format PE GUI 4.0
        entry WinMain

        include         'Units\Instructions.h'
        include         'Units\window.h'

MODE_16           =      0000_0001b
MODE_32           =      0000_0010b

REGISTER          =      0000_0000b
MEMORY            =      0010_0000b
CONST             =      0011_0000b
SEGMENT_REG       =      0000_1000b

SIGN_CONST        =      0000_0100_0000_0000b
FIN_BIT           =      0000_1000_0000_0000b

SIZE_DEF          =      0000_0010_0000_0000b
SIZE_8            =      0000_0001_0000_0000b
SIZE_16           =      0000_0010_0000_0000b
SIZE_32           =      0000_0011_0000_0000b

REG_AL            =      0000_0001_0000_0000b
REG_AX            =      0000_0010_0000_0000b
REG_CL            =      0000_0001_0000_0001b

FLAG_MODRM        =      0000_0001b
FLAG_IMM          =      0000_0010b
FLAG_POST_PROCESS =      0000_0100b

MASK_OPER         =      0000_0111b
MASK_SEGREG       =      0000_1000b
MASK_OPTYPE       =      0011_0000b
MASK_MOD          =      1100_0000b
MASK_SIZE         =      0000_0011_0000_0000b
MASK_SIGN         =      0000_0100_0000_0000b

MASK_REG          =      0011_1000b
MASK_MEM          =      0000_0111b

MASK_BP           =      0000_0110b
MASK_EBP          =      0000_0101b
MASK_SIB          =      0000_0100b

MASK_INDEX        =      0011_1000b
MASK_BASE         =      0000_0111b
MASK_SS           =      1100_0000b


section '.code' code readable writeable executable

proc WinMain
        invoke        GetCommandLine
        invoke        CommandLineToArgvW, eax, .argvNum
        mov           ebx, eax
        push          eax
        mov           [flag], MODE_16
        mov           esi, 1

        cmp           [.argvNum], 4
        ja            .EndProc
        je            .withMode
        cmp           [.argvNum], 3
        je            .conDef
        stdcall       Window
        jmp           .EndProc

.withMode:
        mov           ecx, [ebx+4*esi]
        stdcall       wStringToNum, ecx
        inc           esi
        cmp           eax, 16
        je            .conDef
        cmp           eax, 32
        jne           .EndProc
        mov           [flag], MODE_32

.conDef:
        mov           eax, [ebx+4*esi]
        inc           esi
        mov           [FileBin], eax
        mov           eax, [ebx+esi*4]
        mov           [FileTxt], eax
        invoke        CreateFile, [FileTxt], GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL
        mov           ebx, eax
        invoke        WriteFile, eax , bom, 2,.nBytes, NULL
        stdcall       Start, ebx

.EndProc:
        invoke        GetProcessHeap
        invoke        HeapFree, eax, 0, [Mas]
        pop           eax
        invoke        LocalFree, eax
        invoke        ExitProcess, 0

.argvNum                      dd      ?
.nBytes                       dd      ?
endp

proc Start handle
        stdcall       ReadFileProc, [FileBin]
        mov           edi, eax
        test          edi,  edi
        jz            .EndProc
        mov           ecx, eax
        mov           ebx, [Mas]
        add           ecx, ebx

.loop:
        push          ecx
        stdcall       Avto, ebx, Inst, ecx
        mov           ebx, eax
        stdcall       WriteFileProc, Inst, [handle]
        pop           ecx
        cmp           ebx, ecx
        jb            .loop

.EndProc:
        ret
endp

proc wStringToNum uses ebx esi, string
        xor           edx, edx
        xor           eax, eax
        mov           ecx, 10
        mov           esi,[string]
        cmp           word[esi], 0
        je            .EndProc

@@:
        lodsw
        sub           ax, "0"
        cmp           word[esi], 0
        je            @F
        mul           ecx
        add           edx, eax
        jmp           @B

@@:
        add           edx, eax

.EndProc:
        xchg          eax, edx
        ret

endp

proc ReadFileProc uses ebx, NameBIN
        invoke        CreateFile,[NameBIN], GENERIC_READ , FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
        push          eax
        push          eax
        invoke        GetFileSize, eax, NULL
        mov           ebx, eax
        add           ebx, 16
        mov           [.FileSize], eax
        invoke        GetProcessHeap
        invoke        HeapAlloc, eax, HEAP_ZERO_MEMORY, ebx
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
        movzx         eax, word[ebx + Instructions.opcode]
        push          eax
        shl           eax, 4
        add           eax, T4
        stdcall       WriteStr,eax,[handle]
        stdcall       WriteStr, space, [handle]

.Operand:
        cmp           [ebx + Instructions.optype1], 0
        je            @F
        stdcall       OpPrint,dword[ebx + Instructions.optype1], [handle], [stru]

@@:
        cmp           [ebx + Instructions.optype2], 0
        je            @F
        stdcall       WriteStr, comma, [handle]
        stdcall       OpPrint,dword[ebx + Instructions.optype2], [handle], [stru]

@@:
        pop           eax
        cmp           eax, UNKNOWN_OPCODE
        jne           .EndProc
        stdcall       WriteStr, semicl, [handle]
        mov           edx,[ebx + Instructions.const]
        mov           [letter], dx
        stdcall       WriteStr, letter, [handle]

.EndProc:
        stdcall       WriteStr, entstr, [handle]
        ret

endp

proc OpPrint uses ebx, optype,handle, stru
        movzx         eax, word[optype]
        and           eax, MASK_OPTYPE
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

proc ConstPrint uses ebx, optype, handle, stru
        mov           ebx, [stru]
        mov           eax, [ebx + Instructions.const]
        movzx         edx, word[optype]
        and           edx, MASK_SIGN
        cmp           edx, SIGN_CONST
        je            .Size16S
        movzx         edx, word[optype]
        and           edx, MASK_SIZE
        cmp           edx, SIZE_8
        jne           .Size16
        stdcall       HexPrint, eax, oneb, 2
        stdcall       WriteStr,oneb,[handle]
        jmp           .EndProc

.Size16:
        cmp           [flag], MODE_16
        jne           .Size32
        cmp           edx, SIZE_16
        jne           .Jmpfar16

.Size16S:

        stdcall       HexPrint, eax, twob, 4
        stdcall       WriteStr,twob,[handle]
        jmp           .EndProc

.Jmpfar16:
        push          eax
        and           eax, $FFFF_0000
        shr           eax, 16
        stdcall       HexPrint, eax, twob, 4
        stdcall       WriteStr,twob,[handle]
        stdcall       WriteStr,colon,[handle]
        pop           eax
        and           eax, $0000_FFFF
        stdcall       HexPrint, eax, twob, 4
        stdcall       WriteStr,twob,[handle]
        jmp           .EndProc

.Size32:
        stdcall       HexPrint, eax, fourb, 8
        stdcall       WriteStr,fourb,[handle]

.EndProc:
        ret
endp

proc RegPrint uses ebx, optype, handle, stru
        movzx         eax, word[optype]
        mov           ebx, eax
        and           ax, MASK_OPER
        shl           ax, 3

        and           ebx, MASK_SEGREG
        cmp           ebx, SEGMENT_REG
        je            .SegReg

        movzx         ebx, word[optype]
        and           ebx, MASK_SIZE
        cmp           ebx, SIZE_8
        jne           .mode
        add           eax, T2
        jmp           .EndProc

.mode:
        cmp           [flag], MODE_16
        jne           .mode32
        add           eax, T3
        jmp           .EndProc

.mode32:
        add           eax, T7
        jmp           .EndProc

.SegReg:
        add           eax, T6

.EndProc:
        stdcall       WriteStr,eax,[handle]
        ret
endp

proc MemPrint uses ebx esi, optype, handle, stru
        mov           ebx, [stru]
        movzx         eax, word[optype]
        and           eax, MASK_SIZE
        cmp           eax, SIZE_8
        je            .size8
        cmp           [flag], MODE_16
        jne           .size32
        stdcall       WriteStr,wstr,[handle]
        jmp           .Mem

.size32:
        stdcall       WriteStr,dstr,[handle]
        jmp           .Mem

.size8:
        stdcall       WriteStr,bstr,[handle]
.Mem:
        stdcall       WriteStr,opbr,[handle]
        mov           edx, 12
        movzx         eax, word[optype]
        and           ax, MASK_MOD or MASK_OPER
        cmp           [flag], MODE_16
        jne           .cmpEBP
        cmp           ax, MASK_BP
        jne           .wrtReg
        jmp           @F

.cmpEBP:
        cmp           ax, MASK_EBP
        jne           .cmpSIB

@@:
        mov           eax, [ebx + Instructions.memSh]
        jmp           .Continue

.cmpSIB:
        and           eax, MASK_OPER
        cmp           ax, MASK_SIB
        jne           .wrtReg

.sib:
        movzx         eax, byte[ebx + Instructions.SIBbyte]
        and           ax, MASK_BASE
        movzx         esi, word[optype]
        and           esi, MASK_MOD
        cmp           esi, 0000_0000b
        jne           .base
        cmp           ax, MASK_EBP
        je            .index

.base:
        shl           eax, 3
        add           eax, T7
        stdcall       WriteStr, eax, [handle]

.index:
        movzx         eax, byte[ebx + Instructions.SIBbyte]
        and           ax, MASK_INDEX
        shr           eax, 3
        cmp           ax, MASK_SIB
        je            .sibmem

        movzx         eax, word[optype]
        and           ax, MASK_MOD
        cmp           ax, 0000_0000b
        jne           .hasbase

        movzx         eax, byte[ebx + Instructions.SIBbyte]
        and           ax, MASK_BASE
        cmp           ax, MASK_EBP
        je            .nobase

.hasbase:
        stdcall       WriteStr, plus, [handle]

.nobase:
        movzx         eax, byte[ebx + Instructions.SIBbyte]
        and           ax, MASK_INDEX
        add           eax, T7
        stdcall       WriteStr,eax,[handle]

        movzx         eax, byte[ebx + Instructions.SIBbyte]
        and           ax, MASK_SS
        cmp           ax, 0000_0000b
        je            .memsh
        cmp           ax, 0100_0000b
        je            .ss2
        cmp           ax, 1000_0000b
        je            .ss4
        mov           eax, 8
        jmp           .wrtSS

.ss2:
        mov           eax, 2
        jmp           .wrtSS

.ss4:
        mov           eax, 4

.wrtSS:
        stdcall       HexPrint, eax, scale, 1
        stdcall       WriteStr,scale,[handle]
        jmp           .memsh


.wrtReg:
        movzx         eax, word[optype]
        and           ax, MASK_OPER
        cmp           [flag], MODE_16
        je            .reg16
        shl           eax, 3
        add           eax, T7
        stdcall       WriteStr,eax,[handle]
        jmp           .memsh

.reg16:
        mul           edx
        add           eax, T5
        stdcall       WriteStr,eax,[handle]

.memsh:
        cmp           [ebx + Instructions.memSh], 0
        jz            .EndProc
        test          [ebx + Instructions.memSh], $80000000
        jz            .umem
        stdcall       WriteStr, minus, [handle]
        mov           eax, [ebx + Instructions.memSh]
        neg           eax
        jmp           .Continue

.umem:
        stdcall       WriteStr, plus, [handle]
        mov           eax, [ebx + Instructions.memSh]
        jmp           .Continue


.sibmem:
        movzx         eax, word[optype]
        and           ax, MASK_MOD
        cmp           ax, 0000_0000b
        jne           .memsh
        cmp           [ebx + Instructions.memSh], 0
        jz            .EndProc
        mov           eax, [ebx + Instructions.memSh]

.Continue:
        cmp           [flag], MODE_16
        jne           @F
        stdcall       HexPrint, eax, twob, 4
        stdcall       WriteStr,twob,[handle]
        jmp           .EndProc

@@:
        stdcall       HexPrint, eax, fourb, 8
        stdcall       WriteStr,fourb,[handle]

.EndProc:
        stdcall       WriteStr,clbr,[handle]
        ret
endp

proc HexPrint uses ebx esi, numHex, string, num
        mov           esi, [string]
        mov           ebx, [numHex]
        mov           ecx, [num]

@@:
        mov           ax, bx
        and           al, 0000_0000_0000_1111b
        cmp           al, $0A
        sbb           al, $69
        das
        xor           ah, ah
        mov           [esi+ecx*2], ax
        ror           ebx, 4
        loop          @B
        ret
endp

proc WriteStr uses ebx, str, handle
        mov           ebx, [str]
        mov           eax, [handle]
        cmp           eax, [edithWnd]
        je            .WriteToWindow

.WriteToFile:
        xor           ecx, ecx
.loop:
        mov           dx, [ebx + ecx*2]
        test          dx, dx
        je            .EndProc
        lea           edx, [ebx + ecx*2]
        push          ecx
        invoke        WriteFile, [handle],edx, 2,.nBytes, NULL
        pop           ecx
        inc           ecx
        jmp           .loop

.WriteToWindow:
        invoke        SendMessage, [handle], EM_SETSEL, -1, -1
        invoke        SendMessage, [handle], EM_REPLACESEL,FALSE, ebx
.EndProc:
        ret

.nBytes                       dd      ?
endp

proc Avto uses esi ebx edi, start, stru, endMas

        mov           esi, [start]
        movzx         ebx, byte[esi]
        mov           edi, [stru]
        mov           byte[edi + Instructions.flags], 0

        cmp           [T1 + ebx*4], 0
        jne           .Opcode

.Unknown:
        stdcall       UNKNOWN, [stru], [esi]
        jmp           .StateModRM

.Opcode:
        stdcall       [T1 + ebx*4], [stru], [esi]
        cmp           [edi + Instructions.opcode], UNKNOWN_OPCODE
        je            .StateModRM
        inc           esi

.StateModRM:
        movzx         edx, byte[edi + Instructions.flags]
        test          edx, FLAG_MODRM
        jz            .StateConst
        stdcall       ModRM, esi, [stru]
        add           esi, eax

.StateConst:
        movzx         edx, byte[edi + Instructions.flags]
        test          edx, FLAG_IMM
        jz            .PostProcess
        stdcall       Const, esi, [stru]
        add           esi, eax

.PostProcess:
        movzx         edx, byte[edi + Instructions.flags]
        test          edx, FLAG_POST_PROCESS
        jz            .EndProc
        mov           esi, [start]
        jmp           .Opcode

.EndProc:
        cmp           esi, [endMas]
        jle           .End
        mov           esi, [start]
        jmp           .Unknown

.End:
        mov           eax, esi
        ret

endp

proc Const uses ebx esi, bt, stru

        locals
         numBt        db      0
        endl

        mov           esi, [bt]
        mov           ebx, [stru]
        movzx         eax, word[ebx + Instructions.optype1]
        and           eax, MASK_OPTYPE
        cmp           eax, CONST
        jne           .optp2
        movzx         eax, word[ebx + Instructions.optype1]
        jmp           .Next

.optp2:
        movzx         eax, word[ebx + Instructions.optype2]

.Next:
        and           ax, MASK_SIZE
        cmp           ax, SIZE_8
        jne           .sizeDef
        movsx         eax, byte[esi]
        inc           [numBt]
        jmp           .EndProc

.sizeDef:
        cmp           [flag], MODE_16
        jne           .size32
        cmp           ax, SIZE_16
        jne           .size32
        movsx         eax, word[esi]
        add           [numBt], 2
        jmp           .EndProc

.size32:
        mov           eax, dword[esi]
        add           [numBt], 4

.EndProc:
        add           [ebx + Instructions.const], eax
        movzx         eax, byte[numBt]
        ret
endp

proc ModRM uses ebx esi, bt, stru

        locals
         numBt        db      ?
        endl

        mov           [numBt], 1
        mov           esi, [bt]
        movzx         eax, byte[esi]
        mov           ebx, [stru]
        movzx         edx,word[ebx + Instructions.optype1]
        and           edx, FIN_BIT
        test          edx, edx
        jnz           .Op2
        stdcall       ProcOp, [stru], esi, Instructions.optype1
        add           [numBt], al

.Op2:
        movzx         edx,word[ebx + Instructions.optype2]
        test          edx, edx
        jz            .EndProc
        and           edx, FIN_BIT
        test          edx, edx
        jnz           .EndProc
        movzx         edx,word[ebx + Instructions.optype2]
        and           edx, MASK_OPTYPE
        cmp           edx, CONST
        je            .EndProc
        stdcall       ProcOp, [stru], esi, Instructions.optype2
        add           [numBt], al

.EndProc:
        movzx         eax, byte[numBt]
        ret
endp

proc ProcOp uses ebx esi edi, stru, bt, optypeN

        locals
         numBt        db      0
        endl

        mov           esi, [bt]
        movzx         eax, byte[esi]
        mov           ebx, [stru]
        mov           edi, [optypeN]
        movzx         edx, word[ebx + edi]
        and           edx, MASK_OPTYPE
        cmp           edx, REGISTER
        jne           .memory
        and           eax, MASK_REG
        shr           eax, 3
        and           word[ebx + edi],MASK_SIZE or MASK_OPTYPE
        or            [ebx + edi], ax
        jmp           .EndProc

.memory:
        push          eax
        and           eax, MASK_MOD
        cmp           eax, 0000_0000b
        jne           .mod01
        pop           eax
        and           eax, MASK_MOD or MASK_MEM
        and           word[ebx + edi], MASK_SIZE or MASK_OPTYPE
        or            [ebx + edi], ax
        and           eax, MASK_MEM
        cmp           [flag], MODE_16
        jne           .mod00_32
        cmp           eax, MASK_BP
        jne           .nomemsh
        jmp           .disp16

.mod00_32:
        cmp           eax, MASK_SIB
        je            .sib
        cmp           eax, MASK_EBP
        jne           .nomemsh
        jmp           .disp32

.nomemsh:
        mov           [ebx + Instructions.memSh], 0
        jmp           .EndProc

.sib:
        movzx         eax, word[ebx + edi]
        and           eax, MASK_MOD
        inc           esi
        movzx         ecx, byte[esi]
        mov           byte[ebx + Instructions.SIBbyte], cl
        inc           [numBt]

        cmp           eax, 0000_0000b
        jne           @F
        and           ecx, MASK_BASE
        cmp           ecx, MASK_EBP
        je            .disp32
        jmp           .nomemsh

@@:
        cmp           eax, 0100_0000b
        je            .disp8
        cmp           eax, 1000_0000b
        je            .disp32
        jmp           .EndProc

.mod01:
        cmp           eax, 0100_0000b
        jne           .mod10
        pop           eax
        and           eax, MASK_MOD or MASK_MEM
        and           word[ebx + edi],MASK_SIZE or MASK_OPTYPE
        or            [ebx + edi], ax
        cmp           [flag], MODE_16
        jne           .mod01_32
        jmp           .disp8

.mod01_32:
        and           eax, MASK_MEM
        cmp           eax, MASK_SIB
        jne           .disp8
        jmp           .sib

.mod10:
        cmp           eax, 1000_0000b
        jne           .mod11
        pop           eax
        and           eax, MASK_MOD or MASK_MEM
        and           word[ebx + edi],MASK_SIZE or MASK_OPTYPE
        or            [ebx + edi], ax
        cmp           [flag], MODE_16
        jne           .mod10_32
        jmp           .disp16

.mod10_32:
        and           eax, MASK_MEM
        cmp           eax, MASK_SIB
        jne           .disp32
        jmp           .sib

.mod11:
        pop           eax
        and           eax, MASK_MEM
        and           word[ebx + edi], MASK_SIZE
        or            word[ebx + edi], REGISTER
        and           word[ebx + edi], MASK_SIZE or MASK_OPTYPE
        or            [ebx + edi], ax
        jmp           .EndProc

.disp8:
        inc           esi
        movsx         ecx, byte[esi]
        mov           [ebx + Instructions.memSh], ecx
        inc           [numBt]
        jmp           .EndProc

.disp16:
        inc           esi
        movsx         ecx, word[esi]
        mov           [ebx + Instructions.memSh], ecx
        add           [numBt], 2
        jmp           .EndProc

.disp32:
        inc           esi
        mov           ecx,[esi]
        mov           [ebx + Instructions.memSh], ecx
        add           [numBt], 4

.EndProc:
        movzx         eax,byte[numBt]
        ret
endp


        include       'Units\Instructions.c'
        include         'Units\window.c'

section '.data' data readable writeable

        include         'Units\window.di'
        include         'Units\window.du'

fourb                        du      "$00000000",0
twob                         du      "$0000",0
oneb                         du      "$00", 0
scale                        du      "*0",0
bom                          dw      $FEFF
opbr                         du      "[",0
clbr                         du      "]",0
minus                        du      "-",0
plus                         du      "+",0
comma                        du      ", ",0
space                        du      " ",0
semicl                       du      "; ",0
colon                        du      ":",0
letter                       du      " ", 0
bstr                         du      "byte",0
wstr                         du      "word",0
dstr                         du      "dword",0
entstr                       dw      13, 10,0
T1                           dd      ADD_00,ADD_01,ADD_02,ADD_03,ADD_04,ADD_05,PUSH_SEG,POP_SEG,OR_08,OR_09,OR_0A,OR_0B,OR_0C,OR_0D,PUSH_SEG,POP_SEG,ADC_10,ADC_11,ADC_12,ADC_13,ADC_14,ADC_15,PUSH_SEG,POP_SEG,SBB_18,SBB_19,SBB_1A,\
                                     SBB_1B,SBB_1C,SBB_1D,PUSH_SEG,POP_SEG,AND_20,AND_21,AND_22,AND_23,AND_24,AND_25,0,0,SUB_28,SUB_29,SUB_2A,SUB_2B,SUB_2C,SUB_2D,0,0,XOR_30,XOR_31,XOR_32,XOR_33,XOR_34,XOR_35,0,0,CMP_38,CMP_39,\
                                     CMP_3A,CMP_3B,CMP_3C,CMP_3D,0,0,8 dup INC_REG,8 dup DEC_REG,8 dup PUSH_REG,8 dup POP_REG,6 dup 0,0,0, 8 dup 0,JO_70,JNO_71,JB_72,JAE_73,JZ_74,JNZ_75,JBE_76,JA_77,JS_78,JNS_79,\
                                     JP_7A,JNP_7B,JL_7C,JGE_7D,JLE_7E,JG_7F,GRP_80,GRP_81,0,GRP_83,TEST_84,TEST_85,XCHG_86,XCHG_87,MOV_88,MOV_89, MOV_8A, MOV_8B,MOV_8C,0,MOV_8E,0,\
                                     8 dup XCHG_AX,0,0,CALL_9A,5 dup 0,0,0,0,0,MOVSB_A4,MOVSW_A5,CMPSB_A6,CMPSW_A7,0,0,STOSB_AA,STOSW_AB,LODSB_AC,LODSW_AD,SCASB_AE,SCASW_AF,\
                                     16 dup MOV_REG_CONST,0,0,0,RET_C3,0,0,MOV_C6,MOV_C7,0,0,0,0,INT_CC,\
                                     INT_CD,0,0,GRP_D0,GRP_D1,GRP_D2,GRP_D3,12 dup 0,LOOPNZ_E0,LOOPZ_E1,LOOP_E2,JCXZ_E3,0,0,0,0,CALL_E8,JMP_E9,JMP_EA,JMP_EB,0,0,0,0,LOCK_F0,0,REPNE_F2,REPE_F3,0,0,GRP_F6,GRP_F7,0,0,0,0,0,0,GRP_FE,GRP_FF
T2                           du      "al",0,0,"cl",0,0,"dl",0,0,"bl",0,0,"ah",0,0,"ch",0,0,"dh",0,0,"bh",0,0
T3                           du      "ax",0,0,"cx",0,0,"dx",0,0,"bx",0,0,"sp",0,0,"bp",0,0,"si",0,0,"di",0,0
T4                           du      "db",6 dup 0,"add",5 dup 0,"or",6 dup 0,"adc",5 dup 0,"sbb",5 dup 0,"and",5 dup 0,"sub",5 dup 0,"xor",5 dup 0,"cmp",5 dup 0,"rol",5 dup 0,"ror",5 dup 0,"rcl",5 dup 0,"rcr",5 dup 0,\
                                     "shl",5 dup 0,"shr",5 dup 0,"xchg",4 dup 0,"sar",5 dup 0,"test",4 dup 0,"nop",5 dup 0,"not",5 dup 0,"neg",5 dup 0,"mul",5 dup 0,"imul",4 dup 0,"div",5 dup 0,"idiv",4 dup 0,"inc",\
                                     5 dup 0,"dec",5 dup 0,"call",4 dup 0,"ret",5 dup 0,"jmp",5 dup 0,"int",5 dup 0,"push",4 dup 0,"pop",5 dup 0,"mov",5 dup 0,"repe",4 dup 0,"repne",0,0,0,"movsb",0,0,0,"movsw",0,0,0,"cmpsb",0,0,0,\
                                     "cmpsw",0,0,0,"scasb",0,0,0,"scasw",0,0,0,"lodsb",0,0,0,"lodsw",0,0,0,"stosb",0,0,0,"stosw",0,0,0,"lock",4 dup 0,"jz",6 dup 0,"jl",6 dup 0,"jle",5 dup 0,"jb",6 dup 0,"jbe",5 dup 0,\
                                     "jp",6 dup 0,"jo",6 dup 0,"js",6 dup 0,"jnz",5 dup 0,"jge",5 dup 0,"jg",6 dup 0,"jae",5 dup 0,"ja",6 dup 0,"jnp",5 dup 0,"jno",5 dup 0,"jns",5 dup 0,"loop",4 dup 0,"loopz",0,0,0,"loopnz",0,0,\
                                     "jcxz",4 dup 0
T5                           du      "bx+si",0,"bx+di",0,"bp+si",0,"bp+di",0,"si",0,0,0,0,"di",0,0,0,0,"bp",0,0,0,0,"bx",0,0,0,0
T6                           du      "es",0,0,"cs",0,0,"ss",0,0,"ds",0,0
T7                           du      "eax",0,"ecx",0,"edx",0,"ebx",0,"esp",0,"ebp",0,"esi",0,"edi",0

flag                         dw      ?
Mas                          dd      ?
Inst                         Instructions

section '.idata' data import readable writeable

library kernel, 'kernel32.dll',\
        shell, 'shell32.dll',\
        user, 'user32.dll',\
        gdi, 'GDI32.DLL',\
        comdlg, 'comdlg32.dll'
  
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
            GetModuleHandle,'GetModuleHandleW',\
            ExitProcess, 'ExitProcess'

import shell,\
            CommandLineToArgvW, 'CommandLineToArgvW'

import user,\
            RegisterClass,'RegisterClassW',\
            CreateWindowEx,'CreateWindowExW',\
            DefWindowProc,'DefWindowProcW',\
            LoadCursor,'LoadCursorW',\
            LoadMenu,'LoadMenuW',\
            GetMessage,'GetMessageW',\
            DispatchMessage,'DispatchMessageW',\
            GetClientRect,'GetClientRect',\
            SendMessage,'SendMessageW',\
            MoveWindow,'MoveWindow',\
            SetFocus,'SetFocus',\
            TranslateMessage,'TranslateMessage',\
            GetWindowTextLength , 'GetWindowTextLengthW',\
            GetWindowText, 'GetWindowTextW',\
            CheckMenuRadioItem, 'CheckMenuRadioItem',\
            GetMenu, 'GetMenu',\
            PostQuitMessage,'PostQuitMessage'

import gdi,\
            CreateFont,'CreateFontW',\
            DeleteObject,'DeleteObject'

import comdlg,\
            GetOpenFileName, 'GetOpenFileNameW'

section '.rsrc' resource data readable
directory RT_MENU,menus

resource menus,\
           IDR_MENU,LANG_ENGLISH+SUBLANG_DEFAULT,main_menu

  menu main_menu
       menuitem '&File',0,MFR_POPUP
                menuitem '&Input',IDM_INPUT
                menuitem 'Output',IDM_OUTPUT,MFR_END
       menuitem '&Mode',0,MFR_POPUP
                menuitem '&16-bit',IDM_MODE_16,
                menuitem '&32-bit', IDM_MODE_32,MFR_END
       menuitem '&Exit',IDM_EXIT, MFR_END