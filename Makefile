# Jink Kernel Makefile.

include .config

LDFLAGS=-ffreestanding -O2 -nostdlib

OBJ := boot/boot.o kernel/kernel.o

all:
	@make -s -f boot/Makefile
	@make -s -f lib/libk/Makefile install-lib
	@make -s -f lib/libk/Makefile
	@make -s -f lib/libk/Makefile make-lib
	@make -s -f drivers/Makefile
	@make -s -f drivers/Makefile libdriver
	@make -s -f lib/libc/Makefile install-lib
	@make -s -f lib/libc/Makefile
	@make -s -f lib/libc/Makefile make-lib
	@make -s -f kernel/Makefile
	@${JINK_CONFIG_COMPILER_CC} -T arch/${JINK_CONFIG_ARCH}/linker.ld -o jink.bin ${LDFLAGS} $(OBJ) -lgcc -Lsysroot/lib -ldriver -lc -lk
	@echo "LD	$(OBJ)	->	jink.bin (Kernel ELF32)"
	@cp ./jink.bin bootloader/grub/boot/


clean:
	@make -s -f boot/Makefile clean
	@make -s -f drivers/Makefile clean
	@make -s -f kernel/Makefile clean
	@make -s -f lib/libc/Makefile clean
	@make -s -f lib/libk/Makefile clean
	@rm jink.bin

qemurun:
	@qemu-system-i386 -audiodev pa,id=snd0 -machine pcspk-audiodev=snd0 -kernel jink.bin
