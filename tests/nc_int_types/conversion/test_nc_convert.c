/* tests/nc_int_types/conversion/test_nc_convert.c */

/*
    About: Successful tests for 'nc_convert' macro across types.
    Initial Commit: TESTING
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#include "../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i32 original_val = nc_new_i32(300);

    /* Convert nc_i32 to nc_i8 (should trigger overflow/clamping to 127) */
    nc_i8 converted_i8 = nc_convert(nc_i8, original_val);
    printf("NC_GET_VAL [original i32]: %d\n", nc_get_val(original_val));
    printf("NC_GET_VAL [converted to i8]: %d\n", nc_get_val(converted_i8));

    /* Convert nc_i32 to nc_u16 (fits fine) */
    nc_u16 converted_u16 = nc_convert(nc_u16, original_val);
    printf("NC_GET_VAL [converted to u16]: %u\n", nc_get_val(converted_u16));

    printf("CONVERTED_U16 SIZE: %ld\n", nc_get_size(converted_u16));
    int convert_int = nc_convert(int, converted_u16);

    printf("SIZEOF: %ld\n", sizeof(convert_int));
}