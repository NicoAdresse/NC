/* src/nc/nc_int/nc_ptr_i32/nc_ptr_i32.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_ptr_i32'.
*/

#ifndef NC_PTR_I32_H
#define NC_PTR_I32_H

#include "../nc_int_macros.h"
#include "../nc_types.h"
#include "../nc_int_constructors.h"
#include "../inc_helper_funcs.h"

/* Checked Addition -> nc_ptr_i32 */
static inline nc_ptr_i32 nc_checked_add_ptr_i32(nc_ptr_i32 ptr_num, nc_i32 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i32");
        return (nc_ptr_i32){.ptr = NULL};
    }

    nc_i32 number_one = *ptr_num.ptr;

    if (val.val > 0 && number_one.val > NC_I32_MAX - val.val) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = (int32_t)NC_I32_MAX});
    }

    if (val.val < 0 && number_one.val < NC_I32_MIN - val.val) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = (int32_t)NC_I32_MIN});
    }

    int32_t sum = number_one.val + val.val;
    return nc_new_ptr_i32((nc_i32){.val = sum});
}

/* Checked Subtraction -> nc_ptr_i32 */
static inline nc_ptr_i32 nc_checked_sub_ptr_i32(nc_ptr_i32 ptr_num, nc_i32 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i32");
        return (nc_ptr_i32){.ptr = NULL};
    }

    nc_i32 number_one = *ptr_num.ptr;

    if (val.val < 0 && number_one.val > NC_I32_MAX - val.val) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = NC_I32_MAX});
    }

    if (val.val > 0 && number_one.val < NC_I32_MIN + val.val) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = (int32_t)NC_I32_MIN});
    }

    int32_t diff = number_one.val - val.val;
    return nc_new_ptr_i32((nc_i32){.val = diff});
}

/* Checked Multiplication -> nc_ptr_i32 */
static inline nc_ptr_i32 nc_checked_mul_ptr_i32(nc_ptr_i32 ptr_num, nc_i32 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i32");
        return (nc_ptr_i32){.ptr = NULL};
    }

    nc_i32 number_one = *ptr_num.ptr;

    if (number_one.val > 0 && val.val > 0 && number_one.val > NC_I32_MAX / val.val) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = (int32_t)NC_I32_MAX});
    }

    if (number_one.val > 0 && val.val < 0 && val.val < NC_I32_MIN / number_one.val) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = (int32_t)NC_I32_MIN});
    }

    if (number_one.val < 0 && val.val > 0 && number_one.val < NC_I32_MIN / val.val) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = (int32_t)NC_I32_MIN});
    }

    if (number_one.val < 0 && val.val < 0 && number_one.val < NC_I32_MAX / val.val) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = (int32_t)NC_I32_MAX});
    }

    int32_t prod = number_one.val * val.val;
    return nc_new_ptr_i32((nc_i32){.val = prod});
}

/* Checked Division -> nc_ptr_i32 */
static inline nc_ptr_i32 nc_checked_div_ptr_i32(nc_ptr_i32 ptr_num, nc_i32 val, int is_zero_denominator_allowed) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i32");
        return (nc_ptr_i32){.ptr = NULL};
    }

    nc_i32 number_one = *ptr_num.ptr;

    if (val.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val);
        }
        return nc_new_ptr_i32((nc_i32){.val = 0});
    }

    if (number_one.val == NC_I32_MIN && val.val == -1) {
        send_bounds_ptr_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I32_MAX);
        return nc_new_ptr_i32((nc_i32){.val = (int32_t)NC_I32_MAX});
    }

    int32_t quot = number_one.val / val.val;
    return nc_new_ptr_i32((nc_i32){.val = quot});
}

/* Checked Modulo -> nc_ptr_i32 */
static inline nc_ptr_i32 nc_checked_mod_ptr_i32(nc_ptr_i32 ptr_num, nc_i32 val, int is_zero_denominator_allowed) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i32");
        return (nc_ptr_i32){.ptr = NULL};
    }

    nc_i32 number_one = *ptr_num.ptr;

    if (val.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val);
        }
        return nc_new_ptr_i32((nc_i32){.val = 0});
    }

    if (number_one.val == NC_I32_MIN && val.val == -1) {
        return nc_new_ptr_i32((nc_i32){.val = 0});
    }

    int32_t rem = number_one.val % val.val;
    return nc_new_ptr_i32((nc_i32){.val = rem});
}


/* nc_get_size */
static inline size_t nc_get_size_ptr_i32() { return sizeof(nc_ptr_i32); }

/* nc_get_val */
static inline nc_i32 nc_get_val_ptr_i32(nc_ptr_i32 primitive) { return *primitive.ptr; }

#endif /* NC_PTR_I32_H */