#include "lib/allocator.h"

void bump_init(BumpAllocator *allocator, uint32_t heap_start, uint32_t heap_end)
{
    allocator->heap_start = heap_start;
    allocator->heap_end = heap_end;
    allocator->next = heap_start;
}

uint8_t *alloc(BumpAllocator *allocator, size_t size)
{
    uint32_t alloc_start = allocator->next;
    allocator->next += size;
    return (uint8_t *)alloc_start;
}
