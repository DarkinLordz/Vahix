#ifndef VAHIX_ALLOCATOR_H
#define VAHIX_ALLOCATOR_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint32_t heap_start;
    uint32_t heap_end;
    uint32_t next;
} BumpAllocator;

extern BumpAllocator allocator;

void bump_init(BumpAllocator *allocator, uint32_t heap_start, uint32_t heap_end);
uint8_t *alloc(BumpAllocator *allocator, size_t size);

#endif
