/* tests/nc_int_types/unsigned/nc_u64/test_nc_u64.c */

/*
    About: Tests for the 'nc_u64' datatype.
    Initial Commit: NC_INT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#include "../../../../src/nc/nc_int_types.h"
#include <inttypes.h>
#include <stdio.h>

int main(void) {
    nc_u64 x = nc_new((uint64_t)100);
    nc_u64 y = nc_new((uint64_t)300);

    printf("NC_GET_VAL [x]: %" PRIu64 "\n", nc_get_val(x));
    printf("NC_GET_VAL [y]: %" PRIu64 "\n", nc_get_val(y));
    printf("NC_GET_SIZE [x]: %zu\n", nc_get_size(x));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %" PRIu64 "\n", nc_get_val(nc_checked_add(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, y]: %" PRIu64 "\n", nc_get_val(nc_checked_sub(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, y]: %" PRIu64 "\n", nc_get_val(nc_checked_mul(x, y)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, y]: %" PRIu64 "\n", nc_get_val(nc_checked_div(x, y, 0)));

    nc_u64 z = nc_new((uint64_t)NC_U64_MAX);

    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, z]: %" PRIu64 "\n", nc_get_val(nc_checked_add(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_SUB) [x, z]: %" PRIu64 "\n", nc_get_val(nc_checked_sub(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_MUL) [x, z]: %" PRIu64 "\n", nc_get_val(nc_checked_mul(x, z)));
    printf("NC_GET_VAL(NC_CHECKED_DIV) [x, z]: %" PRIu64 "\n", nc_get_val(nc_checked_div(x, z, 0)));

    return 0;
}