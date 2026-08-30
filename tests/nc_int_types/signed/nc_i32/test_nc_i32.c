/* tests/nc_int_types/signed/nc_i32/test_nc_i32.c */

/*
    About: Successful tests 'nc_i32' datatype.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Success */

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i32 x = nc_new_i32(150);
    nc_i32 y = nc_new_i32(150);

    printf("NC_GET_VAL [x]: %d\n", nc_get_val(x));
    printf("NC_GET_VAL [y]: %d\n", nc_get_val(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size(x));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %d\n", nc_get_val(nc_checked_add(x, y)));
}