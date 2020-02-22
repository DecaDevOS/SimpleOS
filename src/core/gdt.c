/* Global Descriptor Table */
#include <ksys.h>

/* Global Descriptor Table Entry */
struct gdt_entry {
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed));

/* GDT Pointer */
struct gdt_ptr {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed))

struct gdt_entry gdt[3];
struct gdt_ptr   gp;

extern void gdt_flush();

/* gdt_set_gate: Set a GDT descriptor */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran) {
    /* Base Address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = (limit >> 16) & 0x0F;

    /* Granularity */
    gdt[num].granularity |= (gran & 0xF0);

    /* Access Flags */
    gdt[num].access = access;
}

