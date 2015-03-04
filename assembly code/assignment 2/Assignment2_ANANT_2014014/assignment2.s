MOV r2, #20
MOV r3, #0

ITERATE:
	CMP r3, r2
	BGE EXIT
	MOV r0, r3
	BL FIB
	MOV r1, r0
	MOV r0, #1
	swi 0x6B
	MOV r0, #'\n
	swi 0x00
	ADD r3, r3, #1
	B ITERATE

FIB:
	SUB sp, sp, #12
	STR r4, [sp, #4]
	STR r5, [sp, #8]
	STR lr, [sp, #0]
	MOV r4, r0
	CMP r0, #2
	BGE LOOP
	MOV r0, #1
	LDR r4, [sp, #4]
	LDR r5, [sp, #8]
	LDR lr, [sp, #0]
	ADD sp, sp, #12
	MOV pc, lr
	LOOP:
		SUB r0, r4, #1
		BL FIB
		MOV r5, r0
		SUB r0, r4, #2
		BL FIB
		ADD r0, r0, r5
		LDR r4, [sp, #4]
		LDR r5, [sp, #8]
		LDR lr, [sp, #0]
		ADD sp, sp, #12
		MOV pc, lr		

EXIT: