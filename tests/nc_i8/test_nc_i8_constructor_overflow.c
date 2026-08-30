/* tests/nc_i8/test_nc_i8_constructor_overflow.c */

/*
    About: Overflow testing of the nc_i8 constructor.
    Initial Commit: INIT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#include "../../src/nc/nc_int_types.h"

int main(void) {
    nc_i8 x = nc_new_i8(1000);
}