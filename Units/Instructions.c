proc UNKNOWN stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], UNKNOWN_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc GRP_80 stru
        mov           edx, [stru]
        cmp           [edx + Instructions.PostProcess], 0
        jne           .PostProcess
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], REGISTER
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        mov           [edx + Instructions.PostProcess], 1
        jmp           .EndProc

.PostProcess:
        movzx         eax, byte[edx + Instructions.optype1]
        and           eax, 0000_0111b
        add           [edx + Instructions.opcode], ax
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.PostProcess], 0
        mov           [edx + Instructions.hasModRM],1
        mov           [edx + Instructions.hasImm],1

.EndProc:
        ret
endp

proc ADD_00 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADD_01 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADD_02 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADD_03 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADD_04 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc ADD_05 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc OR_08 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc OR_09 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc OR_0A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc OR_0B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc OR_0C stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc OR_0D stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc ADC_10 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADC_11 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADC_12 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADC_13 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADC_14 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc ADC_15 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc SBB_18 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SBB_19 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SBB_1A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SBB_1B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SBB_1C stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc SBB_1D stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc AND_20 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc AND_21 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc AND_22 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc AND_23 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc AND_24 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc AND_25 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc SUB_28 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SUB_29 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SUB_2A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SUB_2B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SUB_2C stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc SUB_2D stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc XOR_30 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XOR_31 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XOR_32 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XOR_33 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XOR_34 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc XOR_35 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc CMP_38 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc CMP_39 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc CMP_3A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc CMP_3B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc CMP_3C stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc CMP_3D stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc PUSH_SEG stru, bt
        mov           eax, [bt]
        and           eax, 0011_1000b
        shr           eax, 3
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], PUSH_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or SEGMENT_REG
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp


proc PUSH_REG stru, bt
        mov           eax, [bt]
        and           eax, 0000_0111b
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], PUSH_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc POP_SEG stru, bt
        mov           eax, [bt]
        and           eax, 0011_1000b
        shr           eax, 3
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], POP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or SEGMENT_REG
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc POP_REG stru, bt
        mov           eax, [bt]
        and           eax, 0000_0111b
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], POP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc INC_REG stru, bt
        mov           eax, [bt]
        and           eax, 0000_0111b
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], INC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret

endp

proc DEC_REG stru, bt
        mov           eax, [bt]
        and           eax, 0000_0111b
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], DEC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc XCHG_86 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XCHG_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XCHG_87 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XCHG_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XCHG_AX stru, bt
        mov           eax, [bt]
        mov           edx, [stru]
        and           eax, 0000_0111b
        test          eax, eax
        jz            .Nop
        mov           [edx + Instructions.opcode], XCHG_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], REGISTER or SIZE_16
        or            [edx + Instructions.optype2], al
        jmp           .EndProc

.Nop:
        mov           [edx + Instructions.opcode], NOP_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0

.EndProc:
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc MOV_88 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc MOV_89 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc MOV_8A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc MOV_8B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc MOV_REG_CONST stru, bt
        mov           eax, [bt]
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        and           eax, 0000_0111b
        mov           [edx + Instructions.optype1], REGISTER
        or            [edx + Instructions.optype1], al
        mov           eax, [bt]
        and           eax, 0000_1000b
        cmp           eax, 0000_0000b
        jne           @F
        or            [edx + Instructions.optype1], SIZE_8
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        jmp           .EndProc
@@:
        or            [edx + Instructions.optype1], SIZE_16
        mov           [edx + Instructions.optype2], SIZE_16 or CONST

.EndProc:
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc RET_C3 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], RET_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc INT_CD stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], INT_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp