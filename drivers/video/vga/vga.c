#include <drivers/video/vga/vga.h>

// VGA Driver

static inline vgauint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
    return fg | bg << 4;
}
 
static inline vgauint16_t vga_entry(unsigned char uc, vgauint8_t color) 
{
    return (vgauint16_t) uc | (vgauint16_t) color << 8;
}
 
vgasize_t vga_strlen(const char* str) 
{
    vgasize_t len = 0;
    while (str[len])
        len++;
    return len;
}

static const vgasize_t VGA_WIDTH = 80;
static const vgasize_t VGA_HEIGHT = 25;

vgasize_t vga_term_row;
vgasize_t vga_term_column;
vgauint8_t vga_term_color;
vgauint16_t* vga_term_buffer;

void vga_init(void) {
    vga_term_row = 0;
    vga_term_column = 0;
    vga_term_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    vga_term_buffer = (vgauint16_t*) 0xB8000;
    for (vgasize_t y = 0; y < VGA_HEIGHT; y++) {
        for (vgasize_t x = 0; x < VGA_WIDTH; x++) {
            const vgasize_t index = y * VGA_WIDTH + x;
            vga_term_buffer[index] = vga_entry(' ', vga_term_color);
        }
    }
}

void vga_set_color(vgauint8_t color) {
    vga_term_color = color;
}

void vga_putentryat(char c, vgauint8_t color, vgasize_t x, vgasize_t y) {
    const vgasize_t index = y * VGA_WIDTH + x;
    vga_term_buffer[index] = vga_entry(c, color);
}

void vga_putc(char c) {
    vga_putentryat(c, vga_term_color, vga_term_column, vga_term_row);
    if (++vga_term_column == VGA_WIDTH) {
        vga_term_column = 0;
        if (++vga_term_row == VGA_HEIGHT) {
            vga_term_row = 0;
        }
    }
}

void vga_write(const char* data, vgasize_t size) {
    for (vgasize_t i = 0; i < size; i++) {
        if (data[i] == '\n') {
            vga_term_row++;
            vga_term_column = 0;
        } else {
            vga_putc(data[i]);
        }
    }
}

void vga_puts(const char* data) {
    vga_write(data, vga_strlen(data));
}
