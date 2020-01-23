#pragma once
/* Tables header */

/* (gdt_install): Install the kernels GDTs */
extern void gdt_install();

/* (gdt_set_gate): Set the GDT Descriptor */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);


