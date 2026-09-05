/* tests/nc_int_types/signed/nc_i64/test_nc_i64.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_i64'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i64 x = nc_new((int64_t)100);
    nc_i64 y = nc_new((int64_t)300);

    printf("NC_GET_VAL [x]: %ld\n", nc_get_val(x));
    printf("NC_GET_VAL [y]: %ld\n", nc_get_val(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size(x));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %ld\n", nc_get_val(nc_checked_add(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %ld\n", nc_get_val(nc_checked_sub(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %ld\n", nc_get_val(nc_checked_mul(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %ld\n", nc_get_val(nc_checked_div(x, y, 0)));

    nc_i64 z = nc_new((int64_t)NC_I64_MAX);
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, z]: %ld\n", nc_get_val(nc_checked_add(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, z]: %ld\n", nc_get_val(nc_checked_sub(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, z]: %ld\n", nc_get_val(nc_checked_mul(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, z]: %ld\n", nc_get_val(nc_checked_div(x, z, 0)));

    return 0;
}