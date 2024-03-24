#ifndef VGA_H
#define VGA_H

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

typedef unsigned long vgasize_t;

typedef unsigned char vgauint8_t;
typedef unsigned short int vgauint16_t;

void vga_init(void);
void vga_set_color(vgauint8_t color);
void vga_putentryat(char c, vgauint8_t color, vgasize_t x, vgasize_t y);
void vga_putc(char c);
void vga_write(const char* data, vgasize_t size);
void vga_puts(const char* data);
vgasize_t vga_strlen(const char* str);

#endif /* VGA_H */
