/* tests/nc_int_types/signed/nc_i16/test_nc_i16_constructor_underflow.c */

/*
    About: Underflow testing of the 'nc_i16' constructor.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* Expected result: Error */

#include "../../../../src/nc/nc_int_types.h"

int main(void) {
    nc_i16 x = nc_new_i16(NC_I16_MIN-1);
}