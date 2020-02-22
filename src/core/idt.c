/* Interrupt Descriptor Table */
# include <ksys.h>

/* IDT Entry */
struct idt_entry {
    unsigned short base_low;
    unsigned short sel;
    unsigned char zero;
    unsigned char flags;
    unsigned short base_high;
} __attribute__((packed));

