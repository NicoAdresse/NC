/* tests/nc_int_types/signed/nc_i32/test_nc_i32_checked_add_overflow.c */

/*
    About: Overflow tests 'nc_i32' datatype using the 'nc_checked_add' function.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_i32 x = nc_new_i32(NC_I32_MAX);
    nc_i32 y = nc_new_i32(1);
    nc_i32 z = nc_checked_add(x, y);
}