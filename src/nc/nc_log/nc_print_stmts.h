/* src/nc/nc_log/nc_print_stmts.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Print statements for various situations.
*/

#include <stdio.h>
#include <stdarg.h>

#ifndef NC_PRINT_STMTS_H
#define NC_PRINT_STMTS_H

#define NC_RESET "\e[0m"
#define NC_BLACK "\e[0;30m"
#define NC_RED "\e[0;31m"
#define NC_GREEN "\e[0;32m"
#define NC_YELLOW "\e[0;33m"
#define NC_BLUE "\e[0;34m"
#define NC_MAGENTA "\e[0;35m"
#define NC_CYAN "\e[0;36m"
#define NC_WHITE "\e[0;37m"

typedef enum {
    NC_COLOR_BLACK,
    NC_COLOR_RED,
    NC_COLOR_GREEN,
    NC_COLOR_YELLOW,
    NC_COLOR_BLUE,
    NC_COLOR_MAGENTA,
    NC_COLOR_CYAN,
    NC_COLOR_WHITE
} nc_colors;

static inline const char* nc_color_to_string(nc_colors color) {
    switch (color) {
        case NC_COLOR_BLACK:   return NC_BLACK;
        case NC_COLOR_RED:     return NC_RED;
        case NC_COLOR_GREEN:   return NC_GREEN;
        case NC_COLOR_YELLOW:  return NC_YELLOW;
        case NC_COLOR_BLUE:    return NC_BLUE;
        case NC_COLOR_MAGENTA: return NC_MAGENTA;
        case NC_COLOR_CYAN:    return NC_CYAN;
        case NC_COLOR_WHITE:   return NC_WHITE;
        default:               return NC_RESET;
    }
}

static inline void nc_println_color(const char* string, nc_colors color) {
    printf("%s%s\n" NC_RESET, nc_color_to_string(color), string);
}

static inline void nc_print_color(const char* string, nc_colors color) {
    printf("%s%s" NC_RESET, nc_color_to_string(color), string);
}

static inline int nc_println_err(const char* format, ...) {
    fprintf(stderr, NC_RED);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stderr, format, args);

    va_end(args);
    fprintf(stderr, "\n" NC_RESET);

    return printed_chars;
}

static inline int nc_print_err(const char* format, ...) {
    fprintf(stderr, NC_RED);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stderr, format, args);

    va_end(args);
    fprintf(stderr, NC_RESET);

    return printed_chars;
}

static inline int nc_println_warn(const char* format, ...) {
    fprintf(stderr, NC_YELLOW);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stderr, format, args);

    va_end(args);
    fprintf(stderr, "\n" NC_RESET);

    return printed_chars;
}

static inline int nc_print_warn(const char* format, ...) {
    fprintf(stderr, NC_YELLOW);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stderr, format, args);

    va_end(args);
    fprintf(stderr, NC_RESET);

    return printed_chars;
}

static inline int nc_println_succ(const char* format, ...) {
    fprintf(stdout, NC_GREEN);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stdout, format, args);

    va_end(args);
    fprintf(stdout, "\n" NC_RESET);

    return printed_chars;
}

static inline int nc_print_succ(const char* format, ...) {
    fprintf(stdout, NC_GREEN);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stdout, format, args);

    va_end(args);
    fprintf(stdout, NC_RESET);

    return printed_chars;
}

static inline int nc_println_info(const char* format, ...) {
    fprintf(stdout, NC_CYAN);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stdout, format, args);

    va_end(args);
    fprintf(stdout, "\n" NC_RESET);
    
    return printed_chars;
}

static inline int nc_print_info(const char* format, ...) {
    fprintf(stdout, NC_CYAN);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stdout, format, args);

    va_end(args);
    fprintf(stdout, NC_RESET);
    
    return printed_chars;
}

static inline int nc_println_debug(const char* format, ...) {
    fprintf(stdout, NC_MAGENTA);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stdout, format, args);

    va_end(args);
    fprintf(stdout, "\n" NC_RESET);

    return printed_chars;
}

static inline int nc_print_debug(const char* format, ...) {
    fprintf(stdout, NC_MAGENTA);

    va_list args;
    va_start(args, format);

    int printed_chars = vfprintf(stdout, format, args);

    va_end(args);
    fprintf(stdout, NC_RESET);

    return printed_chars;
}

#endif /* NC_PRINT_STMTS_H */