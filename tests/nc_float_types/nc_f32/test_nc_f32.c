/* tests/nc_float_types/nc_f32/test_nc_f32.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_f32'.
*/

#include "../../../src/nc.h"

int main(void) {
    nc_f32 x = nc_new_f32(20.0);
    nc_f32 y = nc_new_f32(10.0);

    nc_assert_eq(nc_get_val_float(x), 20.0);
    nc_assert_eq(nc_get_val_float(y), 10.0);
    nc_debug_log("You should see this if 'x == 20.0' and 'y == 10.0'.");

    nc_f32 add_result = nc_checked_add_float(x, y);
    float expected_add_result = 30.0;

    nc_assert_eq(nc_get_val_float(add_result), expected_add_result);
    nc_debug_log("You should see this if 'add_result' == 'expected_add_result'.");

    nc_f32 sub_result = nc_checked_sub_float(x, y);
    float expected_sub_result = 10.0;

    nc_assert_eq(nc_get_val_float(sub_result), expected_sub_result);
    nc_debug_log("You should see this if 'sub_result' == 'expected_sub_result'.");

    nc_f32 mul_result = nc_checked_mul_float(x, y);
    float expected_mul_result = 200.0;

    nc_assert_eq(nc_get_val_float(mul_result), expected_mul_result);
    nc_debug_log("You should see this if 'mul_result' == 'expected_mul_result'.");

    nc_f32 div_result = nc_checked_div_float(x, y, 0);
    float expected_div_result = 2.0;

    nc_assert_eq(nc_get_val_float(div_result), expected_div_result);
    nc_debug_log("You should see this if 'div_result' == 'expected_div_result'.");

    nc_f32 mod_result = nc_checked_mod_float(x, y, 0);
    float expected_mod_result = 0.0;

    nc_assert_eq(nc_get_val_float(mod_result), expected_mod_result);
    nc_debug_log("You should see this if 'mod_result' == 'expected_mod_result'.");
}