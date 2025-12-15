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
XCHG_OPCODE            =       $0F
SAR_OPCODE             =       $10

TEST_OPCODE            =       $11
NOP_OPCODE             =       $12
NOT_OPCODE             =       $13
NEG_OPCODE             =       $14
MUL_OPCODE             =       $15
IMUL_OPCODE            =       $16
DIV_OPCODE             =       $17
IDIV_OPCODE            =       $18

INC_OPCODE             =       $19
DEC_OPCODE             =       $1A
CALL_OPCODE            =       $1B
RET_OPCODE             =       $1C
JMP_OPCODE             =       $1D
INT_OPCODE             =       $1E
PUSH_OPCODE            =       $1F

POP_OPCODE             =       $20
MOV_OPCODE             =       $21

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
LOOP_OPCODE            =       $3F
LOOPZ_OPCODE           =       $40
LOOPNZ_OPCODE          =       $41
JCXZ_OPCODE            =       $42