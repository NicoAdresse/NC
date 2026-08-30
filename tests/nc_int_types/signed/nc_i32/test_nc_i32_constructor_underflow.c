/* tests/nc_int_types/signed/nc_i32/test_nc_i32_constructor_underflow.c */

/*
    About: Underflow testing of the 'nc_i32' constructor.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_i32 x = nc_new_i32(NC_I32_MIN-1);
}