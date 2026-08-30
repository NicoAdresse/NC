/* tests/nc_int_types/unsigned/nc_u32/test_nc_u32_constructor_overflow.c */

/*
    About: Overflow testing of the 'nc_u32' constructor.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_u32 x = nc_new_u32(NC_U32_MAX+1);
}