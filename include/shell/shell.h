#ifndef VAHIX_SHELL_H
#define VAHIX_SHELL_H

#include <stdbool.h>
#include <stdint.h>

#include "drivers/keyboard.h"
#include "drivers/vga.h"
#include "kernel/io.h"
#include "lib/random.h"
#include "lib/string.h"
#include "lib/stdio.h"
#include "drivers/sound.h"

void shell(void);

#endif
