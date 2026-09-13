/* src/nc/nc_float/nc_f32/nc_f32.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_f32'.
*/

#ifndef NC_F32_H
#define NC_F32_H

#include <math.h>

#include "../nc_float_primitives.h"
#include "../inc_helper_funcs.h"

/* Checked Addition -> nc_f32 */
static inline nc_f32 nc_checked_add_f32(nc_f32 number_one, nc_f32 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    float sum = number_one.val + number_two.val;

    if (isinf(sum)) {
        send_float_error_overflow(32, (double)sum);
        return (nc_f32){.val = 0.0};
    }

    return (nc_f32){.val = sum};
}

/* Checked Subtraction -> nc_f32 */
static inline nc_f32 nc_checked_sub_f32(nc_f32 number_one, nc_f32 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    float diff = number_one.val - number_two.val;

    if (isinf(diff)) {
        send_float_error_overflow(32, (double)diff);
        return (nc_f32){.val = 0.0};
    }

    return (nc_f32){.val = diff};
}

/* Checked Multiplication -> nc_f32 */
static inline nc_f32 nc_checked_mul_f32(nc_f32 number_one, nc_f32 number_two) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    float product = number_one.val * number_two.val;

    if (isinf(product)) {
        send_float_error_overflow(32, (double)product);
        return (nc_f32){.val = 0.0};
    }

    return (nc_f32){.val = product};
}

/* Checked Division -> nc_f32 */
static inline nc_f32 nc_checked_div_f32(nc_f32 number_one, nc_f32 number_two, int is_zero_division_allowed) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    if (number_two.val == 0.0) {
        if (!is_zero_division_allowed) {
            send_float_zero_denominator_error_msg((double)number_one.val, (double)number_two.val);
            return (nc_f32){.val = 0.0};
        }
    }

    float quotient = number_one.val / number_two.val;

    if (isinf(quotient)) {
        send_float_error_overflow(32, (double)quotient);
        return (nc_f32){.val = 0.0};
    }

    return (nc_f32){.val = quotient};
}

/* Checked Modulo -> nc_f32 */
static inline nc_f32 nc_checked_mod_f32(nc_f32 number_one, nc_f32 number_two, int is_zero_division_allowed) {
    if (isnan(number_one.val) || isnan(number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(number_one.val) || isinf(number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)number_one.val, (double)number_two.val);
        return (nc_f32){.val = 0.0};
    }
    
    if (number_two.val == 0.0) {
        if (!is_zero_division_allowed) {
            send_float_zero_denominator_error_msg((double)number_one.val, (double)number_two.val);
            return (nc_f32){.val = 0.0};
        }
    }
    
    float remainder = fmod(number_one.val, number_two.val);
    
    if (isinf(remainder)) {
        send_float_error_overflow(32, (double)remainder);
        return (nc_f32){.val = 0.0};
    }
    
    return (nc_f32){.val = remainder};
}

/* Checked Signum -> nc_f32 */
static inline nc_f32 nc_checked_signum_f32(nc_f32 number) {
    if (isnan(number.val)) {
        send_float_error(32, ERROR_ISNAN, (double)number.val, 0.0);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(number.val)) {
        send_float_error(32, ERROR_ISINF, (double)number.val, 0.0);
        return (nc_f32){.val = 0.0};
    }
    
    float sign = copysign(1.0f, number.val);

    return (nc_f32){.val = sign};
}

/* nc_get_size */
static inline size_t nc_get_size_f32() { return sizeof(nc_f32); }

/* nc_get_val */
static inline float nc_get_val_f32(nc_f32 val) { return val.val; }

#endif /* NC_F32_H */