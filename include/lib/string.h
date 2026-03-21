#pragma once

#include <stdint.h>
#include <stddef.h>

#include "drivers/vga.h"

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strlen(const char *s);
uint32_t string_to_hex(char *str);
void print_hex_byte(uint8_t value);
void print_hex(uint32_t value);