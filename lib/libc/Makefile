include .config

CC=${JINK_CONFIG_COMPILER_CC}
AR=${JINK_CONFIG_COMPILER_AR}
SYSROOT_DIR=${JINK_CONFIG_SYSROOT_DIR}
INCLUDE_DIR=${SYSROOT_DIR}/include
CFLAGS=-ffreestanding -O2 -Wall -Wextra --sysroot=${SYSROOT_DIR} -I${INCLUDE_DIR} -Lsysroot/lib -ldriver

SRC_DIR := ./lib/libc/stdio ./lib/libc/string
SRCS := $(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.c))
OBJS := $(SRCS:.c=.o)

HEADER_DIR=lib/libc/include

ALLH=$(shell cat lib/libc/header_list.txt)

all: $(OBJS)

%.o: %.c
	@${CC} -c $< -o $@ $(CFLAGS)
	@echo "CC	$<	->	$@"

install-lib:
	@cp ${HEADER_DIR}/*.h ${INCLUDE_DIR}
	@echo "CP	${HEADER_DIR} (header) -> ${INCLUDE_DIR}"

make-lib:
	${AR} rcs ${SYSROOT_DIR}/lib/libc.a ${OBJS} --target=elf32-i386
	@echo "LD	${OBJS}	-> libc.a"

clean:
	@for file in $(ALLH); do \
		rm ${INCLUDE_DIR}/$$file; \
	done
	rm ${OBJS}
	rm ${SYSROOT_DIR}/lib/libc.a
	echo "lib/libc/Makefile: libc.a is deleted!"
