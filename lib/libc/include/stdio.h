#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>

int vsprintf(char* buffer, const char* format, va_list args);
void printf(const char* format, ...);

#endif
