/* src/nc/nc_float/nc_ptr_f64/nc_ptr_f64.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Pointer type for NC f64 primitives.
*/

#ifndef NC_PTR_F64_H
#define NC_PTR_F64_H

#include "../nc_float_primitives.h"
#include "../inc_helper_funcs.h"
#include "../nc_f64/nc_f64.h"
#include "../nc_float_constructors.h"

/* Checked Addition -> nc_ptr_f64 */
static inline nc_ptr_f64 nc_checked_add_ptr_f64(nc_f64 number_one, nc_f64 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    nc_f64 sum = nc_checked_add_f64(number_one, number_two);
    return nc_new_ptr_f64((double)sum.val);
}

/* Checked Subtraction -> nc_ptr_f64 */
static inline nc_ptr_f64 nc_checked_sub_ptr_f64(nc_f64 number_one, nc_f64 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    nc_f64 diff = nc_checked_sub_f64(number_one, number_two);
    return nc_new_ptr_f64(diff.val);
}

/* Checked Multiplication -> nc_ptr_f64 */
static inline nc_ptr_f64 nc_checked_mul_ptr_f64(nc_f64 number_one, nc_f64 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    nc_f64 prod = nc_checked_mul_f64(number_one, number_two);
    return nc_new_ptr_f64(prod.val);
}

/* Checked Division -> nc_ptr_f64 */
static inline nc_ptr_f64 nc_checked_div_ptr_f64(nc_f64 number_one, nc_f64 number_two, int zero_division_allowed) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    nc_f64 quot = nc_checked_div_f64(number_one, number_two, zero_division_allowed);
    return nc_new_ptr_f64(quot.val);
}

/* Checked Mod -> nc_ptr_f64 */
static inline nc_ptr_f64 nc_checked_mod_ptr_f64(nc_f64 number_one, nc_f64 number_two, int zero_division_allowed) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_ptr_f64){.val = NULL};
    }

    nc_f64 rem = nc_checked_mod_f64(number_one, number_two, zero_division_allowed);
    return nc_new_ptr_f64(rem.val);
}

/* Checked Signum -> nc_ptr_f64 */
static inline nc_ptr_f64 nc_checked_signum_ptr_f64(nc_f64 number) {
    if (isnan(number.val)) {
        send_float_error(64, ERROR_ISNAN, number.val, 0.0);
        return (nc_ptr_f64){.val = NULL};
    }

    if (isinf(number.val)) {
        send_float_error(64, ERROR_ISINF, number.val, 0.0);
        return (nc_ptr_f64){.val = NULL};
    }

    nc_f64 sig = nc_checked_signum_f64(number);
    return nc_new_ptr_f64(sig.val);
}

/* Helper functions */
static inline size_t nc_get_size_ptr_f64() { return sizeof(nc_ptr_f64); }
static inline double nc_get_val_ptr_f64(nc_ptr_f64 val) { return *val.val; }

#endif /* NC_PTR_F64_H */