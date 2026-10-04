#include "shell/shell.h"
#include "lib/allocator.h"

// 4mb heap size
#define HEAP_START 0x00400000
#define HEAP_END 0x00800000

void kernel_main(void)
{
	bump_init(&allocator, HEAP_START, HEAP_END);
	shell();

	while (1) {
		asm volatile("hlt");
	}
}
