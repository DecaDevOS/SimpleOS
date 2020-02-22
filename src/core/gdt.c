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
