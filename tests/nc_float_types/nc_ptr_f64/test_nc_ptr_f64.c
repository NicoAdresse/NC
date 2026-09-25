/* tests/nc_float_types/nc_ptr_f64/test_nc_ptr_f64.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for 'nc_ptr_f64'.
*/

#include "../../../src/nc.h"

int main(void) {
    nc_ptr_f64 x = nc_new_ptr_f64(10.0);
    nc_ptr_f64 y = nc_new_ptr_f64(15.0);

    nc_ptr_f64 x_y_add_res = nc_new_ptr_f64(
        nc_get_val_f64(
            nc_checked_add_float(
                nc_get_val_ptr_f64(x), 
                nc_get_val_ptr_f64(y)
            )
        )
    );

    nc_f64 expected_add_res = nc_new_f64(25.0);
    nc_assert_eq(
        nc_get_val_f64(nc_get_val_ptr_f64(x_y_add_res)), 
        nc_get_val_f64(expected_add_res)
    );
    nc_debug_log("You should see this if 'x_y_add_res' == 25.0.");

    nc_ptr_f64 x_y_sub_res = nc_new_ptr_f64(
        nc_get_val_f64(
            nc_checked_sub_float(
                nc_get_val_ptr_f64(x),
                nc_get_val_ptr_f64(y)
            )
        )
    );

    nc_f64 expected_sub_res = nc_new_f64(-5.0);
    nc_assert_eq(
        nc_get_val_f64(nc_get_val_ptr_f64(x_y_sub_res)),
        nc_get_val_f64(expected_sub_res)
    );
    nc_debug_log("You should see this if 'x_y_sub_res' == -5.0.");

    nc_ptr_f64 x_y_mul_res = nc_new_ptr_f64(
        nc_get_val_f64(
            nc_checked_mul_float(
                nc_get_val_ptr_f64(x), 
                nc_get_val_ptr_f64(y)
            )
        )
    );

    nc_f64 expected_mul_res = nc_new_f64(150.0);
    nc_assert_eq(
        nc_get_val_f64(nc_get_val_ptr_f64(x_y_mul_res)),
        nc_get_val_f64(expected_mul_res)
    );
    nc_debug_log("You should see this if 'x_y_mul_res' == 150.0.");

    nc_ptr_f64 x_y_div_res = nc_new_ptr_f64(
        nc_get_val_f64(
            nc_checked_div_float(
                nc_get_val_ptr_f64(x), 
                nc_get_val_ptr_f64(y),
                0
            )
        )
    );

    nc_f64 expected_div_res = nc_new_f64(10.0 / 15.0);
    nc_assert_eq(
        nc_get_val_f64(nc_get_val_ptr_f64(x_y_div_res)),
        nc_get_val_f64(expected_div_res)
    );
    nc_debug_log("You should see this if 'x_y_div_res' == 10/15.");

    nc_ptr_f64 x_y_mod_res = nc_new_ptr_f64(
        nc_get_val_f64(
            nc_checked_mod_float(
                nc_get_val_ptr_f64(x), 
                nc_get_val_ptr_f64(y),
                0
            )
        )
    );

    nc_f64 expected_mod_res = nc_new_f64(10.0);
    nc_assert_eq(
        nc_get_val_f64(nc_get_val_ptr_f64(x_y_mod_res)),
        nc_get_val_f64(expected_mod_res)
    );
    nc_debug_log("You should see this if 'x_y_mod_res' == 10.0.");

    nc_free_float(x);
    nc_free_float(y);
    nc_free_float(x_y_add_res);
    nc_free_float(x_y_sub_res);
    nc_free_float(x_y_mul_res);
    nc_free_float(x_y_div_res);
    nc_free_float(x_y_mod_res);
}