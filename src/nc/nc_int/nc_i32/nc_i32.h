/* src/nc/nc_int/nc_i32/nc_i32.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_i32'.
*/

#ifndef NC_I32_H
#define NC_I32_H

#include <stdint.h>
#include <stdlib.h>

#include "../inc_helper_funcs.h"
#include "../nc_int_macros.h"
#include "../nc_types.h"
#include "../nc_int_constructors.h"

/* Checked Addition -> nc_i32 */
static inline nc_i32 nc_checked_add_i32(nc_i32 number_one, nc_i32 number_two) {
    int64_t sum = (int64_t)number_one.val + (int64_t)number_two.val;

    if (check_overflow(sum, NC_I32_MAX)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I32_MAX);
        return (nc_i32){.val = (int32_t)NC_I32_MAX};   
    }

    if (check_underflow(sum, NC_I32_MIN)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I32_MIN);
        return (nc_i32){.val = (int32_t)NC_I32_MIN};   
    }

    return (nc_i32){.val = (int32_t)sum};
}

/* Checked Subtraction -> nc_i32 */
static inline nc_i32 nc_checked_sub_i32(nc_i32 number_one, nc_i32 number_two) {
    int64_t diff = (int64_t)number_one.val - (int64_t)number_two.val;

    if (check_overflow(diff, NC_I32_MAX)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I32_MAX);
        return (nc_i32){.val = (int32_t)NC_I32_MAX};
    }

    if (check_underflow(diff, NC_I32_MIN)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I32_MIN);
        return (nc_i32){.val = (int32_t)NC_I32_MIN};
    }

    return (nc_i32){.val = (int32_t)diff};
}

/* Checked Multiplication -> nc_i32 */
static inline nc_i32 nc_checked_mul_i32(nc_i32 number_one, nc_i32 number_two) {
    int64_t product = (int64_t)number_one.val * (int64_t)number_two.val;

    if (check_overflow(product, NC_I32_MAX)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I32_MAX);
        return (nc_i32){.val = (int32_t)NC_I32_MAX};
    }

    if (check_underflow(product, NC_I32_MIN)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I32_MIN);
        return (nc_i32){.val = (int32_t)NC_I32_MIN};
    }

    return (nc_i32){.val = (int32_t)product};
}

/* Checked Division -> nc_i32 */
static inline nc_i32 nc_checked_div_i32(nc_i32 number_one, nc_i32 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val);
            return (nc_i32){.val = 0};
        }
        return (nc_i32){.val = 0};
    }

    int64_t quotient = (int64_t)number_one.val / (int64_t)number_two.val;

    if (check_overflow(quotient, NC_I32_MAX)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I32_MAX);
        return (nc_i32){.val = (int32_t)NC_I32_MAX};
    }

    if (check_underflow(quotient, NC_I32_MIN)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I32_MIN);
        return (nc_i32){.val = (int32_t)NC_I32_MIN};
    }

    return (nc_i32){.val = (int32_t)quotient};
}

/* Checked Modulo -> nc_i32 */
static inline nc_i32 nc_checked_mod_i32(nc_i32 number_one, nc_i32 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val);
            return (nc_i32){.val = 0};
        } 
        return (nc_i32){.val = 0};
    }

    int64_t remainder = (int64_t)number_one.val % (int64_t)number_two.val;
    return (nc_i32){.val = (int32_t)remainder};
}
    
/* nc_i32_convert_to */
static inline nc_i8 nc_i32_convert_to_i8(nc_i32 primitive) { return nc_new_i8(primitive.val); }
static inline nc_i16 nc_i32_convert_to_i16(nc_i32 primitive) { return nc_new_i16(primitive.val); }
static inline nc_u8 nc_i32_convert_to_u8(nc_i32 primitive) { return nc_new_u8(primitive.val); }
static inline nc_u16 nc_i32_convert_to_u16(nc_i32 primitive) { return nc_new_u16(primitive.val); }
static inline nc_u32 nc_i32_convert_to_u32(nc_i32 primitive) { return nc_new_u32(primitive.val); }
static inline nc_i64 nc_i32_convert_to_i64(nc_i32 primitive) { return nc_new_i64(primitive.val); }
static inline nc_u64 nc_i32_convert_to_u64(nc_i32 primitive) { return nc_new_u64(primitive.val); }

/* nc_convert_i32_to_libc_primitive */
static inline int nc_i32_convert_to_int(nc_i32 primitive) { return primitive.val; }
static inline int8_t nc_i32_convert_to_int8_t(nc_i32 primitive) { return primitive.val; }
static inline uint8_t nc_i32_convert_to_uint8_t(nc_i32 primitive) { return primitive.val; }
static inline int16_t nc_i32_convert_to_int16_t(nc_i32 primitive) { return primitive.val; }
static inline uint16_t nc_i32_convert_to_uint16_t(nc_i32 primitive) { return primitive.val; }
static inline int32_t nc_i32_convert_to_int32_t(nc_i32 primitive) { return primitive.val; }
static inline uint32_t nc_i32_convert_to_uint32_t(nc_i32 primitive) { return primitive.val; }
static inline int64_t nc_i32_convert_to_int64_t(nc_i32 primitive) { return primitive.val; }
static inline uint64_t nc_i32_convert_to_uint64_t(nc_i32 primitive) { return primitive.val; }

/* nc_libc_primitive_convert_to_i32 */
static inline nc_i32 nc_int_convert_to_i32(int val) { return nc_new_i32(val); }
static inline nc_i32 nc_int8_t_convert_to_i32(int8_t val) { return nc_new_i32(val); }
static inline nc_i32 nc_uint8_t_convert_to_i32(uint8_t val) { return nc_new_i32(val); }
static inline nc_i32 nc_int16_t_convert_to_i32(int16_t val) { return nc_new_i32(val); }
static inline nc_i32 nc_uint16_t_convert_to_i32(uint16_t val) { return nc_new_i32(val); }
static inline nc_i32 nc_int32_t_convert_to_i32(int32_t val) { return nc_new_i32(val); }
static inline nc_i32 nc_uint32_t_convert_to_i32(uint32_t val) { return nc_new_i32(val); }
static inline nc_i32 nc_int64_t_convert_to_i32(int64_t val) { return nc_new_i32(val); }
static inline nc_i32 nc_uint64_t_convert_to_i32(uint64_t val) { return nc_new_i32((int64_t)val); }

/* nc_get_val */
static inline int32_t nc_get_val_i32(nc_i32 primitive) { return primitive.val; }

/* nc_get_size */
static inline size_t nc_get_size_i32() { return sizeof(nc_i32); }

/* nc_get_signum */
static inline nc_i32 nc_signum_i32(nc_i32 val) {
    return (nc_i32){.val = (val.val > 0) - (val.val < 0)};
}

#endif /* NC_I32_H */