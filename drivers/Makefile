include .config

AR=${JINK_CONFIG_COMPILER_AR}

drivers_makefiles := drivers/video/vga/Makefile

drivers_objects := drivers/video/vga/vga.o


all: $(drivers_makefiles)
	@for makefile in $^; do \
		$(MAKE) -f $$makefile install-driver; \
		$(MAKE) -f $$makefile build; \
	done

clean: $(drivers_makefiles)
	@for makefile in $^; do \
		$(MAKE) -f $$makefile cleans; \
	done
	rm ${JINK_CONFIG_SYSROOT_DIR}/lib/libdriver.a
	echo "drivers/Makefile: libdriver.a deleted!"

libdriver:
	${AR} rcs libdriver.a $(drivers_objects) --target=elf32-i386
	echo "LD	libdriver.a -> SYSROOT/lib"
	mv libdriver.a ${JINK_CONFIG_SYSROOT_DIR}/lib/
