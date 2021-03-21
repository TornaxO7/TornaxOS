# General aliases
#CC=gcc -m32 
#AS=as --32
#CFLAGS=-c -lgcc -ffreestanding -nostdlib -std=gnu99 -Wall -Wextra
#L=ld -m elf_i386

CC=i686-elf-gcc
AS=i686-elf-as
CFLAGS=-c -ffreestanding -nostdlib -std=gnu99 -Wall -Wextra
L=i686-elf-ld

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
	$(CC) $(CFLAGS) -T $(SRCD)/linker.ld -o $(BUILDD)/iso/boot/kernel.bin \
		$(BUILDD)/boot.o $(BUILDD)/kernel.o -lgcc

	#$(shell ./test_mutliboot.sh $(SRCD)/iso/boot/kernel.bin)

	grub-mkrescue -o $(OSNAME).iso $(BUILDD)/iso/

osdev:
	$(AS) -o $(BUILDD)/boot.o $(SRCD)/boot/boot.s
	$(CC) -c $(SRCD)/kernel.c -o $(BUILDD)/kernel.o -std=gnu99 -ffreestanding -O2 \
		-Wall -Wextra

	$(CC) -T $(SRCD)/linker.ld -o $(BUILDD)/iso/boot/kernel.bin -ffreestanding -O2 -nostdlib \
		$(BUILDD)/boot.o $(BUILDD)/kernel.o -lgcc

	grub-mkrescue -o $(OSNAME).iso $(BUILDD)/iso/

clean:
	#$(CC) $(CFLAGS) -o $(BUILDD)/kernel.o $(SRCD)/kernel.c
	#$(L) -o $(BUILDD)/iso/boot/kernel.bin -T $(SRCD)/linker.ld \
	#	$(BUILDD)/boot.o $(BUILDD)/kernel.o
	rm -rf build
	rm $(OSNAME).iso
