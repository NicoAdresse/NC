/* tests/nc_log/test_nc_debug.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Testing assertions and debugging.
*/

#include "../../src/nc/nc_log/nc_print_stmts.h"
#include "../../src/nc/nc_log/nc_debug_stmts.h"

int main(void) {
    nc_println_info("Starting debug statement tests...");

    nc_debug_log("This debug message should appear only if NDEBUG and NC_RELEASE are undefined.");

    int val_a = 42;
    int val_b = 42;
    int val_c = 100;

    nc_assert_eq(val_a, val_b);
    nc_assert_lt(val_a, val_c);
    nc_assert_le(val_a, val_b);
    nc_assert_gt(val_c, val_a);
    nc_assert_ge(val_c, val_b);

    nc_assert_ne(val_a, 42);
    /* Replace line 27 with nc_assert_eq(val_a, 42); if you want it to succeed. */

    /* Expected: Assertion failed: val_a == val_c (Left: 42, Right: 100) */
    /* nc_assert_eq(val_a, val_c); */

    /* Expected: Assertion failed: val_c < val_a (Left: 100, Right: 42) */
    /* nc_assert_lt(val_c, val_a); */

    nc_println_succ("All debug tests passed successfully!");
    return 0;
}
