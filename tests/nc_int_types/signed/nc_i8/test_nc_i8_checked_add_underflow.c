/* tests/nc_int_types/signed/nc_i8/test_nc_i8_checked_add_underflow.c */

/*
    About: Underflow tests 'nc_i8' datatype using the 'nc_checked_add' function.
    Initial Commit: INIT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_i8 x = nc_new_i8(-55);
    nc_i8 y = nc_new_i8(-110);
    nc_i8 z = nc_checked_add(x, y);
}