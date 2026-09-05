/* tests/nc_int_types/unsigned/nc_u32/test_nc_u32.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_u32'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_u32 x = nc_new_u32(100000U);
    nc_u32 y = nc_new_u32(25000U);

    printf("NC_GET_VAL [x]: %u\n", nc_get_val(x));
    printf("NC_GET_VAL [y]: %u\n", nc_get_val(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size(x));
    printf("NC_GET_SIZE [y]: %ld\n", nc_get_size(y));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %u\n", nc_get_val(nc_checked_add(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %u\n", nc_get_val(nc_checked_sub(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %u\n", nc_get_val(nc_checked_mul(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %u\n", nc_get_val(nc_checked_div(x, y, 0)));
}