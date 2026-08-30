/* tests/nc_u8/test_nc_u8_constructor_overflow.c */

/*
    About: Over testing of the nc_u8 constructor.
    Initial Commit: INIT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#include "../../src/nc/nc_int_types.h"

int main(void) {
    nc_u8 x = nc_new_u8(-5);
}