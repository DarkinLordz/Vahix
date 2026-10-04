#include "shell/shell.h"

void kernel_main(void)
{
	shell();

	while (1) {
		asm volatile("hlt");
	}
}
