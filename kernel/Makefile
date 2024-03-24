include .config

CC=${JINK_CONFIG_COMPILER_CC}
SYSROOT_DIR=${JINK_CONFIG_SYSROOT_DIR}
CCFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra --sysroot=${SYSROOT_DIR} -I${SYSROOT_DIR}/include -ldriver -lc -lk
SRCDIR=./kernel/
OBJDIR=./kernel/
CSOURCES=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CSOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $< -o $@ $(CCFLAGS)
	@echo "CC	$<	->	$@"

all: $(OBJECTS)

clean:
	@rm -r $(OBJDIR)/*.o
	@echo "kernel/Makefile: directory clean!"
