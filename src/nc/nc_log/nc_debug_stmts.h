/* src/nc/nc_log/nc_debug_stmts.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Debug statements to detect bugs much quicker.
*/

#ifndef NC_DEBUG_STMTS_H
#define NC_DEBUG_STMTS_H

#include <stdlib.h>
#include <stdio.h>

#include "nc_print_stmts.h"
#include "../nc_int_types.h"

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

    /* Standard assert. */
    #define nc_assert(condition, msg) \
        do { \
            if (NC_UNLIKELY(!(condition))) { \
                nc_println_err("Assertion failed: %s (File: %s, Line: %ld)", msg, __FILE__, (long)__LINE__); \
                exit(1); \
            } \
        } while (0)

    /* Helper Macro. */
    #define NC_FMT_SPECIFIER(x) _Generic((x), \
        char: "%c", \
        nc_i8: "%d", \
        nc_u8: "%u", \
        nc_i16: "%d", \
        nc_u16: "%u", \
        nc_i32: "%d", \
        nc_u32: "%u", \
        nc_i64: "%lld", \
        nc_u64: "%llu", \
        float: "%f", \
        double: "%f", \
        char*: "%s", \
        const char*: "%s", \
        default: "%p" \
    )

    /* Assert: Checks if two values are equal. */
    #define nc_assert_eq(a, b) \
        do { \
            __typeof__(a) _a = (a); \
            __typeof__(b) _b = (b); \
            if (NC_UNLIKELY(_a != _b)) { \
                char tmpl_buf[512]; \
                char msg_buf[512]; \
                snprintf(tmpl_buf, sizeof(tmpl_buf), \
                    "Assertion failed: %s == %s (Left: %s, Right: %s) [File: %s, Line: %ld]", \
                    #a, #b, NC_FMT_SPECIFIER(_a), NC_FMT_SPECIFIER(_b), __FILE__, (long)__LINE__); \
                snprintf(msg_buf, sizeof(msg_buf), tmpl_buf, _a, _b); \
                nc_println_err("%s", msg_buf); \
                exit(1); \
            } \
        } while (0)

    /* Assert: Checks if two vales are NOT equal. */
    #define nc_assert_ne(a, b) \
        do { \
            __typeof__(a) _a = (a); \
            __typeof__(b) _b = (b); \
            if (NC_UNLIKELY(_a == _b)) { \
                char tmpl_buf[512]; \
                char msg_buf[512]; \
                snprintf(tmpl_buf, sizeof(tmpl_buf), \
                    "Assertion failed: %s != %s (Both values are: %s) [File: %s, Line: %ld]", \
                    #a, #b, NC_FMT_SPECIFIER(_a), __FILE__, (long)__LINE__); \
                snprintf(msg_buf, sizeof(msg_buf), tmpl_buf, _a); \
                nc_println_err("%s", msg_buf); \
                exit(1); \
            } \
        } while (0)

    /* Assert: Checks if 'n' value is lesser than 'm' value. */
    #define nc_assert_lt(a, b) \
        do { \
            __typeof__(a) _a = (a); \
            __typeof__(b) _b = (b); \
            if (NC_UNLIKELY(!(_a < _b))) { \
                char tmpl_buf[512]; \
                char msg_buf[512]; \
                snprintf(tmpl_buf, sizeof(tmpl_buf), \
                    "Assertion failed: %s < %s (Left: %s, Right: %s) [File: %s, Line: %ld]", \
                    #a, #b, NC_FMT_SPECIFIER(_a), NC_FMT_SPECIFIER(_b), __FILE__, (long)__LINE__); \
                snprintf(msg_buf, sizeof(msg_buf), tmpl_buf, _a, _b); \
                nc_println_err("%s", msg_buf); \
                exit(1); \
            } \
        } while (0)

    /* Assert: Checks if 'n' value is lesser than or equal 'm' value. */
    #define nc_assert_le(a, b) \
        do { \
            __typeof__(a) _a = (a); \
            __typeof__(b) _b = (b); \
            if (NC_UNLIKELY(!(_a <= _b))) { \
                char tmpl_buf[512]; \
                char msg_buf[512]; \
                snprintf(tmpl_buf, sizeof(tmpl_buf), \
                    "Assertion failed: %s <= %s (Left: %s, Right: %s) [File: %s, Line: %ld]", \
                    #a, #b, NC_FMT_SPECIFIER(_a), NC_FMT_SPECIFIER(_b), __FILE__, (long)__LINE__); \
                snprintf(msg_buf, sizeof(msg_buf), tmpl_buf, _a, _b); \
                nc_println_err("%s", msg_buf); \
                exit(1); \
            } \
        } while (0)

    /* Assert: Checks if 'n' value is greater than 'm' value. */
    #define nc_assert_gt(a, b) \
        do { \
            __typeof__(a) _a = (a); \
            __typeof__(b) _b = (b); \
            if (NC_UNLIKELY(!(_a > _b))) { \
                char tmpl_buf[512]; \
                char msg_buf[512]; \
                snprintf(tmpl_buf, sizeof(tmpl_buf), \
                    "Assertion failed: %s > %s (Left: %s, Right: %s) [File: %s, Line: %ld]", \
                    #a, #b, NC_FMT_SPECIFIER(_a), NC_FMT_SPECIFIER(_b), __FILE__, (long)__LINE__); \
                snprintf(msg_buf, sizeof(msg_buf), tmpl_buf, _a, _b); \
                nc_println_err("%s", msg_buf); \
                exit(1); \
            } \
        } while (0)

    /* Assert: Checks if 'n' value is greater than or equal 'm' value. */
    #define nc_assert_ge(a, b) \
        do { \
            __typeof__(a) _a = (a); \
            __typeof__(b) _b = (b); \
            if (NC_UNLIKELY(!(_a >= _b))) { \
                char tmpl_buf[512]; \
                char msg_buf[512]; \
                snprintf(tmpl_buf, sizeof(tmpl_buf), \
                    "Assertion failed: %s >= %s (Left: %s, Right: %s) [File: %s, Line: %ld]", \
                    #a, #b, NC_FMT_SPECIFIER(_a), NC_FMT_SPECIFIER(_b), __FILE__, (long)__LINE__); \
                snprintf(msg_buf, sizeof(msg_buf), tmpl_buf, _a, _b); \
                nc_println_err("%s", msg_buf); \
                exit(1); \
            } \
        } while (0)
#else /* !defined(NDEBUG) && !defined(NC_RELEASE)    release/NDEBUG builds: all macros are no-ops */
    #define nc_debug_log(fmt, ...) ((void)0)
    #define nc_assert(condition, msg) ((void)0)
    #define nc_assert_eq(a, b) ((void)0)
    #define nc_assert_ne(a, b) ((void)0)
    #define nc_assert_lt(a, b) ((void)0)
    #define nc_assert_le(a, b) ((void)0)
    #define nc_assert_gt(a, b) ((void)0)
    #define nc_assert_ge(a, b) ((void)0)
#endif /* !defined(NDEBUG) && !defined(NC_RELEASE) */

#endif /* NC_DEBUG_STMTS_H */