/* tests/nc_int_types/signed/nc_ptr_i8/test_nc_ptr_i8.c */

/*
    About: Tests for the 'nc_ptr_i8' datatype.
    Initial Commit: NC_INT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#include "../../../../src/nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    // Setup initial values and pointer wrappers
    nc_i8 val_a = nc_new_i8(10);
    nc_i8 val_b = nc_new_i8(5);
    nc_i8 val_zero = nc_new_i8(0);
    nc_i8 val_max = nc_new_i8(NC_I8_MAX);
    
    nc_ptr_i8 ptr_a = nc_new_ptr_i8(val_a);
    nc_ptr_i8 ptr_max = nc_new_ptr_i8(val_max);
    nc_ptr_i8 ptr_null = {.ptr = NULL};

    printf("=== SUCCESS CASES ===\n");
    
    // Expected Result: 10 + 5 = 15
    nc_ptr_i8 res_add = nc_checked_add_ptr_i8(ptr_a, val_b);
    printf("NC_CHECKED_ADD [10 + 5] -> Expected: 15 | Got: %d\n", nc_get_val(*res_add.ptr));

    // Expected Result: 10 - 5 = 5
    nc_ptr_i8 res_sub = nc_checked_sub_ptr_i8(ptr_a, val_b);
    printf("NC_CHECKED_SUB [10 - 5] -> Expected: 5 | Got: %d\n", nc_get_val(*res_sub.ptr));

    // Expected Result: 10 * 5 = 50
    nc_ptr_i8 res_mul = nc_checked_mul_ptr_i8(ptr_a, val_b);
    printf("NC_CHECKED_MUL [10 * 5] -> Expected: 50 | Got: %d\n", nc_get_val(*res_mul.ptr));

    // Expected Result: 10 / 5 = 2
    nc_ptr_i8 res_div = nc_checked_div_ptr_i8(ptr_a, val_b, 0);
    printf("NC_CHECKED_DIV [10 / 5] -> Expected: 2 | Got: %d\n", nc_get_val(*res_div.ptr));


    printf("\n=== ERROR CASES ===\n");

    // Expected Result: Overflow clamping to NC_I8_MAX (127) + error message triggered
    nc_ptr_i8 res_overflow = nc_checked_add_ptr_i8(ptr_max, val_b);
    printf("NC_CHECKED_ADD Overflow [127 + 5] -> Expected: %d (Clamped) | Got: %d\n", NC_I8_MAX, nc_get_val(*res_overflow.ptr));

    // Expected Result: Division by zero -> Expected: 0 (with error message triggered)
    nc_ptr_i8 res_div_zero = nc_checked_div_ptr_i8(ptr_a, val_zero, 0);
    printf("NC_CHECKED_DIV Zero [10 / 0] -> Expected: 0 | Got: %d\n", nc_get_val(*res_div_zero.ptr));

    // Expected Result: Null pointer check -> Handled safely, returns NULL pointer struct
    nc_ptr_i8 res_null = nc_checked_add_ptr_i8(ptr_null, val_b);
    printf("NC_CHECKED_ADD Null Pointer -> Expected Pointer: NULL | Got Pointer: %p\n", (void*)res_null.ptr);

    nc_free_ptr_i8(ptr_a);
    nc_free_ptr_i8(ptr_max);
    nc_free_ptr_i8(ptr_null);

    return 0;
}