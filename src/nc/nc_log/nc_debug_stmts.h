/* src/nc/nc_log/nc_debug_stmts.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Debug statements to detect bugs much quicker.
*/

#ifndef NC_DEBUG_STMTS_H
#define NC_DEBUG_STMTS_H

#include <stdlib.h>

#include "nc_print_stmts.h"

#if !defined(NDEBUG) && !defined(NC_RELEASE)
    #define nc_debug_log(fmt, ...) nc_println_debug("[DEBUG] " fmt, ##__VA_ARGS__)
    #define nc_assert(condition, msg) \
        do { \
            if (!(condition)) { \
                nc_println_err("Assertion failed: %s (File: %s, Line: %d)", msg, __FILE__, __LINE__); \
                abort(); \
            } \
        } while (0)
#else
    #define nc_debug_log(fmt, ...) ((void)0)
    #define nc_assert(condition, msg) ((void)0)
#endif

#endif /* NC_DEBUG_STMTS_H */