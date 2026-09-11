/* src/nc/nc_int/nc_ptr_i8/nc_ptr_i8.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_ptr_i8'.
*/

#ifndef NC_PTR_I8_H
#define NC_PTR_I8_H

#include "../nc_types.h"
#include "../inc_helper_funcs.h"
#include "../nc_int_macros.h"
#include "../nc_int_constructors.h"

/* Checked Addition -> nc_ptr_i8 */
static inline nc_ptr_i8 nc_checked_add_ptr_i8(nc_ptr_i8 ptr_num, nc_i8 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i8");
        return (nc_ptr_i8){.ptr = NULL};
    }

    nc_i8 number_one = *ptr_num.ptr;

    if (val.val > 0 && number_one.val > NC_I8_MAX - val.val) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = (int8_t)NC_I8_MAX});
    }

    if (val.val < 0 && number_one.val < NC_I8_MIN - val.val) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = (int8_t)NC_I8_MIN});
    }

    int8_t sum = number_one.val + val.val;
    return nc_new_ptr_i8((nc_i8){.val = sum});
}

/* Checked Subtraction -> nc_ptr_i8 */
static inline nc_ptr_i8 nc_checked_sub_ptr_i8(nc_ptr_i8 ptr_num, nc_i8 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i8");
        return (nc_ptr_i8){.ptr = NULL};
    }

    nc_i8 number_one = *ptr_num.ptr;

    if (val.val < 0 && number_one.val > NC_I8_MAX - val.val) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = NC_I8_MAX});
    }

    if (val.val < 0 && number_one.val < NC_I8_MIN - val.val) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = (int8_t)NC_I8_MIN});
    }

    int8_t diff = number_one.val - val.val;
    return nc_new_ptr_i8((nc_i8){.val = diff});
}

/* Checked Multiplication -> nc_ptr_i8 */
static inline nc_ptr_i8 nc_checked_mul_ptr_i8(nc_ptr_i8 ptr_num, nc_i8 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i8");
        return (nc_ptr_i8){.ptr = NULL};
    }

    nc_i8 number_one = *ptr_num.ptr;

    if (number_one.val > 0 && val.val > 0 && number_one.val > NC_I8_MAX / val.val) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = (int8_t)NC_I8_MAX});
    }

    if (number_one.val > 0 && val.val < 0 && val.val < NC_I8_MIN / number_one.val) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = (int8_t)NC_I8_MIN});
    }

    if (number_one.val < 0 && val.val > 0 && number_one.val < NC_I8_MIN / val.val) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = (int8_t)NC_I8_MIN});
    }

    if (number_one.val < 0 && val.val < 0 && number_one.val < NC_I8_MAX / val.val) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = (int8_t)NC_I8_MAX});
    }

    int8_t prod = number_one.val * val.val;
    return nc_new_ptr_i8((nc_i8){.val = prod});
}

/* Checked Division -> nc_ptr_i8 */
static inline nc_ptr_i8 nc_checked_div_ptr_i8(nc_ptr_i8 ptr_num, nc_i8 val, int is_zero_denominator_allowed) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i8");
        return (nc_ptr_i8){.ptr = NULL};
    }

    nc_i8 number_one = *ptr_num.ptr;

    if (val.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val);
        }
        return nc_new_ptr_i8((nc_i8){.val = 0});
    }

    if (number_one.val == NC_I8_MIN && val.val == -1) {
        send_bounds_ptr_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I8_MAX);
        return nc_new_ptr_i8((nc_i8){.val = (int8_t)NC_I8_MAX});
    }

    int8_t quot = number_one.val / val.val;
    return nc_new_ptr_i8((nc_i8){.val = quot});
}

/* Checked Modulo -> nc_ptr_i8 */
static inline nc_ptr_i8 nc_checked_mod_ptr_i8(nc_ptr_i8 ptr_num, nc_i8 val, int is_zero_denominator_allowed) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i8");
        return (nc_ptr_i8){.ptr = NULL};
    }

    nc_i8 number_one = *ptr_num.ptr;

    if (val.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val);
        }
        return nc_new_ptr_i8((nc_i8){.val = 0});
    }

    if (number_one.val == NC_I8_MIN && val.val == -1) {
        return nc_new_ptr_i8((nc_i8){.val = 0});
    }

    int8_t rem = number_one.val % val.val;
    return nc_new_ptr_i8((nc_i8){.val = rem});
}

/* nc_get_size */
static inline size_t nc_get_size_ptr_i8() { return sizeof(nc_ptr_i8); }

/* nc_get_val */
static inline nc_i8 nc_get_val_ptr_i8(nc_ptr_i8 primitive) { return *primitive.ptr; }

/* nc_get_signum */
static inline nc_i8 nc_signum_ptr_i8(nc_ptr_i8 ptr) {
    if (!ptr.ptr) {
        return (nc_i8){.val = 0};
    }
    intptr_t addr = (intptr_t)ptr.ptr;
    return (nc_i8){.val = (addr > 0) - (addr < 0)};
}

#endif /* NC_PTR_I8_H */