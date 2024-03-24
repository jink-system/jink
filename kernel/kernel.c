#include <drivers/video/vga/vga.h>

int kernel_main() {
	vga_init();
	vga_puts("Hello");
	return 0;
}
