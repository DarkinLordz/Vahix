CC      := i686-elf-gcc
LD      := i686-elf-gcc
AS      := i686-elf-gcc
CFLAGS  := -std=gnu99 -ffreestanding -O2 -Wall -Wextra -MMD -MP
ASFLAGS := -ffreestanding
LDFLAGS := -T linker.ld -ffreestanding -O2 -nostdlib

OBJDIR  := build
SRC_C   := $(wildcard src/*.c)
SRC_S   := $(wildcard src/*.s)
OBJS    := $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRC_C)) \
	$(patsubst src/%.s,$(OBJDIR)/%.o,$(SRC_S))
DEPS    := $(OBJS:.o=.d)
KERNEL  := kernel.bin
ISO     := Vahix.iso

.PHONY: all clean iso

all: $(KERNEL)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: src/%.s | $(OBJDIR)
	$(AS) $(ASFLAGS) -c $< -o $@

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL): $(OBJS) linker.ld
	$(LD) $(LDFLAGS) $(OBJS) -o $@

iso: $(KERNEL)
	cp $(KERNEL) iso/boot/kernel.bin
	grub-mkrescue -o $(ISO) iso

clean:
	rm -rf $(OBJDIR) $(KERNEL) $(ISO) iso/boot/kernel.bin

-include $(DEPS)
