/* tests/nc_int_types/conversion/test_nc_convert.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Conversion testing between different NC integer primitives.
*/

#include "../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i32 original_val = nc_new_i32(300);

    nc_i8 converted_i8 = nc_convert_int(nc_i8, original_val);
    printf("NC_GET_VAL [original i32]: %d\n", nc_get_val_int(original_val));
    printf("NC_GET_VAL [converted to i8]: %d\n", nc_get_val_int(converted_i8));

    nc_u16 converted_u16 = nc_convert_int(nc_u16, original_val);
    printf("NC_GET_VAL [converted to u16]: %u\n", nc_get_val_int(converted_u16));

    printf("CONVERTED_U16 SIZE: %ld\n", nc_get_size_int(converted_u16));
    int convert_int = nc_convert_int(int, converted_u16);

    printf("SIZEOF: %ld\n", sizeof(convert_int));

    nc_i32 another_val = nc_new_i32(1000);
    uint32_t converted_uint32_t = nc_i32_convert_to_uint32_t(another_val);

    printf("%d | %ld\n", converted_uint32_t, sizeof(converted_uint32_t));
}