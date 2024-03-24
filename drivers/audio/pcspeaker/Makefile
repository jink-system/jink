include .config

CC=${JINK_CONFIG_COMPILER_CC}
SYSROOT_DIR=${JINK_CONFIG_SYSROOT_DIR}
INCLUDE_DIR=${SYSROOT_DIR}/include
CFLAGS=-ffreestanding -O2 -Wall -Wextra --sysroot=${SYSROOT_DIR} -I${INCLUDE_DIR} -Lsysroot/lib -lk
SRCDIR=./drivers/audio/pcspeaker/
OBJDIR=./drivers/audio/pcspeaker/
CSOURCES=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CSOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $< -o $@ $(CFLAGS)
	echo "CC	$<	->	$@"

build: $(OBJECTS)

install-driver:
	@cp $(SRCDIR)/*.h $(INCLUDE_DIR)/drivers/audio/pcspeaker/
	echo "CP	$(SRCDIR) (header) -> $(INCLUDE_DIR)"

cleans:
	rm ./drivers/audio/pcspeaker/pcspeaker.o
	rm ./sysroot/include/drivers/audio/pcspeaker/pcspeaker.h
	echo "drivers/audio/pcspeaker/Makefile: directory clean!"
