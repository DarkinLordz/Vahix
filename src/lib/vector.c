#include "lib/vector.h"

int grow_vector(Vector *vec)
{
    size_t new_capacity = (vec->capacity == 0) ? 8 : vec->capacity * 2;
    return vector_reserve(vec, new_capacity);
}

int push_vector(Vector *vec, Value val)
{
    if (vec->length == vec->capacity) {
        if (!grow_vector(vec)) {
            return 0; // failed to grow vector
        }
    }

    vec->data[vec->length] = val;
    vec->length++;
    return 1; // success
}

Vector new_vector(void)
{
    Vector vec;
    vec.data = NULL;
    vec.length = 0;
    vec.capacity = 0;
    return vec;
}

int vector_reserve(Vector *vec, size_t new_capacity)
{
    if (new_capacity <= vec->capacity) {
        return 1; // no need to reserve if the new capacity is less than or equal to current capacity
    }

    Value *new_data = (Value *)alloc(&allocator, new_capacity * sizeof(Value));

    if (new_data == NULL) {
        return 0;
    }

    if (vec->length > 0) {
        for (size_t i = 0; i < vec->length; i++) {
            new_data[i] = vec->data[i];
        }
    }

    vec->data = new_data;
    vec->capacity = new_capacity;
    return 1; // success
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

void vector_clear(Vector *vec)
{
    vec->length = 0;
}