/* tests/nc_string/test_string.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_string'.
*/

#include "../../src/nc.h"

int main(void) {
    nc_string* str = nc_string_create(100);

    nc_assert_ne(str, NULL);
    nc_assert_eq(nc_string_get_capacity(str), 100);
    nc_assert_eq(nc_string_get_length(str), 0);
    nc_debug_log("If you see this, then all assertions have been passing.");

    nc_string_set(str, "Hello, World!");
    nc_assert_eq(nc_string_compare(str, nc_string_from_cstr("Hello, World!")), 0);
    nc_println_info("Data: %s", nc_string_get_data(str));

    nc_string_destroy(str);
}