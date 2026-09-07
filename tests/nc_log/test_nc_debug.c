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

    nc_debug_log("This debug message should appear only if NC_DEBUG is defined.");

    int test_val = 42;
    nc_assert(test_val == 42, "Value should match expected state.");

    nc_println_succ("All debug tests passed successfully!");
    return 0;
}