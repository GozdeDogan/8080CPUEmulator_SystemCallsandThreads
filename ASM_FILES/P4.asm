; 8080 assembler code
        .hexfile P4.hex
        .binfile P4.com
        ; try "hex" for downloading in hex format
        .download bin
        .objcopy gobjcopy
        .postbuild echo "OK!"
        ;.nodump

	; OS call list
PRINT_B		equ 1
PRINT_MEM	equ 2
READ_B		equ 3
READ_MEM	equ 4
PRINT_STR	equ 5
READ_STR	equ 6
GND_RND		equ 7
TExit		equ 8
TJoin 		equ 9
TYield 		equ 10
TCreate 	equ 11

	; Position for stack pointer
stack   equ 0F00H

	org 0000H
	jmp begin

	; Start of our Operating System
GTU_OS:	PUSH D
	push D
	push H
	push psw
	nop	; This is where we run our OS in C++, see the CPU8080::isSystemCall()
		; function for the detail.
	pop psw
	pop H
	pop D
	pop D
	ret
	; ---------------------------------------------------------------
	; YOU SHOULD NOT CHANGE ANYTHING ABOVE THIS LINE

	; my variables to use in searching

welcome: dw 'Welcome Program4', 00AH, 00H

thread_program1: dw 'F1.com', 00AH, 00H
thread_program2: dw 'F2.com', 00AH, 00H
thread_program3: dw 'F3.com', 00AH, 00H
thread_program4: dw 'F4.com', 00AH, 00H
thread_program5: dw 'F5.com', 00AH, 00H


begin:

	LXI B, welcome
	MVI A, PRINT_STR 					
	call GTU_OS 						; system call

	LXI B, thread_program4
	MVI A, TCreate 						; call TCreat
	call GTU_OS 						; system call
	MVI A, TExit
	call GTU_OS
	

	LXI B, thread_program5
	MVI A, TCreate 						; call TCreat
	call GTU_OS 						; system call
	MVI A, TExit
	call GTU_OS

END:
	hlt    								; end program