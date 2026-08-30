/* tests/nc_int_types/unsigned/nc_u16/test_nc_u16_checked_add_overflow.c */

/*
    About: Overflow tests 'nc_u16' datatype using the 'nc_checked_add' function.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_u16 x = nc_new_u16(NC_U16_MAX);
    nc_u16 y = nc_new_u16(1);
    nc_u16 z = nc_checked_add(x, y);
}