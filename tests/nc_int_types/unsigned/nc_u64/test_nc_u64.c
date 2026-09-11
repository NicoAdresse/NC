/* tests/nc_int_types/unsigned/nc_u64/test_nc_u64.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_u64'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <inttypes.h>
#include <stdio.h>

int main(void) {
    nc_u64 x = nc_new_int((uint64_t)100);
    nc_u64 y = nc_new_int((uint64_t)300);

    printf("NC_GET_VAL [x]: %" PRIu64 "\n", nc_get_val_int(x));
    printf("NC_GET_VAL [y]: %" PRIu64 "\n", nc_get_val_int(y));
    printf("NC_GET_SIZE [x]: %zu\n", nc_get_size_int(x));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %" PRIu64 "\n", nc_get_val_int(nc_checked_add_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %" PRIu64 "\n", nc_get_val_int(nc_checked_sub_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %" PRIu64 "\n", nc_get_val_int(nc_checked_mul_int(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %" PRIu64 "\n", nc_get_val_int(nc_checked_div_int(x, y, 0)));

    nc_u64 z = nc_new_int((uint64_t)NC_U64_MAX);

    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, z]: %" PRIu64 "\n", nc_get_val_int(nc_checked_add_int(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, z]: %" PRIu64 "\n", nc_get_val_int(nc_checked_sub_int(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, z]: %" PRIu64 "\n", nc_get_val_int(nc_checked_mul_int(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, z]: %" PRIu64 "\n", nc_get_val_int(nc_checked_div_int(x, z, 0)));
    printf("NC_GET_VAL(NC_SIGNUM_INT) [x]: %" PRIu64 "\n", nc_get_val_int(nc_signum_int(x)));

    nc_assert(nc_get_val_int(nc_checked_mod_u64(x, y, 0)) == nc_get_val_int(nc_int_convert_to_u64(100)), "Should be 100.");
    nc_debug_log("If you see this, this means the assertion was successful.");

    return 0;
}