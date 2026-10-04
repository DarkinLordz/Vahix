/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (C) 2026 Vahid Khalafov */

#ifndef VAHIX_ALLOCATOR_H
#define VAHIX_ALLOCATOR_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint32_t heap_start;
    uint32_t heap_end;
    uint32_t next;
} BumpAllocator;

void bump_init(BumpAllocator *allocator, uint32_t heap_start, uint32_t heap_end);
uint8_t *alloc(BumpAllocator *allocator, size_t size);

#endif /* VAHIX_ALLOCATOR_H */