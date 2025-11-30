proc ADD_00 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 0
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc ADD_01 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 0
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc ADD_02 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 0
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc ADD_03 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 0
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc ADD_04 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 0
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc ADD_05 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 0
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc OR_08 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 1
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc OR_09 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 1
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc OR_0A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 1
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc OR_0B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 1
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc OR_0C stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 1
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc OR_0D stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 1
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc ADC_10 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 2
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc ADC_11 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 2
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc ADC_12 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 2
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc ADC_13 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 2
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc ADC_14 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 2
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc ADC_15 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 2
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc SBB_18 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 3
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc SBB_19 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 3
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc SBB_1A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 3
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc SBB_1B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 3
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc SBB_1C stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 3
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc SBB_1D stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 3
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc AND_20 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 4
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc AND_21 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 4
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc AND_22 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 4
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc AND_23 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 4
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc AND_24 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 4
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc AND_25 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 4
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc SUB_28 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 5
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc SUB_29 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 5
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc SUB_2A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 5
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc SUB_2B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 5
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc SUB_2C stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 5
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc SUB_2D stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 5
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc XOR_30 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 6
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc XOR_31 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 6
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc XOR_32 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 6
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc XOR_33 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 6
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc XOR_34 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 6
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc XOR_35 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 6
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc CMP_38 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 7
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc CMP_39 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 7
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc CMP_3A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 7
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc CMP_3B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 7
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc CMP_3C stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 7
        mov           [edx + Instructions.optype1], REG_AL
        mov           [edx + Instructions.optype2], SIZE_8 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc CMP_3D stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 7
        mov           [edx + Instructions.optype1], REG_AX
        mov           [edx + Instructions.optype2], SIZE_16 or CONST
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_CONST

        ret
endp

proc PUSH_SEG stru, bt
        mov           eax, [bt]
        and           eax, 0011_1000b
        shr           eax, 3
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 8
        mov           [edx + Instructions.optype1], SIZE_16 or SEGMENT_REG
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_END

        ret
endp


proc PUSH_REG stru, bt
        mov           eax, [bt]
        and           eax, 0000_0111b
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 8
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_END

        ret
endp

proc POP_SEG stru, bt
        mov           eax, [bt]
        and           eax, 0011_1000b
        shr           eax, 3
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 9
        mov           [edx + Instructions.optype1], SIZE_16 or SEGMENT_REG
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_END

        ret
endp

proc POP_REG stru, bt
        mov           eax, [bt]
        and           eax, 0000_0111b
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 9
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_END

        ret
endp

proc INC_REG stru, bt
        mov           eax, [bt]
        and           eax, 0000_0111b
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 10
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_END

        ret

endp

proc DEC_REG stru, bt
        mov           eax, [bt]
        and           eax, 0000_0111b
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 11
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        or            [edx + Instructions.optype1], al
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_END

        ret

endp

proc MOV_88 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 12
        mov           [edx + Instructions.optype1], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc MOV_89 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 12
        mov           [edx + Instructions.optype1], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype2], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc MOV_8A stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 12
        mov           [edx + Instructions.optype1], SIZE_8 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_8 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc MOV_8B stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 12
        mov           [edx + Instructions.optype1], SIZE_16 or REGISTER
        mov           [edx + Instructions.optype2], SIZE_16 or MEMORY
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_MODRM

        ret
endp

proc RET_C3 stru
        mov           edx, [stru]
        mov           [edx + Instructions.opcode], 13
        mov           [edx + Instructions.optype1], 0
        mov           [edx + Instructions.optype2], 0
        mov           [edx + Instructions.optype3], 0
        mov           eax, STATE_END

        ret
endp