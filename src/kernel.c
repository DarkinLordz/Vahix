#include <stddef.h>
#include <stdint.h>
#include "keyboard.h"
#include "shell.h"
#include "vga.h"

void kernel_main(void) {
    clear();
    shell();
    while (1) {
        __asm__ volatile ("hlt");
    }
}
