/* src/nc/nc_int/nc_i64/nc_i64.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_i64'.
*/

#ifndef NC_I64_H
#define NC_I64_H

#include <stdint.h>
#include <stdlib.h>

#include "../inc_helper_funcs.h"
#include "../nc_int_macros.h"
#include "../nc_types.h"
#include "../nc_int_constructors.h"

/* Checked Addition -> nc_i64 */
static inline nc_i64 nc_checked_add_i64(nc_i64 number_one, nc_i64 number_two) {
    if (number_two.val > 0 && number_one.val > NC_I64_MAX - number_two.val) {
        send_constructor_error_msg(64, IS_SIGNED, ERROR_OVERFLOW, NC_I64_MAX, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (number_two.val < 0 && number_one.val < NC_I64_MIN - number_two.val) {
        send_constructor_error_msg(64, IS_SIGNED, ERROR_UNDERFLOW, NC_I64_MIN, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

    int64_t sum = number_one.val + number_two.val;
    return (nc_i64){.val = sum};
}

/* Checked Subtraction -> nc_i64 */
static inline nc_i64 nc_checked_sub_i64(nc_i64 number_one, nc_i64 number_two) {
    if (number_two.val < 0 && number_one.val > NC_I64_MAX + number_two.val) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (number_two.val > 0 && number_one.val < NC_I64_MIN + number_two.val) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

    int64_t diff = number_one.val - number_two.val;
    return (nc_i64){.val = diff};
}

/* Checked Multiplication -> nc_i64 */
static inline nc_i64 nc_checked_mul_i64(nc_i64 number_one, nc_i64 number_two) {
    if (number_one.val == 0 || number_two.val == 0) {
        return (nc_i64){.val = 0};
    }

    if (number_one.val == NC_I64_MIN && number_two.val == -1) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }
    if (number_two.val == NC_I64_MIN && number_one.val == -1) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (number_one.val > 0 && number_two.val > 0 && number_one.val > NC_I64_MAX / number_two.val) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }
    if (number_one.val > 0 && number_two.val < 0 && number_two.val < NC_I64_MIN / number_one.val) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }
    if (number_one.val < 0 && number_two.val > 0 && number_one.val < NC_I64_MIN / number_one.val) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }
    if (number_one.val < 0 && number_two.val < 0 && number_one.val < NC_I64_MAX / number_two.val) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    int64_t product = number_one.val * number_two.val;
    return (nc_i64){.val = product};
}

/* Checked Division -> nc_i64 */
static inline nc_i64 nc_checked_div_i64(nc_i64 number_one, nc_i64 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, number_one.val, number_two.val);
        }
        return (nc_i64){.val = 0};
    }

    if (number_one.val == NC_I64_MIN && number_two.val == -1) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    int64_t quotient = number_one.val / number_two.val;
    return (nc_i64){.val = quotient};
}

/* nc_i64_convert_to */
static inline nc_i8 nc_i64_convert_to_i8(nc_i64 primitive) { return nc_new_i8(primitive.val); }
static inline nc_i16 nc_i64_convert_to_i16(nc_i64 primitive) { return nc_new_i16(primitive.val); }
static inline nc_i32 nc_i64_convert_to_i32(nc_i64 primitive) { return nc_new_i32(primitive.val); }
static inline nc_u8 nc_i64_convert_to_u8(nc_i64 primitive) { return nc_new_u8(primitive.val); }
static inline nc_u16 nc_i64_convert_to_u16(nc_i64 primitive) { return nc_new_u16(primitive.val); }
static inline nc_u32 nc_i64_convert_to_u32(nc_i64 primitive) { return nc_new_u32(primitive.val); }
static inline nc_u64 nc_i64_convert_to_u64(nc_i64 primitive) { return nc_new_u64(primitive.val); }

/* nc_i64_convert_to_libc_primitive */
static inline int nc_i64_convert_to_int(nc_i64 primitive) { return primitive.val; }
static inline int8_t nc_i64_convert_to_int8_t(nc_i64 primitive) { return primitive.val; }
static inline uint8_t nc_i64_convert_to_uint8_t(nc_i64 primitive) { return primitive.val; }
static inline int16_t nc_i64_convert_to_int16_t(nc_i64 primitive) { return primitive.val; }
static inline uint16_t nc_i64_convert_to_uint16_t(nc_i64 primitive) { return primitive.val; }
static inline int32_t nc_i64_convert_to_int32_t(nc_i64 primitive) { return primitive.val; }
static inline uint32_t nc_i64_convert_to_uint32_t(nc_i64 primitive) { return primitive.val; }
static inline int64_t nc_i64_convert_to_int64_t(nc_i64 primitive) { return primitive.val; }
static inline uint64_t nc_i64_convert_to_uint64_t(nc_i64 primitive) { return primitive.val; }

/* nc_libc_primitive_convert_to_i64 */
static inline nc_i64 nc_int_convert_to_i64(int val) { return nc_new_i64(val); }
static inline nc_i64 nc_int8_t_convert_to_i64(int8_t val) { return nc_new_i64(val); }
static inline nc_i64 nc_uint8_t_convert_to_i64(uint8_t val) { return nc_new_i64(val); }
static inline nc_i64 nc_int16_t_convert_to_i64(int16_t val) { return nc_new_i64(val); }
static inline nc_i64 nc_uint16_t_convert_to_i64(uint16_t val) { return nc_new_i64(val); }
static inline nc_i64 nc_int32_t_convert_to_i64(int32_t val) { return nc_new_i64(val); }
static inline nc_i64 nc_uint32_t_convert_to_i64(uint32_t val) { return nc_new_i64(val); }
static inline nc_i64 nc_int64_t_convert_to_i64(int64_t val) { return nc_new_i64(val); }
static inline nc_i64 nc_uint64_t_convert_to_i64(uint64_t val) { return nc_new_i64((int64_t)val); }

/* nc_get_val */
static inline int64_t nc_get_val_i64(nc_i64 primitive) { return primitive.val; }

/* nc_get_size */
static inline size_t nc_get_size_i64() { return sizeof(nc_i64); }

#endif /* NC_I64_H */