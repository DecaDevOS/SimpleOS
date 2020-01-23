#pragma once
/* kernel mem function header */

/* (memcpy): Copy from source to destination. Assumes that sorce and destination are not overlapping */
extern void *memcpy(void * restrict dest, const void * restrict src, size_t count);

