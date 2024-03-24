#include <drivers/video/vga/vga.h>
#include <stdio.h>
#include <stdarg.h>

int vsprintf(char* buffer, const char* format, va_list args) {
    int count = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                int value = va_arg(args, int);
                int num_digits = 0;
                int temp = value;
                if (value < 0) {
                    temp = -temp;
                    buffer[count++] = '-';
                }
                do {
                    buffer[count++] = '0' + temp % 10;
                    temp /= 10;
                    num_digits++;
                } while (temp != 0);
                for (int i = 0; i < num_digits / 2; i++) {
                    char tmp = buffer[count - i - 1];
                    buffer[count - i - 1] = buffer[count - num_digits + i];
                    buffer[count - num_digits + i] = tmp;
                }
            } else if (*format == 's') {
                const char* str = va_arg(args, const char*);
                while (*str) {
                    buffer[count++] = *str++;
                }
            }
        } else {
            buffer[count++] = *format;
        }
        format++;
    }
    buffer[count] = '\0';
    return count;
}

void printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[256]; 
    vsprintf(buffer, format, args); 

    va_end(args);

    vga_puts(buffer);
}

