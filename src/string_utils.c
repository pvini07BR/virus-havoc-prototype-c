#include "string_utils.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char* formatted_string(const char* fmt, ...) {
    if (fmt == NULL) return NULL;

    va_list args;
    va_start(args, fmt);
    size_t size = vsnprintf(NULL, 0, fmt, args) + 1; // +1 for null terminator
    va_end(args);

    char* buffer = (char*)malloc(size);
    if (buffer == NULL) {
        perror("Error allocating memory for formatted string.\n");
        return NULL;
    }

    va_start(args, fmt);
    vsnprintf(buffer, size, fmt, args);
    va_end(args);

    return buffer;
}