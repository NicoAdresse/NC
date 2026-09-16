/* tests/nc_float_types/nc_f64/test_nc_f64.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_f64'.
*/

#include "../../../src/nc/nc_float_types.h"

int main(void) {
    nc_f64 x = nc_new_f64(40.0);
    nc_f64 y = nc_new_f64(-20.0);

    nc_assert_eq(nc_get_val_float(x), 40.0);
    nc_assert_eq(nc_get_val_float(y), -20.0);
    nc_debug_log("You should see this if 'x == 40.0' and 'y == -20.0'.");

    nc_f64 add_result = nc_checked_add_float(x, y);
    float expected_add_result = 20.0;

    nc_assert_eq(nc_get_val_float(add_result), expected_add_result);
    nc_debug_log("You should see this if 'add_result == expected_add_result'.");

    nc_f64 sub_result = nc_checked_sub_float(x, y);
    float expected_sub_result = 60.0;

    nc_assert_eq(nc_get_val_float(sub_result), expected_sub_result);
    nc_debug_log("You should see this if 'sub_result == expected_sub_result'.");

    nc_f64 mul_result = nc_checked_mul_float(x, y);
    float expected_mul_result = -800.0;

    nc_assert_eq(nc_get_val_float(mul_result), expected_mul_result);
    nc_debug_log("You should see this if 'mul_result == expected_mul_result'.");

    nc_f64 div_result = nc_checked_div_float(x, y, 0);
    float expected_div_result = -2.0;

    nc_assert_eq(nc_get_val_float(div_result), expected_div_result);
    nc_debug_log("You should see this if 'div_result == expected_div_result'.");

    nc_f64 mod_result = nc_checked_mod_float(x, y, 0);
    float expected_mod_result = 0.0;

    nc_assert_eq(nc_get_val_float(mod_result), expected_mod_result);
    nc_debug_log("You should see this if 'mod_result' == 'expected_mod_result'.");
}