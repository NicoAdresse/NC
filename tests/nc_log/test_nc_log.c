/* tests/nc_log/test_nc_log.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Testing logging methods.
*/

#include "../../src/nc/nc_log.h"
#include "../../src/nc/nc_int_types.h"

int main(void) {
    nc_i8 x = nc_new((int8_t)NC_I8_MAX);

    println_warn("%d", nc_get_val(x));
    println_err("%d", nc_get_val(x));
    println_succ("%d", nc_get_val(x));
    println_info("%d", nc_get_val(x));
    println_color("Hello, World!", NC_COLOR_MAGENTA);
    println_color("This is so colorful!", NC_COLOR_BLUE);
}