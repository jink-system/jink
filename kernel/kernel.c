#include <drivers/video/vga/vga.h>
#include <drivers/audio/pcspeaker/pcspeaker.h>
#include <stdio.h>

int kernel_main() {
	vga_init();
	printf("Jink Operating System");
	return 0;
}
