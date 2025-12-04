struct Instructions
pref            dw       ?
opcode          dw       ?
optype1         db       ?
optype2         db       ?
optype3         db       ?
flags           db       ?
memSh           dd       ?
hasImm          db       ?
hasModRM        db       ?
PostProcess     db       ?
const           dd       ?
ends

UNKNOWN_OPCODE         =       $00

ADD_OPCODE             =       $01
OR_OPCODE              =       $02
ADC_OPCODE             =       $03
SSB_OPCODE             =       $04
AND_OPCODE             =       $05
SUB_OPCODE             =       $06
XOR_OPCODE             =       $07
CMP_OPCODE             =       $08

ROL_OPCODE             =       $09
ROR_OPCODE             =       $0A
RCL_OPCODE             =       $0B
RCR_OPCODE             =       $0C
SHL_OPCODE             =       $0D
SHR_OPCODE             =       $0E
SAR_OPCODE             =       $0F

TEST_OPCODE            =       $10
NOT_OPCODE             =       $11
NEG_OPCODE             =       $12
MUL_OPCODE             =       $13
IMUL_OPCODE            =       $14
DIV_OPCODE             =       $15
IDIV_OPCODE            =       $16

INC_OPCODE             =       $17
DEC_OPCODE             =       $18
CALL_OPCODE            =       $19
JMP_OPCODE             =       $1A
PUSH_OPCODE            =       $1B

POP_OPCODE             =       $1C
MOV_OPCODE             =       $1D
RET_OPCODE             =       $1E
INT_OPCODE             =       $1F

