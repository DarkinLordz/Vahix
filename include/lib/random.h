#ifndef VAHIX_RANDOM_H
#define VAHIX_RANDOM_H

#include <stdint.h>

uint32_t random(void);
uint32_t get_hwrng_seed(void);
uint32_t get_seed_from_rdtsc(void);

#endif
