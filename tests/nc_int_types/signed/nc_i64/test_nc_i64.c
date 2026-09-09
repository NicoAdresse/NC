/* tests/nc_int_types/signed/nc_i64/test_nc_i64.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_i64'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i64 x = nc_new_int((int64_t)100);
    nc_i64 y = nc_new_int((int64_t)300);

    printf("NC_GET_VAL [x]: %ld\n", nc_get_val_int(x));
    printf("NC_GET_VAL [y]: %ld\n", nc_get_val_int(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size_int(x));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %ld\n", nc_get_val_int(nc_checked_add_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %ld\n", nc_get_val_int(nc_checked_sub_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %ld\n", nc_get_val_int(nc_checked_mul_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %ld\n", nc_get_val_int(nc_checked_div_int(x, y, 0)));

    nc_i64 z = nc_new_int((int64_t)NC_I64_MAX);
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, z]: %ld\n", nc_get_val_int(nc_checked_add_int(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, z]: %ld\n", nc_get_val_int(nc_checked_sub_int(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, z]: %ld\n", nc_get_val_int(nc_checked_mul_int(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, z]: %ld\n", nc_get_val_int(nc_checked_div_int(x, z, 0)));

    nc_assert(nc_get_val_int(nc_checked_mod_i64(x, y, 0)) == nc_get_val_int(nc_int_convert_to_i64(100)), "Should be 100.");
    nc_debug_log("If you see this, this means the assertion was successful.");

    return 0;
}