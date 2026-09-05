/* tests/nc_int_types/signed/nc_i16/test_nc_i16.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_i16'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i16 x = nc_new_i16(-1200);
    nc_i16 y = nc_new_i16(350);

    printf("NC_GET_VAL [x]: %d\n", nc_get_val(x));
    printf("NC_GET_VAL [y]: %d\n", nc_get_val(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size(x));
    printf("NC_GET_SIZE [y]: %ld\n", nc_get_size(y));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %d\n", nc_get_val(nc_checked_add(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %d\n", nc_get_val(nc_checked_sub(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %d\n", nc_get_val(nc_checked_mul(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %d\n", nc_get_val(nc_checked_div(x, y, 0)));
}