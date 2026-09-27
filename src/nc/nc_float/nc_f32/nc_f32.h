/* src/nc/nc_float/nc_f32/nc_f32.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_f32'.
*/

#ifndef NC_F32_H
#define NC_F32_H

#include <math.h>
#include <stdlib.h>

#include "../nc_float_primitives.h"
#include "../inc_helper_funcs.h"

/* Checked Addition -> nc_f32 */
static inline nc_f32 nc_checked_add_f32(nc_f32 number_one, nc_f32 number_two) {
    float sum = number_one.val + number_two.val;
    return inc_check_for_errs_f32(sum, number_one, number_two);
}

/* Checked Must Addition -> nc_f32 */
static inline nc_f32 nc_checked_must_add_f32(nc_f32 number_one, nc_f32 number_two) {
    float sum = number_one.val + number_two.val;
    inc_check_for_errs_must_f32(sum, number_one, number_two);
    return (nc_f32){.val = sum};
}

/* Checked Subtraction -> nc_f32 */
static inline nc_f32 nc_checked_sub_f32(nc_f32 number_one, nc_f32 number_two) {
    float diff = number_one.val - number_two.val;
    return inc_check_for_errs_f32(diff, number_one, number_two);
}

/* Checked Must Subtraction -> nc_f32 */
static inline nc_f32 nc_checked_sub_must_f32(nc_f32 number_one, nc_f32 number_two) {
    float diff = number_one.val - number_two.val;
    inc_check_for_errs_must_f32(diff, number_one, number_two);
    return (nc_f32){.val = diff};
}

/* Checked Multiplication -> nc_f32 */
static inline nc_f32 nc_checked_mul_f32(nc_f32 number_one, nc_f32 number_two) {
    float product = number_one.val * number_two.val;
    return inc_check_for_errs_f32(product, number_one, number_two);
}

/* Checked Must Multiplication -> nc_f32 */
static inline nc_f32 nc_checked_mul_must_f32(nc_f32 number_one, nc_f32 number_two) {
    float product = number_one.val * number_two.val;
    inc_check_for_errs_must_f32(product, number_one, number_two);
    return (nc_f32){.val = product};
}

/* Checked Division -> nc_f32 */
static inline nc_f32 nc_checked_div_f32(nc_f32 number_one, nc_f32 number_two, int is_zero_division_allowed) {
    if (number_two.val == 0.0) {
        if (!is_zero_division_allowed) {
            send_float_zero_denominator_error_msg((double)number_one.val, (double)number_two.val);
            return (nc_f32){.val = 0.0};
        }
    }

    float quotient = number_one.val / number_two.val;
    return inc_check_for_errs_f32(quotient, number_one, number_two);
}

/* Checked Must Division -> nc_f32 */
static inline nc_f32 nc_checked_div_must_f32(nc_f32 number_one, nc_f32 number_two, int is_zero_division_allowed) {
    if (number_two.val == 0.0) {
        if (!is_zero_division_allowed) {
            send_float_zero_denominator_error_msg((double)number_one.val, (double)number_two.val);
            exit(EXIT_FAILURE);
        }
    }

    float quotient = number_one.val / number_two.val;
    inc_check_for_errs_must_f32(quotient, number_one, number_two);
    return (nc_f32){.val = quotient};
}

/* Checked Modulo -> nc_f32 */
static inline nc_f32 nc_checked_mod_f32(nc_f32 number_one, nc_f32 number_two, int is_zero_division_allowed) {
    if (number_two.val == 0.0) {
        if (!is_zero_division_allowed) {
            send_float_zero_denominator_error_msg((double)number_one.val, (double)number_two.val);
            return (nc_f32){.val = 0.0};
        }
    }
    
    float remainder = fmod(number_one.val, number_two.val);
    return inc_check_for_errs_f32(remainder, number_one, number_two);
}

/* Checked Must Modulo -> nc_f32 */
static inline nc_f32 nc_checked_mod_must_f32(nc_f32 number_one, nc_f32 number_two, int is_zero_division_allowed) {
    if (number_two.val == 0.0) {
        if (!is_zero_division_allowed) {
            send_float_zero_denominator_error_msg((double)number_one.val, (double)number_two.val);
            return (nc_f32){.val = 0.0};
        }
    }
    
    float remainder = fmod(number_one.val, number_two.val);
    inc_check_for_errs_must_f32(remainder, number_one, number_two);
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

/* nc_convert_to_f64 */
static inline nc_f64 nc_f32_convert_to_f64(nc_f32 val) { return (nc_f64){.val = (double)val.val}; }

/* nc_convert_to_libc_primitives */
static inline float nc_f32_convert_to_float(nc_f32 val) { return val.val; }
static inline double nc_f32_convert_to_double(nc_f32 val) { return (double)val.val; }

#endif /* NC_F32_H */