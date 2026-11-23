#ifndef VAHIX_VECTOR_H
#define VAHIX_VECTOR_H

#include <stddef.h>
#include <stdint.h>
#include "lib/allocator.h"

typedef struct {
  void *data;
  size_t length;
  size_t capacity;
  size_t elem_size;
} Vec;

Vec vec_new(size_t elem_size);
int vec_grow(Vec *vec);
int vec_push(Vec *vec, void *value);
void *vec_pop(Vec *vec);
void *vec_at(Vec *vec, size_t index);
void vec_reset(Vec *vec);

#endif