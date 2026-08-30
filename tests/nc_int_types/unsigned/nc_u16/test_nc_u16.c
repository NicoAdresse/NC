/* tests/nc_int_types/unsigned/nc_u16/test_nc_u16.c */

/*
    About: Successful tests 'nc_u16' datatype.
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
    nc_u16 x = nc_new_u16(1000);
    nc_u16 y = nc_new_u16(500);

    printf("NC_GET_VAL [x]: %d\n", nc_get_val(x));
    printf("NC_GET_VAL [y]: %d\n", nc_get_val(y));
    printf("NC_GET_SIZE [x]: %ld\n", nc_get_size(x));
    printf("NC_GET_VAL(NC_CHECKED_ADD) [x, y]: %d\n", nc_get_val(nc_checked_add(x, y)));
}