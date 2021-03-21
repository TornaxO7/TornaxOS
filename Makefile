# General aliases
CC=gcc
AS=as --32
CFLAGS=-c -m32 -lgcc -ffreestanding -nostdlib -std=gnu99 -Wall -Wextra
L=ld -m elf_i386
OSNAME=TornaxOS

# Directories
BUILDD=build
SRCD=src

.PHONY: default clean

default:
	mkdir -p $(BUILDD)/iso/boot/grub
	cp $(SRCD)/boot/grub.cfg $(BUILDD)/iso/boot/grub/

	# assemble and compile the stuff
	$(AS) -o $(BUILDD)/boot.o $(SRCD)/boot/boot.s
	$(CC) $(CFLAGS) -o $(BUILDD)/kernel.o $(SRCD)/kernel.c
	$(L) -o $(BUILDD)/iso/boot/kernel.bin -T $(SRCD)/linker.ld \
		$(BUILDD)/boot.o $(BUILDD)/kernel.o

	$(shell ./test_mutliboot.sh $(SRCD)/iso/boot/kernel.bin)

	grub-mkrescue -o $(OSNAME).iso $(BUILDD)/iso/

clean:
	#$(CC) $(CFLAGS) -o $(BUILDD)/kernel.o $(SRCD)/kernel.c
	rm -rf build
