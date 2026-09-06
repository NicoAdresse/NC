/* tests/nc_int_types/macros/test_nc_macros.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for generic arithmetic and pointer allocation macros.
*/

#include "../../../src/nc/nc_int_types.h"
#include <stdio.h>
#include <inttypes.h>

int main(void) {
    printf("=== TESTING GENERIC PRIMITIVE & POINTER MACROS ===\n");

    nc_i32 val_primitive = nc_new_int(42);
    nc_ptr_i32 ptr_wrapped = nc_new_ptr_int(val_primitive);
    
    printf("nc_new & nc_new_ptr [i32] -> Got Value: %d, Got Pointer Value: %d\n", 
           nc_get_val_int(val_primitive), nc_get_val_int(*ptr_wrapped.ptr));

    nc_i32 a_prim = nc_new_int(100);
    nc_i32 b_prim = nc_new_int(25);
    nc_i32 res_add_prim = nc_checked_add_int(a_prim, b_prim);
    printf("nc_checked_add [Primitive i32: 100 + 25] -> Expected: 125 | Got: %d\n", nc_get_val_int(res_add_prim));

    nc_ptr_i32 a_ptr = nc_new_ptr_int(nc_new_int(200));
    nc_i32 b_val = nc_new_int(50);
    nc_ptr_i32 res_add_ptr = nc_checked_add_int(a_ptr, b_val);
    printf("nc_checked_add [Pointer i32: 200 + 50] -> Expected: 250 | Got: %d\n", nc_get_val_int(*res_add_ptr.ptr));

    nc_ptr_i32 res_sub_ptr = nc_checked_sub_int(a_ptr, b_val);
    printf("nc_checked_sub [Pointer i32: 200 - 50] -> Expected: 150 | Got: %d\n", nc_get_val_int(*res_sub_ptr.ptr));

    nc_ptr_i32 res_mul_ptr = nc_checked_mul_int(a_ptr, nc_new_int(2));
    printf("nc_checked_mul [Pointer i32: 200 * 2] -> Expected: 400 | Got: %d\n", nc_get_val_int(*res_mul_ptr.ptr));

    nc_ptr_i32 res_div_ptr = nc_checked_div_int(a_ptr, nc_new_int(4), 0);
    printf("nc_checked_div [Pointer i32: 200 / 4] -> Expected: 50 | Got: %d\n", nc_get_val_int(*res_div_ptr.ptr));

    nc_free_int(ptr_wrapped);
    nc_free_int(a_ptr);
    nc_free_int(res_add_ptr);
    nc_free_int(res_sub_ptr);
    nc_free_int(res_mul_ptr);
    nc_free_int(res_div_ptr);

    printf("=== ALL MACRO TESTS COMPLETED SUCCESSFULLY ===\n");
    return 0;
}