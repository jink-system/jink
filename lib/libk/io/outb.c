#include <kernel/io.h>

void outb(io_uint16_t port, io_uint8_t value) {
    asm volatile("outb %0, %1" : : "a"(value), "Nd"(port));
}
