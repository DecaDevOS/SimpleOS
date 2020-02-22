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


; Global Descriptor Table
global gdt_flush
extern gp

gdt_flush:
	lgdt [gp]
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:flush2
flush2:
	ret


; Interrupt Descriptor Table
global idt_load
extern idtp
idt_load:
	lidt [idtp]
	ret


; Interrupt Service Routines


; BSS Section


SECTION .bss
	resb 8192 ; 8K of memory reserved for the stack

_k_stack:
	; this is a pointer to the start of the kernel stack
