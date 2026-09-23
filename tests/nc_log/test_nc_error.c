/* tests/nc_log/test_nc_error.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Testing panics.
*/

#include "../../src/nc.h"

int main(void) {
    nc_panicln("This is a panic: %d", 42);
    /* nc_panic("This is a panic: %d", 42); <- same thing but without a newline, duh */
}