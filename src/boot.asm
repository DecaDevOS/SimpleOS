[BITS 32]
ALIGN 4

; Main entrypoint of the bootsector

global start

start:

	mov 	esp, _k_stack ; set the top of the stack
	push	ebx ; push the frame
	cli	; clear interrupts
	extern	main	; set the entry point for the c kernel
	call	main	; call the main entrypoint of the c kernel
	jmp	$	; infinite loop

; BSS Section

SECTION .bss
	resb 8192 ; 8K of memory reserved for the stack

_k_stack:
	; this is a pointer to the start of the kernel stack
