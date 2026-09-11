/* src/nc/nc_int/nc_ptr_i64/nc_ptr_i64.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_ptr_i64'.
*/

#ifndef NC_PTR_I64_H
#define NC_PTR_I64_H

#include "../nc_int_macros.h"
#include "../nc_types.h"
#include "../nc_int_constructors.h"
#include "../inc_helper_funcs.h"

/* Checked Addition -> nc_ptr_i64 */
static inline nc_ptr_i64 nc_checked_add_ptr_i64(nc_ptr_i64 ptr_num, nc_i64 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i64");
        return (nc_ptr_i64){.ptr = NULL};
    }

    nc_i64 number_one = *ptr_num.ptr;

    if (val.val > 0 && number_one.val > NC_I64_MAX - val.val) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = (int64_t)NC_I64_MAX});
    }

    if (val.val < 0 && number_one.val < NC_I64_MIN - val.val) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = (int64_t)NC_I64_MIN});
    }

    int64_t sum = number_one.val + val.val;
    return nc_new_ptr_i64((nc_i64){.val = sum});
}

/* Checked Subtraction -> nc_ptr_i64 */
static inline nc_ptr_i64 nc_checked_sub_ptr_i64(nc_ptr_i64 ptr_num, nc_i64 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i64");
        return (nc_ptr_i64){.ptr = NULL};
    }

    nc_i64 number_one = *ptr_num.ptr;

    if (val.val < 0 && number_one.val > NC_I64_MAX - val.val) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = NC_I64_MAX});
    }

    if (val.val > 0 && number_one.val < NC_I64_MIN + val.val) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = (int64_t)NC_I64_MIN});
    }

    int64_t diff = number_one.val - val.val;
    return nc_new_ptr_i64((nc_i64){.val = diff});
}

/* Checked Multiplication -> nc_ptr_i64 */
static inline nc_ptr_i64 nc_checked_mul_ptr_i64(nc_ptr_i64 ptr_num, nc_i64 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i64");
        return (nc_ptr_i64){.ptr = NULL};
    }

    nc_i64 number_one = *ptr_num.ptr;

    if (number_one.val > 0 && val.val > 0 && number_one.val > NC_I64_MAX / val.val) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = (int64_t)NC_I64_MAX});
    }

    if (number_one.val > 0 && val.val < 0 && val.val < NC_I64_MIN / number_one.val) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = (int64_t)NC_I64_MIN});
    }

    if (number_one.val < 0 && val.val > 0 && number_one.val < NC_I64_MIN / val.val) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = (int64_t)NC_I64_MIN});
    }

    if (number_one.val < 0 && val.val < 0 && number_one.val < NC_I64_MAX / val.val) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = (int64_t)NC_I64_MAX});
    }

    int64_t prod = number_one.val * val.val;
    return nc_new_ptr_i64((nc_i64){.val = prod});
}

/* Checked Division -> nc_ptr_i64 */
static inline nc_ptr_i64 nc_checked_div_ptr_i64(nc_ptr_i64 ptr_num, nc_i64 val, int is_zero_denominator_allowed) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i64");
        return (nc_ptr_i64){.ptr = NULL};
    }

    nc_i64 number_one = *ptr_num.ptr;

    if (val.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val);
        }
        return nc_new_ptr_i64((nc_i64){.val = 0});
    }

    if (number_one.val == NC_I64_MIN && val.val == -1) {
        send_bounds_ptr_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_I64_MAX);
        return nc_new_ptr_i64((nc_i64){.val = (int64_t)NC_I64_MAX});
    }

    int64_t quot = number_one.val / val.val;
    return nc_new_ptr_i64((nc_i64){.val = quot});
}

/* Checked Modulo -> nc_ptr_i64 */
static inline nc_ptr_i64 nc_checked_mod_ptr_i64(nc_ptr_i64 ptr_num, nc_i64 val, int is_zero_denominator_allowed) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_SIGNED, "nc_ptr_i64");
        return (nc_ptr_i64){.ptr = NULL};
    }

    nc_i64 number_one = *ptr_num.ptr;

    if (val.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)val.val);
        }
        return nc_new_ptr_i64((nc_i64){.val = 0});
    }

    if (number_one.val == NC_I64_MIN && val.val == -1) {
        return nc_new_ptr_i64((nc_i64){.val = 0});
    }

    int64_t rem = number_one.val % val.val;
    return nc_new_ptr_i64((nc_i64){.val = rem});
}

/* nc_get_size */
static inline size_t nc_get_size_ptr_i64() { return sizeof(nc_ptr_i64); }

/* nc_get_val */
static inline nc_i64 nc_get_val_ptr_i64(nc_ptr_i64 primitive) { return *primitive.ptr; }

/* nc_get_signum */
static inline nc_i64 nc_signum_ptr_i64(nc_ptr_i64 ptr) {
    if (!ptr.ptr) {
        return (nc_i64){.val = 0};
    }
    intptr_t addr = (intptr_t)ptr.ptr;
    return (nc_i64){.val = (addr > 0) - (addr < 0)};
}

#endif /* NC_PTR_I64_H */