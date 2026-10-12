#include "lib/allocator.h"

BumpAllocator allocator;

void bump_init(BumpAllocator *allocator, uint32_t heap_start, uint32_t heap_end)
{
    allocator->heap_start = heap_start;
    allocator->heap_end = heap_end;
    allocator->next = heap_start;
}

void *alloc(BumpAllocator *allocator, size_t size)
{
    uint32_t alloc_start = allocator->next;

    if (size  > UINT32_MAX - alloc_start) {
        return NULL; // overflow
    }

    uint32_t alloc_end = alloc_start + (uint32_t)size;

    if (alloc_end > allocator->heap_end) {
        return NULL; // out of memory
    }
    
    allocator->next += size;
    return (void *)alloc_start;
}
