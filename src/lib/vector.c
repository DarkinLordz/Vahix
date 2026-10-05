#include "lib/vector.h"

void grow_vector(Vector *vec)
{
    size_t new_capacity = (vec->capacity == 0) ? 8 : vec->capacity * 2;
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