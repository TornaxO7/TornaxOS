# Build tools
CC=i686-elf-gcc
AS=i686-elf-as

# Directories
SRC=src
BUILDD=build
ISOD=$(BUILDD)/isodir
BOOTD=$(SRC)/boot

# Main stuff
OBJS=$(BUILDD)/boot.o $(BUILDD)/kernel.o

# CRTs
CRTI_OBJ_SRC=$(SRC)/calling_global_constructors/crti.s
CRTN_OBJ_SRC=$(SRC)/calling_global_constructors/crtn.s

CRTI_OBJ=$(BUILDD)/crti.o
CRTBEGIN_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)
CRTN_OBJ=$(BUILDD)/crtn.o

OBJ_LINK_LIST:=$(CRTI_OBJ) $(CRTBEGIN_OBJ) $(OBJS) $(CRTEND_OBJ) $(CRTN_OBJ)

# OS name
OSNAME=TornaxOS

# Actual process
.PHONY: default, clean

default: $(OBJ_LINK_LIST)
	# prepare the stuff before building
	mkdir -p $(ISOD)/boot/grub

	# compiling
	$(AS) $(BOOTD)/boot.s -o $(BUILDD)/boot.o
	$(AS) $(CRTI_OBJ_SRC) -o $(CRTI_OBJ)
	$(AS) $(CRTN_OBJ_SRC) -o $(CRTN_OBJ)
	#$(CC) -o $(BUILDD)/$(OSNAME).bin $(OBJ_LINK_LIST) -nostdlib -lgcc
	$(CC) -c $(SRC)/kernel.c -o $(BUILDD)/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

	# linking
	$(CC) -T $(SRC)/linker.ld -o $(BUILDD)/$(OSNAME).bin -ffreestanding -O2 -nostdlib \
		$(BUILDD)/boot.o $(BUILDD)/kernel.o -lgcc
	#$(CC) -o $(BUILDD)/$(OSNAME).bin $(OBJ_LINK_LIST) -nostdlib -lgcc

	# preparing for qemu
	cp $(SRC)/grub.cfg $(ISOD)/boot/grub/
	cp $(BUILDD)/$(OSNAME).bin $(ISOD)/boot/$(OSNAME).bin
	grub-mkrescue -o $(OSNAME).iso $(ISOD)

clean:
	rm -rf $(BUILDD)
	rm *.iso
