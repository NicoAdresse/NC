/* src/nc/nc_log/nc_error_stmts.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Public error statements.
*/

#ifndef NC_ERROR_STMTS_H
#define NC_ERROR_STMTS_H

#include "nc_print_stmts.h"

#include <stdarg.h>
#include <stdlib.h>

static inline void nc_panic(const char* format, ...) {
    fprintf(stderr, NC_RED);

    va_list args;
    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);
    fprintf(stderr, NC_RESET);

    abort();
}

static inline void nc_panicln(const char* format, ...) {
    fprintf(stderr, NC_RED);

    va_list args;
    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);
    fprintf(stderr, "\n" NC_RESET);

    abort();
}

#endif /* NC_ERROR_STMTS_H */

