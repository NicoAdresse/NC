/* tests/nc_int_types/unsigned/nc_u16/test_nc_u16_constructor_overflow.c */

/*
    About: Overflow testing of the 'nc_u16' constructor.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_u16 x = nc_new_u16(NC_U16_MAX+1);
}