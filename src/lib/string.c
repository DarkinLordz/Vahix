#include "lib/string.h"

int strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}

	return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

size_t strlen(const char *s)
{
	size_t i = 0;
	while (s[i]) i++;
	return i;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2)) {
		s1++;
		s2++;
		n--;
	}

	if (n == 0) {
		return 0;
	}

	return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

char *strcpy(char *dest, const char *src)
{
	char *result = dest;

	while ((*dest++ = *src++) != '\0') {
	}

	return result;
}

uint32_t string_to_hex(char *str)
{
	uint32_t val = 0;
	uint8_t byte;

	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
		str += 2;
	}

	while (*str) {
		byte = *str;
		if (byte >= '0' && byte <= '9') {
			byte = byte - '0';
		} else if (byte >= 'a' && byte <= 'f') {
			byte = byte - 'a' + 10;
		} else if (byte >= 'A' && byte <= 'F') {
			byte = byte - 'A' + 10;
		}

		val = (val << 4) | (byte & 0xf);
		str++;
	}

	return val;
}

void itoa(int n, char *str)
{
	int i = 0;
	int rem;

	if (n == 0) {
		str[i++] = '0';
		str[i] = '\0';
		return;
	}

	while (n > 0) {
		rem = n % 10;
		str[i++] = rem + '0';
		n = n / 10;
	}

	str[i] = '\0';

	reverse(str, i);
}

void reverse(char *str, int length)
{
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int atoi(const char *nptr)
{
	int value = 0;
	int i;

	for (i = 0; nptr[i] != '\0'; i++) {
		if (nptr[i] >= '0' && nptr[i] <= '9') {
			value = (value * 10) + (nptr[i] - '0');
		} else {
			break;
		}
	}

	return value;
}

String string_new(void)
{
	String str;
	str.data = vec_new(sizeof(char));
	return str;
}

int string_push(String *str, char c)
{
	if (!vec_push(&str->data, &(char){c})) {
		return 1; // failed to push character
	}
	return 0; // success
}

int string_push_str(String *str, const char *s)
{
	for (size_t i = 0; s[i] != '\0'; i++) {
		if (!string_push(str, s[i])) {
			return 0; // failed to push character
		}
	}
	return 1; // success
}

char *string_c_str(String *str)
{
	char *c_str = alloc(&allocator, str->data.length + 1);
	if (c_str == NULL) {
		return NULL; // allocation failed
	}

	for (size_t i = 0; i < str->data.length; i++) {
		c_str[i] = *(char *)vec_at(&str->data, i);
	}

	c_str[str->data.length] = '\0';
	return c_str;
}

char string_at(String *str, size_t i)
{
	if (i >= str->data.length) {
		return '\0'; // index out of bounds
	}
	return *(char *)vec_at(&str->data, i);
}