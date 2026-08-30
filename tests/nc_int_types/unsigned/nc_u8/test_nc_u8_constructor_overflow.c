/* tests/nc_int_types/unsigned/nc_u8/test_nc_u8_constructor_overflow.c */

/*
    About: Underflow testing of the 'nc_u8' constructor.
    Initial Commit: INIT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_u8 x = nc_new_u8(555);
}