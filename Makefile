# General aliases
CC=i686-elf-gcc
AS=i686-elf-as
CFLAGS=-c -lgcc -ffreestanding -nostdlib -std=gnu99 -Wall -Wextra
L=i686-elf-ld
OSNAME=TornaxOS

# Directories
BUILDD=build
SRCD=src

.PHONY: default clean

default:
	mkdir -p $(BUILDD)/iso/boot/grub
	cp $(SRCD)/grub.cfg $(BUILDD)/iso/boot/grub/

	# assemble and compile the stuff
	$(AS) -o $(BUILDD)/boot.o $(SRCD)/boot/boot.s
	$(CC) -o $(BUILDD)/kernel.o $(SRCD)/kernel.c -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	$(CC) -T $(SRCD)/linker.ld -o $(BUILDD)/iso/boot/kernel.bin -ffreestanding -O2 -nostdlib \
			$(BUILDD)/boot.o $(BUILDD)/kernel.o

	grub-mkrescue -o $(OSNAME).iso $(BUILDD)/iso/

	# $(shell ./test_multiboot.sh TornaxOS.iso)
	objdump -D build/iso/kernel.bin > kernel_dumped.txt

clean:
	#$(CC) $(CFLAGS) -o $(BUILDD)/kernel.o $(SRCD)/kernel.c
	$(L) -o $(BUILDD)/iso/kernel.bin -T $(SRCD)/linker.ld \
		$(BUILDD)/boot.o $(BUILDD)/kernel.o
	rm -rf build
