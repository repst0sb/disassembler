struct Instructions
pref            dw       ?
opcode          dw       ?
optype1         dw       ?
optype2         dw       ?
optype3         dw       ?
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

XCHG_OPCODE            =       $1C
NOP_OPCODE             =       $1D

POP_OPCODE             =       $1E
MOV_OPCODE             =       $1F
RET_OPCODE             =       $20
INT_OPCODE             =       $21

REPE_OPCODE            =       $22
REPNE_OPCODE           =       $23

MOVSB_OPCODE           =       $24
MOVSW_OPCODE           =       $25
CMPSB_OPCODE           =       $26
CMPSW_OPCODE           =       $27
SCASB_OPCODE           =       $28
SCASW_OPCODE           =       $29
LODSB_OPCODE           =       $2A
LODSW_OPCODE           =       $2B
STOSB_OPCODE           =       $2C
STOSW_OPCODE           =       $2D
LOCK_OPCODE            =       $2E

JZ_OPCODE              =       $2F
JL_OPCODE              =       $30
JLE_OPCODE             =       $31
JB_OPCODE              =       $32
JBE_OPCODE             =       $33
JP_OPCODE              =       $34
JO_OPCODE              =       $35
JS_OPCODE              =       $36
JNZ_OPCODE             =       $37
JGE_OPCODE             =       $38
JG_OPCODE              =       $39
JAE_OPCODE             =       $3A
JA_OPCODE              =       $3B
JNP_OPCODE             =       $3C
JNO_OPCODE             =       $3D
JNS_OPCODE             =       $3E
