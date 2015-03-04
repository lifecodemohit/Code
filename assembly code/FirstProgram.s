MOV R2,#1
MOV R3,#10
while:
mov r1,r2
mov r0,#1
SWI 0x6B
mov r0,#'\n
SWI 0x0
CMP R2,R3
BEQ EXIT
ADD R2,R2,#1
B while
EXIT: