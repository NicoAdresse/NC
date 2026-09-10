/* tests/nc_int_types/unsigned/nc_ptr_u8/test_nc_ptr_u8.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_ptr_u8'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_u8 val_a = nc_new_u8(10);
    nc_u8 val_b = nc_new_u8(5);
    nc_u8 val_zero = nc_new_u8(0);
    nc_u8 val_max = nc_new_u8(NC_U8_MAX);
    
    nc_ptr_u8 ptr_a = nc_new_ptr_u8(val_a);
    nc_ptr_u8 ptr_max = nc_new_ptr_u8(val_max);
    nc_ptr_u8 ptr_null = {.ptr = NULL};

    printf("=== SUCCESS CASES (u8) ===\n");
    nc_ptr_u8 res_add = nc_checked_add_ptr_u8(ptr_a, val_b);
    printf("NC_CHECKED_ADD [10 + 5] -> Expected: 15 | Got: %u\n", nc_get_val_int(*res_add.ptr));

    nc_ptr_u8 res_sub = nc_checked_sub_ptr_u8(ptr_a, val_b);
    printf("NC_CHECKED_SUB [10 - 5] -> Expected: 5 | Got: %u\n", nc_get_val_int(*res_sub.ptr));

    nc_ptr_u8 res_mul = nc_checked_mul_ptr_u8(ptr_a, val_b);
    printf("NC_CHECKED_MUL [10 * 5] -> Expected: 50 | Got: %u\n", nc_get_val_int(*res_mul.ptr));

    nc_ptr_u8 res_div = nc_checked_div_ptr_u8(ptr_a, val_b, 0);
    printf("NC_CHECKED_DIV [10 / 5] -> Expected: 2 | Got: %u\n", nc_get_val_int(*res_div.ptr));

    printf("\n=== ERROR CASES (u8) ===\n");
    nc_ptr_u8 res_overflow = nc_checked_add_ptr_u8(ptr_max, val_b);
    printf("NC_CHECKED_ADD Overflow [255 + 5] -> Expected: %d (Clamped) | Got: %u\n", NC_U8_MAX, nc_get_val_int(*res_overflow.ptr));

    nc_ptr_u8 res_div_zero = nc_checked_div_ptr_u8(ptr_a, val_zero, 0);
    printf("NC_CHECKED_DIV Zero [10 / 0] -> Expected: 0 | Got: %u\n", nc_get_val_int(*res_div_zero.ptr));

    nc_ptr_u8 res_null = nc_checked_add_ptr_u8(ptr_null, val_b);
    printf("NC_CHECKED_ADD Null Pointer -> Expected Pointer: NULL | Got Pointer: %p\n", (void*)res_null.ptr);

    nc_assert_eq(nc_get_val_int(nc_checked_mod_int(val_a, val_b, 0)), 0);
    nc_debug_log("Should appear if successful.");

    nc_free_int(ptr_a);
    nc_free_int(ptr_max);
    nc_free_int(ptr_null);
    nc_free_int(res_add);
    nc_free_int(res_sub);
    nc_free_int(res_mul);
    nc_free_int(res_div);
    nc_free_int(res_div_zero);
    nc_free_int(res_overflow);

    return 0;
}