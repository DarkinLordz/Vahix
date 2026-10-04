/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (C) 2026 Vahid Khalafov */
/* Copyright (C) 2026 gitduck6 */

#include <lib/stdio.h>

void print_character(const char character)
{
    size_t cursor_pos = get_cursor_pos();

	if (cursor_pos >= VGA_WIDTH * VGA_HEIGHT) {
		scroll();
        cursor_pos = get_cursor_pos();
	}

	if (character == '\b') {
		if (cursor_pos > 0) {
			move_cursor(-1);
            cursor_pos = get_cursor_pos();
			write_cell(cursor_pos / VGA_WIDTH,
				   cursor_pos % VGA_WIDTH, ' ', get_color());
		}
	} else if (character == '\n') {
		new_line();
	} else {
		write_cell(cursor_pos / VGA_WIDTH, cursor_pos % VGA_WIDTH,
			   character, get_color());
		move_cursor(1);
	}
}

void print_string(const char *string)
{
	size_t i;

	for (i = 0; string[i] != '\0'; i++) {
		print_character(string[i]);
	}
}

void print_hex_byte(uint8_t value)
{
	const char *hex_chars = "0123456789ABCDEF";

	print_character(hex_chars[(value >> 4) & 0x0f]);
	print_character(hex_chars[value & 0x0f]);
}

void print_hex(uint32_t value)
{
	uint8_t byte;
	int i;

	print_string("0x");

	for (i = 3; i >= 0; i--) {
		byte = (value >> (i * 8)) & 0xff;
		print_hex_byte(byte);
	}
}

int printf(const char * format, ...)
{
    char special = 0;

    va_list va_data;
    va_start(va_data, format);

    for (int i = 0;format[i] != '\0';i++)
    {

        if ((!special) && (format[i] == '%'))
        {
            special = 1;
            continue;
        }

        if (special)
        {
            special = 0;

            switch (format[i])
            {
            case 'X':
            {
                char *hexboard = "0123456789ABCDEF";
                int num = va_arg(va_data, int);
                if (num == 0)
                {
                    print_character('0');
                    continue;
                }
                int bit_len = (sizeof(num) * 8) - 4;
                char non_zero_occured = 0;

                while (bit_len >= 0)
                {
                    char character = hexboard[ (num >> (bit_len)) & 0xf ];
                    if (character != '0') non_zero_occured = 1;

                    if (non_zero_occured)
                        print_character(character);
                    bit_len -= 4;
                }

                break;
            }
            case 'x':
            {
                char *hexboard = "0123456789abcdef";
                int num = va_arg(va_data, int);
                if (num == 0)
                {
                    print_character('0');
                    continue;
                }
                int bit_len = (sizeof(num) * 8) - 4;
                char non_zero_occured = 0;

                while (bit_len >= 0)
                {
                    char character = hexboard[ (num >> (bit_len)) & 0xf ];
                    if (character != '0') non_zero_occured = 1;

                    if (non_zero_occured)
                        print_character(character);
                    bit_len -= 4;
                }

                break;
            }
            case 'd':
            {
                int num = va_arg(va_data, int);

                char buffer[64];

                itoa(num, buffer); /* No negative numbers~ Baka! */

                print_string(buffer);

                break;
            }
            case 's':
                print_string(va_arg(va_data, char *));
                break;
            case 'c':
                print_character(va_arg(va_data, int));
                break;
            case '%':
                print_character('%');
                break;
            default:
                break;
            }
        }
        else 
        {
            print_character(format[i]);
        }

    }

    va_end(va_data);
    return 0;
}