#include <drivers/vga.h>

static volatile uint16_t *const VGA_BUFFER = (uint16_t *)0xB8000;
static const uint8_t VGA_COLOR = 0x0F;
size_t cursor = 0;

void move_cursor(int direction) {
    cursor += direction;
}

void new_line(void) {
    move_cursor(80 - (cursor % 80));
}

void clear(void) {
    for (size_t i = 0; i < 80 * 25; i++) {
        VGA_BUFFER[i] = (uint16_t)' ' | ((uint16_t)VGA_COLOR << 8);
    }
    cursor = 0;
}

void print_character(const char character) {
    if (cursor >= 80 * 25) {
        clear(); // Clear to not cause triple fault
        cursor = 0;
    }
    if (character == '\b') {
        if (cursor > 0) {
            move_cursor(-1);
            VGA_BUFFER[cursor] = (uint16_t)' ' | ((uint16_t)VGA_COLOR << 8);
        }
    } else if (character == '\n') {
        new_line();
    } else {
        VGA_BUFFER[cursor] = (uint16_t)character | ((uint16_t)VGA_COLOR << 8);
        move_cursor(1);
    }
}

void print_string(const char *string) {
    for (size_t i = 0; string[i] != '\0'; ++i) {
        print_character(string[i]);
    }
}
