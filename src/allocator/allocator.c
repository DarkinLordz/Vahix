/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (C) 2026 Vahid Khalafov */

#include "allocator/allocator.h"

typedef struct {
    uint32_t heap_start;
    uint32_t heap_end;
    uint32_t next;
} BumpAllocator;