 ; 8080 assembler code
        .hexfile F2.hex
        .binfile F2.com
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
GET_RND     equ 7

	; Position for stack pointer
stack   equ 0F000h

	org 000H
	jmp begin

	; Start of our Operating System
GTU_OS:	PUSH D
	push D
	push H
	push psw
	nop	; This is where we run our OS in C++, see the CPU8080::isSystemCall()
		; function for the detail.
	pop psw
	pop h
	pop d
	pop D
	ret
	; ---------------------------------------------------------------
	
; Ilk odevde yollanilan sum.asm ornek alindi
	
sum	ds 3 					; will keep the sum

begin:
	LXI SP,stack 			; always initialize the stack pointer
    MVI C, 1000				; init C with 1000
	MVI A, 0				; A = 0

CalculateSum:
	ADC C					; A = A + C + Carry
	DCR C					; --C
	JNZ CalculateSum		; goto loop if C!=0

	STA sum					; sum = A
	LDA sum					; A = sum

	MOV B, A				; B = A
	MVI A, PRINT_B			; store the OS call code to A
	call GTU_OS				; call the OS

	hlt						; end program

