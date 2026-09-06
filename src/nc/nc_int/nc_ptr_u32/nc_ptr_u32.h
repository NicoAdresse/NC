/* src/nc/nc_int/nc_ptr_u32/nc_ptr_u32.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_ptr_u32'.
*/

#ifndef NC_PTR_U32_H
#define NC_PTR_U32_H

#include "../nc_int_macros.h"
#include "../nc_types.h"
#include "../nc_int_constructors.h"
#include "../inc_helper_funcs.h"

/* Checked Addition -> nc_ptr_u32 */
static inline nc_ptr_u32 nc_checked_add_ptr_u32(nc_ptr_u32 ptr_num, nc_u32 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_UNSIGNED, "nc_ptr_u32");
        return (nc_ptr_u32){.ptr = NULL};
    }

    nc_u32 number_one = *ptr_num.ptr;

    if (number_one.val > NC_U32_MAX - val.val) {
        send_bounds_ptr_error_msg(32, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_U32_MAX);
        return nc_new_ptr_u32((nc_u32){.val = (uint32_t)NC_U32_MAX});
    }

    uint32_t sum = number_one.val + val.val;
    return nc_new_ptr_u32((nc_u32){.val = sum});
}

/* Checked Subtraction -> nc_ptr_u32 */
static inline nc_ptr_u32 nc_checked_sub_ptr_u32(nc_ptr_u32 ptr_num, nc_u32 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_UNSIGNED, "nc_ptr_u32");
        return (nc_ptr_u32){.ptr = NULL};
    }

    nc_u32 number_one = *ptr_num.ptr;

    if (number_one.val < val.val) {
        send_bounds_ptr_error_msg(32, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_UNDERFLOW, NC_U32_MAX);
        return nc_new_ptr_u32((nc_u32){.val = 0});
    }

    uint32_t diff = number_one.val - val.val;
    return nc_new_ptr_u32((nc_u32){.val = diff});
}

/* Checked Multiplication -> nc_ptr_u32 */
static inline nc_ptr_u32 nc_checked_mul_ptr_u32(nc_ptr_u32 ptr_num, nc_u32 val) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_UNSIGNED, "nc_ptr_u32");
        return (nc_ptr_u32){.ptr = NULL};
    }

    nc_u32 number_one = *ptr_num.ptr;

    if (number_one.val > 0 && val.val > 0 && number_one.val > NC_U32_MAX / val.val) {
        send_bounds_ptr_error_msg(32, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)val.val, ERROR_OVERFLOW, NC_U32_MAX);
        return nc_new_ptr_u32((nc_u32){.val = (uint32_t)NC_U32_MAX});
    }

    uint32_t prod = number_one.val * val.val;
    return nc_new_ptr_u32((nc_u32){.val = prod});
}

/* Checked Division -> nc_ptr_u32 */
static inline nc_ptr_u32 nc_checked_div_ptr_u32(nc_ptr_u32 ptr_num, nc_u32 val, int is_zero_denominator_allowed) {
    if (!ptr_num.ptr) {
        send_null_pointer_error_msg(IS_UNSIGNED, "nc_ptr_u32");
        return (nc_ptr_u32){.ptr = NULL};
    }

    nc_u32 number_one = *ptr_num.ptr;

    if (val.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_UNSIGNED, (int64_t)number_one.val, (int64_t)val.val);
        }
        return nc_new_ptr_u32((nc_u32){.val = 0});
    }

    uint32_t quot = number_one.val / val.val;
    return nc_new_ptr_u32((nc_u32){.val = quot});
}

/* nc_get_size */
static inline size_t nc_get_size_ptr_u32() { return sizeof(nc_ptr_u32); }

/* nc_get_val */
static inline nc_u32 nc_get_val_ptr_u32(nc_ptr_u32 primitive) { return *primitive.ptr; }

#endif /* NC_PTR_U32_H */