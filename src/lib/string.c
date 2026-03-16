#include <lib/string.h>

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) {
        p++;
    }
    return (size_t)(p - s);
}

int strncmp(const char *s1, const char *s2, size_t n) {
    while (n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) return 0;
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

uint32_t string_to_hex(char *str) {
    uint32_t val = 0;
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) str += 2;
    
    while (*str) {
        uint8_t byte = *str;
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <= 'f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <= 'F') byte = byte - 'A' + 10;

        val = (val << 4) | (byte & 0xF);
        str++;
    }
    return val;
}

void print_hex_byte(uint8_t value) {
    char *hex_chars = "0123456789ABCDEF";
    print_character(hex_chars[(value >> 4) & 0x0F]);
    print_character(hex_chars[value & 0x0F]);
}

void print_hex(uint32_t value) {
    print_string("0x");
    for (int i = 3; i >= 0; i--) {
        uint8_t byte = (value >> (i * 8)) & 0xFF;
        print_hex_byte(byte);
    }
}