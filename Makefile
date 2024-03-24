# Jink Kernel Makefile.

include .config

all:
	@make -s -f boot/Makefile
	@make -s -f drivers/Makefile
	@make -s -f drivers/Makefile libdriver
	@make -s -f kernel/Makefile

clean:
	@make -s -f boot/Makefile clean
	@make -s -f drivers/Makefile clean
	@make -s -f kernel/Makefile clean

buildiso:
	@sh .iso.sh

build-syslinux:
	@sh .img.sh

qemurun:
	qemu-system-i386 -cdrom jink.iso

qemurun-syslinux:
	qemu-system-i386 -drive file=boot.img,format=raw
