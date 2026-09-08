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

#if defined(__GNUC__) || defined(__clang__)
    #define NC_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
    #define NC_UNLIKELY(x) (x)
#endif

#if !defined(NDEBUG) && !defined(NC_RELEASE)
    #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
        #define nc_debug_log(fmt, ...) nc_println_debug("[DEBUG] " fmt __VA_OPT__(,) __VA_ARGS__)
    #else
        #define nc_debug_log(fmt, ...) nc_println_debug("[DEBUG] " fmt, ##__VA_ARGS__)
    #endif

    #define nc_assert(condition, msg) \
        do { \
            if (NC_UNLIKELY(!(condition))) { \
                nc_println_err("Assertion failed: %s (File: %s, Line: %ld)", msg, __FILE__, (long)__LINE__); \
                exit(1); \
            } \
        } while (0)
#else
    #define nc_debug_log(fmt, ...) ((void)0)
    #define nc_assert(condition, msg) ((void)0)
#endif

#endif /* NC_DEBUG_STMTS_H */