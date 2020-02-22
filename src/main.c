#include <ksys.h>

int main() {
    gdt_install();
    idt_install();
    for(;;);    
}