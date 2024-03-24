include .config

CC=${JINK_CONFIG_COMPILER_CC}
SYSROOT_DIR=${JINK_CONFIG_SYSROOT_DIR}
INCLUDE_DIR=${SYSROOT_DIR}/include
CFLAGS=-ffreestanding -O2 -Wall -Wextra --sysroot=${SYSROOT_DIR} -I${INCLUDE_DIR}
SRCDIR=./drivers/video/vga/
OBJDIR=./drivers/video/vga/
CSOURCES=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CSOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $< -o $@ $(CFLAGS)
	echo "CC	$<	->	$@"

build: $(OBJECTS)

install-driver:
	@cp $(SRCDIR)/*.h $(INCLUDE_DIR)/drivers/video/vga/
	echo "CP	$(SRCDIR) (header) -> $(INCLUDE_DIR)"

cleans:
	rm ./drivers/video/vga/vga.o
	rm ./sysroot/include/drivers/video/vga/vga.h
	echo "drivers/video/vga/Makefile: directory clean!"
