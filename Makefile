# =============
# Settings 
# =============
.PHONY: default clean

# ============
# Aliases 
# ============ 
CC=gcc
CFLAGS=-m32	-ffreestanding -c -nostdlib -O2 -std=gnu99
CFLAGSS=-m32 -ffreestanding -c -nostdlib -Wall -Wextra -Werror -Wfatal-errors -Wuninitialized -pedantic -Wshadow -std=gnu99

AS=as
ASFLAGS=--32

LD=ld
LDFLAGS=-melf_i386

# ================
# Directories 
# ================
BUILDD=build
SRCD=src

# ====================
# Acutal compiling
# ====================
# Difference to "release": CC will have the secure flags and no optimisations.
default:
	# prepare the build directory
	mkdir -p build

	# prepare the boot file and the kernel
	# after that, link both together
	$(AS) $(ASFLAGS) -o $(BUILDD)/boot.o $(SRCD)/boot/boot.s
	$(CC) $(CFLAGSS) -o $(BUILDD)/kernel.o $(SRCD)/kernel.c
	$(LD) $(LDFLAGS) -o $(BUILDD)/kernel.bin -T $(SRCD)/linker.ld \
		$(BUILDD)/{boot,kernel}.o

release:
	# prepare the build directory
	mkdir -p build

	# prepare the boot file and the kernel
	# after that, link both together
	$(AS) $(ASFLAGS) -o $(BUILDD)/boot.o $(SRCD)/boot/boot.s
	$(CC) $(CFLAGS) -o $(BUILDD)/kernel.o $(SRCD)/kernel.c
	$(LD) $(LDFLAGS) -o $(BUILDD)/kernel.bin -T $(SRCD)/linker.ld \
		$(BUILDD)/{boot,kernel}.o

clean:
	rm -rf build
