/* src/nc/nc_float/nc_ptr_f32/nc_ptr_f32.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Pointer type for NC f32 primitives.
*/

#ifndef NC_F32_PTR_H
#define NC_F32_PTR_H

#include <math.h>

#include "../nc_float_primitives.h"
#include "../nc_float_constructors.h"
#include "../nc_f32/nc_f32.h"
#include "../inc_helper_funcs.h"

/* Checked Addition -> nc_ptr_f32 */
static inline nc_ptr_f32 nc_checked_add_ptr_f32(nc_f32 number_one, nc_f32 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    nc_f32 sum = nc_checked_add_f32(number_one, number_two);
    return nc_new_ptr_f32((double)sum.val);
}

/* Checked Subtraction -> nc_ptr_f32 */
static inline nc_ptr_f32 nc_checked_sub_ptr_f32(nc_f32 number_one, nc_f32 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    nc_f32 diff = nc_checked_sub_f32(number_one, number_two);
    return nc_new_ptr_f32((double)diff.val);
}

/* Checked Multiplication -> nc_ptr_f32 */
static inline nc_ptr_f32 nc_checked_mul_ptr_f32(nc_f32 number_one, nc_f32 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    nc_f32 prod = nc_checked_mul_f32(number_one, number_two);
    return nc_new_ptr_f32((double)prod.val);
}

/* Checked Division -> nc_ptr_f32 */
static inline nc_ptr_f32 nc_checked_div_ptr_f32(nc_f32 number_one, nc_f32 number_two, int zero_division_allowed) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    nc_f32 quot = nc_checked_div_f32(number_one, number_two, zero_division_allowed);
    return nc_new_ptr_f32((double)quot.val);
}

/* Checked Mod -> nc_ptr_f32 */
static inline nc_ptr_f32 nc_checked_mod_ptr_f32(nc_f32 number_one, nc_f32 number_two, int zero_division_allowed) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_ptr_f32){.val = NULL};
    }

    nc_f32 rem = nc_checked_mod_f32(number_one, number_two, zero_division_allowed);
    return nc_new_ptr_f32((double)rem.val);
}

/* Checked Signum -> nc_ptr_f32 */
static inline nc_ptr_f32 nc_checked_signum_ptr_f32(nc_f32 number) {
    if (isnan(number.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number.val, 0.0);
        return (nc_ptr_f32){.val = NULL};
    }

    if (isinf(number.val)) {
        send_float_error(32, ERROR_ISINF, (double)number.val, 0.0);
        return (nc_ptr_f32){.val = NULL};
    }

    nc_f32 sig = nc_checked_signum_f32(number);
    return nc_new_ptr_f32((double)sig.val);
}

/* Helper functions */
static inline float nc_get_val_ptr_f32(nc_ptr_f32 val) { return *val.val; }
static inline size_t nc_get_size_ptr_f32() { return sizeof(nc_ptr_f32); }

#endif /* NC_F32_PTR_H */