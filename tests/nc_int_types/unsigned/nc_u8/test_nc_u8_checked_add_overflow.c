/* tests/nc_int_types/unsigned/nc_u8/test_nc_u8_checked_add_overflow.c */

/*
    About: Overflow tests 'nc_u8' datatype using the 'nc_checked_add' function.
    Initial Commit: INIT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_u8 x = nc_new_u8(155);
    nc_u8 y = nc_new_u8(165);
    nc_u8 z = nc_checked_add(x, y);
}