/* tests/nc_int_types/signed/nc_i32/test_nc_i32.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_i32'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i32 x = nc_new_i32(-120000);
    nc_i32 y = nc_new_i32(34567);

    printf("NC_GET_VAL [x]: %d\n", nc_get_val_int(x));
    printf("NC_GET_VAL [y]: %d\n", nc_get_val_int(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size_int(x));
    printf("NC_GET_SIZE [y]: %ld\n", nc_get_size_int(y));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %d\n", nc_get_val_int(nc_checked_add_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %d\n", nc_get_val_int(nc_checked_sub_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %d\n", nc_get_val_int(nc_checked_mul_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %d\n", nc_get_val_int(nc_checked_div_int(x, y, 0)));

    nc_assert(nc_get_val_int(nc_checked_mod_i32(x, y, 0)) == nc_get_val_int(nc_int_convert_to_i32(-16299)), "Should be negative 16299.");
    nc_debug_log("If you see this, this means the assertion was successful.");
}