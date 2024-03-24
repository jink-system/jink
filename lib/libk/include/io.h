#ifndef IO_H
#define IO_H

typedef unsigned char io_uint8_t;
typedef unsigned short int io_uint16_t;

void outb(io_uint16_t port, io_uint8_t value);
io_uint8_t inb(io_uint16_t port);

#endif
