#pragma once

#include <stdint.h>
#include <stddef.h>

#include "kernel/io.h"

void new_line(void);
void move_cursor(int direction);
void clear(void);
void print_character(const char character);
void print_string(const char *string);
void scroll(void);
void set_color(uint8_t fg, uint8_t bg);
uint8_t get_color(void);

#define VGA_WIDTH 80
#define VGA_HEIGHT 25