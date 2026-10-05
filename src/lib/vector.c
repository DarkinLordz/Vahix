#include "lib/vector.h"

void grow_vector(Vector *vec)
{
    size_t new_capacity = (vec->capacity == 0) ? 8 : vec->capacity * 2;
    vector_reserve(vec, new_capacity);
}

void push_vector(Vector *vec, Value val)
{
    if (vec->length == vec->capacity) {
        grow_vector(vec);
    }

    vec->data[vec->length] = val;
    vec->length++;
}

Vector new_vector(void)
{
    Vector vec;
    vec.data = NULL;
    vec.length = 0;
    vec.capacity = 0;
    return vec;
}

void vector_reserve(Vector *vec, size_t new_capacity)
{
    if (new_capacity <= vec->capacity) {
        return; // no need to reserve if the new capacity is less than or equal to current capacity
    }

    Value *new_data = (Value *)alloc(&allocator, new_capacity * sizeof(Value));

    if (new_data == NULL) {
        return; // best error handling method trust
    }

    if (vec->length > 0) {
        for (size_t i = 0; i < vec->length; i++) {
            new_data[i] = vec->data[i];
        }
    }

    vec->data = new_data;
    vec->capacity = new_capacity;
}

int vector_pop(Vector *vec, Value *out)
{
    if (vec->length == 0) {
        return 0; // vector is empty
    }

    *out = vec->data[--vec->length];
    return 1; // success
}

int vector_get(const Vector *vec, size_t index, Value *out)
{
    if (index >= vec->length) {
        return 0; // index out of bounds
    }

    *out = vec->data[index];
    return 1; // success
}