#ifndef VAHIX_STRING_H
#define VAHIX_STRING_H

#include <stddef.h>
#include <stdint.h>

#include "drivers/vga.h"
#include "lib/allocator.h"

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} String;

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strcpy(char *dest, const char *src);
size_t strlen(const char *s);
uint32_t string_to_hex(char *str);
void itoa(int n, char *str);
void reverse(char *str, int length);
int atoi(const char *nptr);
int grow_string(String *str);
int push(String *str, char c);
int push_str(String *str, const char *s);
String new_string(void);

#endif
