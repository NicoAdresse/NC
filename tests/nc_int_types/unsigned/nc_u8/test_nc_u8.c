/* tests/nc_int_types/unsigned/nc_u8/test_nc_u8.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_u8'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_u8 x = nc_new_u8(100U);
    nc_u8 y = nc_new_u8(25U);

    printf("NC_GET_VAL [x]: %u\n", nc_get_val_int(x));
    printf("NC_GET_VAL [y]: %u\n", nc_get_val_int(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size_int(x));
    printf("NC_GET_SIZE [y]: %ld\n", nc_get_size_int(y));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %u\n", nc_get_val_int(nc_checked_add_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %u\n", nc_get_val_int(nc_checked_sub_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %u\n", nc_get_val_int(nc_checked_mul_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %u\n", nc_get_val_int(nc_checked_div_int(x, y, 0)));
    printf("NC_GET_VAL(NC_SIGNUM_INT) [x]: %d\n", nc_get_val_int(nc_signum_int(x)));

    nc_assert(nc_get_val_int(nc_checked_mod_u8(x, y, 0)) == nc_get_val_int(nc_int_convert_to_u8(0)), "Should be 0.");
    nc_debug_log("If you see this, this means the assertion was successful.");
}