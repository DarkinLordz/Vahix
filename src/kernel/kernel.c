#include <stddef.h>
#include <stdint.h>
#include <drivers/keyboard.h>
#include <kernel/shell.h>
#include <drivers/vga.h>

void kernel_main(void) {
    clear();
    shell();
    while (1) {
        __asm__ volatile ("hlt");
    }
}
