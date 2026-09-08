/* tests/nc_int_types/signed/nc_i8/test_nc_i8.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_i8'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i8 x = nc_new_i8(-12);
    nc_i8 y = nc_new_i8(7);
    nc_i8 zero = nc_new_i8(0);

    printf("NC_GET_VAL [x]: %d\n", nc_get_val_int(x));
    printf("NC_GET_VAL [y]: %d\n", nc_get_val_int(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size_int(x));
    printf("NC_GET_SIZE [y]: %ld\n", nc_get_size_int(y));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %d\n", nc_get_val_int(nc_checked_add_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %d\n", nc_get_val_int(nc_checked_sub_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %d\n", nc_get_val_int(nc_checked_mul_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV zero error check) [x, zero]: %d\n", nc_get_val_int(nc_checked_div_int(x, zero, 0)));
    printf("NC_GET_VAL(NC_CHECKED_DIV no zero error check) [x, zero]: %d\n", nc_get_val_int(nc_checked_div_int(x, zero, 1)));
    
    nc_assert(nc_get_val_int(nc_checked_mod_i8(x, y, 0)) == nc_get_val_int(nc_int_convert_to_i8(-5)), "Should be negative five.");
    nc_debug_log("If you see this, this means the assertion was successful.");
}