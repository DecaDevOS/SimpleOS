#include <ksys.h>

int main() {
    gdt_install();
    for(;;);    
}