/* tests/nc_int_types/signed/nc_ptr_i32/test_nc_ptr_i32.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_ptr_i32'.
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    nc_i32 val_a = nc_new_i32(10);
    nc_i32 val_b = nc_new_i32(5);
    nc_i32 val_zero = nc_new_i32(0);
    nc_i32 val_max = nc_new_i32(NC_I32_MAX);
    
    nc_ptr_i32 ptr_a = nc_new_ptr_i32(val_a);
    nc_ptr_i32 ptr_max = nc_new_ptr_i32(val_max);
    nc_ptr_i32 ptr_null = {.ptr = NULL};

    printf("=== SUCCESS CASES (i32) ===\n");
    nc_ptr_i32 res_add = nc_checked_add_ptr_i32(ptr_a, val_b);
    printf("NC_CHECKED_ADD [10 + 5] -> Expected: 15 | Got: %d\n", nc_get_val_int(*res_add.ptr));

    nc_ptr_i32 res_sub = nc_checked_sub_ptr_i32(ptr_a, val_b);
    printf("NC_CHECKED_SUB [10 - 5] -> Expected: 5 | Got: %d\n", nc_get_val_int(*res_sub.ptr));

    nc_ptr_i32 res_mul = nc_checked_mul_ptr_i32(ptr_a, val_b);
    printf("NC_CHECKED_MUL [10 * 5] -> Expected: 50 | Got: %d\n", nc_get_val_int(*res_mul.ptr));

    nc_ptr_i32 res_div = nc_checked_div_ptr_i32(ptr_a, val_b, 0);
    printf("NC_CHECKED_DIV [10 / 5] -> Expected: 2 | Got: %d\n", nc_get_val_int(*res_div.ptr));

    printf("\n=== ERROR CASES (i32) ===\n");
    nc_ptr_i32 res_overflow = nc_checked_add_ptr_i32(ptr_max, val_b);
    printf("NC_CHECKED_ADD Overflow -> Expected Clamped | Got: %d\n", nc_get_val_int(*res_overflow.ptr));

    nc_ptr_i32 res_div_zero = nc_checked_div_ptr_i32(ptr_a, val_zero, 0);
    printf("NC_CHECKED_DIV Zero [10 / 0] -> Expected: 0 | Got: %d\n", nc_get_val_int(*res_div_zero.ptr));

    nc_ptr_i32 res_null = nc_checked_add_ptr_i32(ptr_null, val_b);
    printf("NC_CHECKED_ADD Null Pointer -> Expected Pointer: NULL | Got Pointer: %p\n", (void*)res_null.ptr);

    nc_free_ptr_i32(ptr_a);
    nc_free_ptr_i32(ptr_max);
    nc_free_ptr_i32(ptr_null);

    nc_free_ptr_i32(res_add);
    nc_free_ptr_i32(res_sub);
    nc_free_ptr_i32(res_mul);
    nc_free_ptr_i32(res_div);
    nc_free_ptr_i32(res_div_zero);
    nc_free_ptr_i32(res_null);
    nc_free_ptr_i32(res_overflow);

    return 0;
}