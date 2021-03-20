# General aliases
CC=gcc
AS=as
CFLAGS=-c -lgcc -ffreestanding -nostdlib -std=gnu99 -Wall -Wextra
L=ld
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

	grub-mkrescue -o $(OSNAME).iso $(BUILDD)/iso/

clean:
	$(CC) $(CFLAGS) -T $(SRCD)/linker.ld -o $(BUILDD)/iso/boot/kernel.bin \
			$(BUILDD)/boot.o $(BUILDD)/kernel.o
	#$(CC) $(CFLAGS) -o $(BUILDD)/kernel.o $(SRCD)/kernel.c
	rm -rf build
