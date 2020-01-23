#pragma once
/* Tables header */

/* (gdt_install): Install the kernels GDTs */
extern void gdt_install();

/* (gdt_set_gate): Set the GDT Descriptor */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

/* (idt_install): Install the kernels IDTs */
extern void idt_install();

/* (idt_set_gate): Set the IDT Descriptor */
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flag);

/* Registers Structure */
struct registers {
	unsigned int gs;
	unsigned int fs;
	unsigned int es;
	unsigned int ds;

	unsigned int edi;
	unsigned int esi;
	unsigned int ebp;
	unsigned int esp;
	unsigned int ebx;
	unsigned int edx;
	unsigned int ecx;
	unsigned int eax;

	unsigned int int_no;
	unsigned int err_code;

	unsigned int eip;
	unsigned int cs;
	unsigned int eflags;
	unsigned int useresp;
	unsigned int ss;
};

/* Register typedef */
typedef void (*irq_handler_t)(struct registers *);


