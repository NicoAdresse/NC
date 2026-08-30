/* tests/nc_int_types/unsigned/nc_u32/test_nc_u32_checked_add_overflow.c */

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
    nc_u32 x = nc_new_u32(101);
    nc_u32 y = nc_new_u32(NC_U32_MAX-100);
    nc_u32 z = nc_checked_add(x, y);
}