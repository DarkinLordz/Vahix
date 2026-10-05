#ifndef VAHIX_VECTOR_H
#define VAHIX_VECTOR_H

#include <stddef.h>
#include <stdint.h>
#include "lib/allocator.h"

typedef enum {
    VALUE_INT,
    VALUE_FLOAT,
    VALUE_CHAR,
    VALUE_STRING,
} ValueType;

typedef struct {
    ValueType type;
    union {
        int integer;
        float floating;
        char character;
        const char *string;
    } as;
} Value;

typedef struct {
    Value *data;
    size_t length;
    size_t capacity;
} Vector;

int grow_vector(Vector *vec);
int push_vector(Vector *vec, Value val);
Vector new_vector(void);
int vector_reserve(Vector *vec, size_t new_capacity);
int vector_pop(Vector *vec, Value *out);
int vector_get(const Vector *vec, size_t index, Value *out);
void vector_clear(Vector *vec);

#endif