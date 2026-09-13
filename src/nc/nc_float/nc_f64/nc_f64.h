/* src/nc/nc_float/nc_f64/nc_f64.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_f64'.
*/

#ifndef NC_F64_H
#define NC_F64_H

#include <math.h>

#include "../nc_float_primitives.h"
#include "../inc_helper_funcs.h"

/* Checked Addition -> nc_f64 */
static inline nc_f64 nc_checked_add_f64(nc_f64 number_one, nc_f64 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    double sum = number_one.val + number_two.val;

    if (isinf(sum)) {
        send_float_error_overflow(64, sum);
        return (nc_f64){.val = 0.0};
    }

    return (nc_f64){.val = sum};
}

/* Checked Subtraction -> nc_f64 */
static inline nc_f64 nc_checked_sub_f64(nc_f64 number_one, nc_f64 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    double diff = number_one.val - number_two.val;

    if (isinf(diff)) {
        send_float_error_overflow(64, diff);
        return (nc_f64){.val = 0.0};
    }

    return (nc_f64){.val = diff};
}

/* Checked Multiplication -> nc_f64 */
static inline nc_f64 nc_checked_mul_f64(nc_f64 number_one, nc_f64 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    double product = number_one.val * number_two.val;

    if (isinf(product)) {
        send_float_error_overflow(64, product);
        return (nc_f64){.val = 0.0};
    }

    return (nc_f64){.val = product};
}

/* Checked Division -> nc_f64 */
static inline nc_f64 nc_checked_div_f64(nc_f64 number_one, nc_f64 number_two, int is_zero_division_allowed) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    if (number_two.val == 0.0) {
        if (!is_zero_division_allowed) {
            send_float_zero_denominator_error_msg(number_one.val, number_two.val);
            return (nc_f64){.val = 0.0};
        }
    }

    double quotient = number_one.val / number_two.val;

    if (isinf(quotient)) {
        send_float_error_overflow(64, quotient);
        return (nc_f64){.val = 0.0};
    }

    return (nc_f64){.val = quotient};
}

/* Checked Modulo -> nc_f64 */
static inline nc_f64 nc_checked_mod_f64(nc_f64 number_one, nc_f64 number_two, int is_zero_division_allowed) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(64, ERROR_ISNAN, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(64, ERROR_ISINF, number_one.val, number_two.val);
        return (nc_f64){.val = 0.0};
    }
    
    if (number_two.val == 0.0) {
        if (!is_zero_division_allowed) {
            send_float_zero_denominator_error_msg(number_one.val, number_two.val);
            return (nc_f64){.val = 0.0};
        }
    }
    
    double remainder = fmod(number_one.val, number_two.val);
    
    if (isinf(remainder)) {
        send_float_error_overflow(64, remainder);
        return (nc_f64){.val = 0.0};
    }
    
    return (nc_f64){.val = remainder};
}

/* Checked Signum -> nc_f64 */
static inline nc_f64 nc_checked_signum_f64(nc_f64 number) {
    if (isnan(number.val)) {
        send_float_error(64, ERROR_ISNAN, number.val, 0.0);
        return (nc_f64){.val = 0.0};
    }

    if (isinf(number.val)) {
        send_float_error(64, ERROR_ISINF, number.val, 0.0);
        return (nc_f64){.val = 0.0};
    }
    
    double sign = copysign(1.0, number.val);

    return (nc_f64){.val = sign};
}

/* nc_get_size */
static inline size_t nc_get_size_f64() { return sizeof(nc_f64); }

/* nc_get_val */
static inline double nc_get_val_f64(nc_f64 val) { return val.val; }

#endif /* NC_F64_H */