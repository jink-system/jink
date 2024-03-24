#include <kernel/io.h>

io_uint8_t inb(io_uint16_t port) {
    io_uint8_t ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}
