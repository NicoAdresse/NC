/* tests/nc_int_types/signed/nc_i16/test_nc_i16_checked_add_underflow.c */

/*
    About: Underflow tests 'nc_i16' datatype using the 'nc_checked_add' function.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_i16 x = nc_new_i16(-100);
    nc_i16 y = nc_new_i16(NC_I16_MIN);
    nc_i16 z = nc_checked_add(x, y);
}