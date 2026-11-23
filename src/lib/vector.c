#include "lib/vector.h"

Vec vec_new(size_t elem_size)
{
  Vec vec;
  vec.data = NULL;
  vec.length = 0;
  vec.capacity = 0;
  vec.elem_size = elem_size;
  return vec;
}

int vec_grow(Vec *vec)
{
  size_t new_capacity = (vec->capacity == 0) ? 8 : vec->capacity * 2;
  void *new_data = alloc(&allocator, new_capacity * vec->elem_size);

  if (new_data == NULL) {
    return 1;
  }

  uint8_t *dst = new_data;
  uint8_t *src = vec->data;
  
  if (vec->length > 0) {
    for (size_t i = 0; i < vec->length * vec->elem_size; i++) {
      dst[i] = src[i];
    }
  }

  vec->data = new_data;
  vec->capacity = new_capacity;

  return 0;
}

int vec_push(Vec *vec, void *value)
{
  if (vec->length >= vec->capacity) {
    if (vec_grow(vec)) {
      return 1;
    }
  }

  uint8_t *dst = (uint8_t *)vec->data + vec->length * vec->elem_size;
  uint8_t *src = value;

  for (size_t i = 0; i < vec->elem_size; i++) {
    dst[i] = src[i];
  }
  
  vec->length++;

  return 0;
}

void *vec_pop(Vec *vec)
{
  if (vec->data == NULL || vec->length == 0) {
    return NULL;
  }

  vec->length--;
  return (uint8_t *)vec->data + vec->length * vec->elem_size;
}

void *vec_at(Vec *vec, size_t index)
{
  if (vec->data == NULL || index >= vec->length) {
    return NULL;
  }

  return (uint8_t *)vec->data + index * vec->elem_size;
}

void vec_reset(Vec *vec)
{
  vec->length = 0;
}