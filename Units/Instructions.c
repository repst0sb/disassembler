proc UNKNOWN stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], UNKNOWN_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc GRP_80 stru, bt
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
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.PostProcess], 0
        mov           [edx + Instructions.hasModRM],1
        mov           [edx + Instructions.hasImm],1

.EndProc:
        ret
endp

proc ADD_00 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADD_01 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADD_02 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADD_03 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADD_04 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc ADD_05 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADD_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc OR_08 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc OR_09 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc OR_0A stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc OR_0B stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc OR_0C stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc OR_0D stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], OR_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc ADC_10 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADC_11 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADC_12 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADC_13 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc ADC_14 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc ADC_15 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], ADC_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc SBB_18 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SBB_19 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SBB_1A stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SBB_1B stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SBB_1C stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc SBB_1D stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SSB_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc AND_20 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc AND_21 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc AND_22 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc AND_23 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc AND_24 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc AND_25 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], AND_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc SUB_28 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SUB_29 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SUB_2A stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SUB_2B stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc SUB_2C stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc SUB_2D stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SUB_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc XOR_30 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XOR_31 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XOR_32 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XOR_33 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc XOR_34 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc XOR_35 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], XOR_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc CMP_38 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc CMP_39 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc CMP_3A stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc CMP_3B stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc CMP_3C stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc CMP_3D stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMP_OPCODE
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
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

proc XCHG_86 stru, bt
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

proc MOV_88 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc MOV_89 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc MOV_8A stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc MOV_8B stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        ret
endp

proc MOV_C6 stru, bt
        mov           edx, [stru]
        cmp           [edx + Instructions.PostProcess], 0
        jne           .PostProcess
        mov           [edx + Instructions.opcode], MOV_OPCODE
        mov           [edx + Instructions.optype1], REGISTER
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasModRM],1
        mov           [edx + Instructions.PostProcess], 1
        jmp           .EndProc

.PostProcess:
        movzx         eax, byte[edx + Instructions.optype1]
        and           eax, 0000_0111b
        test          eax, eax
        jnz           .Unknown
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.PostProcess], 0
        mov           [edx + Instructions.hasModRM],1
        mov           [edx + Instructions.hasImm],1
        jmp           .EndProc

.Unknown:
        stdcall       UNKNOWN, [stru], [bt]

.EndProc:
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
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc RET_C3 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], RET_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc INT_CD stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], INT_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],0
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc REPE_F3 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], REPE_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc REPNE_F2 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], REPNE_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc MOVSB_A4 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOVSB_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc MOVSW_A5 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], MOVSW_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc CMPSB_A6 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMPSB_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc CMPSW_A7 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], CMPSW_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc SCASB_AE stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SCASB_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc SCASW_AF stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], SCASW_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc LODSB_AC stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], LODSB_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc LODSW_AD stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], LODSW_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc STOSB_AA stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], STOSB_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc STOSW_AB stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], STOSW_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc LOCK_F0 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], LOCK_OPCODE
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        ret
endp

proc JMP_E9 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_16 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],3
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JMP_EB stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JMP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JZ_74 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JZ_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JL_7C stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JL_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JLE_7E stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JLE_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JB_72 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JB_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JBE_76 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JBE_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JP_7A stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JP_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JO_70 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JO_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JS_78 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JS_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp

proc JNZ_75 stru, bt
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], JNZ_OPCODE
        mov           [edx + Instructions.optype1], SIZE_8 or CONST
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           [edx + Instructions.const],2
        mov           [edx + Instructions.hasImm],1
        ret
endp