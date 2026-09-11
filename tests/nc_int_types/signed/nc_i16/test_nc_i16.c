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

    printf("NC_GET_VAL [x]: %d\n", nc_get_val_int(x));
    printf("NC_GET_VAL [y]: %d\n", nc_get_val_int(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size_int(x));
    printf("NC_GET_SIZE [y]: %ld\n", nc_get_size_int(y));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %d\n", nc_get_val_int(nc_checked_add_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %d\n", nc_get_val_int(nc_checked_sub_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %d\n", nc_get_val_int(nc_checked_mul_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %d\n", nc_get_val_int(nc_checked_div_int(x, y, 0)));
    printf("NC_GET_VAL(NC_SIGNUM_INT) [x]: %d\n", nc_get_val_int(nc_signum_int(x)));

    nc_assert(nc_get_val_int(nc_checked_mod_i16(x, y, 0)) == nc_get_val_int(nc_int_convert_to_i16(-150)), "Should be negative 150.");
    nc_debug_log("If you see this, this means the assertion was successful.");
}