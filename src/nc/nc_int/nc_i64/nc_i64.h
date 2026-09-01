/* src/nc/nc_int/nc_i64/nc_i64.h */

/*
    About: Header file for the primitive datatype 'nc_i64'.
    Initial Commit: NC_INT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
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
    int64_t sum = number_one.val + number_two.val;

    if (check_overflow(sum, NC_I64_MAX)) {
        send_constructor_error_msg(64, IS_SIGNED, ERROR_OVERFLOW, sum, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (check_underflow(sum, NC_I64_MIN)) {
        send_constructor_error_msg(64, IS_SIGNED, ERROR_UNDERFLOW, sum, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

    return (nc_i64){.val = sum};
}

/* Checked Subtraction -> nc_i64 */
static inline nc_i64 nc_checked_sub_i64(nc_i64 number_one, nc_i64 number_two) {
    int64_t diff = number_one.val - number_two.val;

    if (check_overflow(diff, NC_I64_MAX)) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (check_underflow(diff, NC_I64_MIN)) {
        send_bounds_error_msg(32, IS_SIGNED, number_one.val, number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

    return (nc_i64){.val = (int64_t)diff};
}

/* Checked Multiplication -> nc_i64 */
static inline nc_i64 nc_checked_mul_i64(nc_i64 number_one, nc_i64 number_two) {
    int64_t product = number_one.val * number_two.val;

    if (check_overflow(product, NC_I64_MAX)) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (check_underflow(product, NC_I64_MIN)) {
        send_bounds_error_msg(64, IS_SIGNED, number_one.val, number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

    return (nc_i64){.val = product};
}

/* Checked Division -> nc_i64 */
static inline nc_i64 nc_checked_div_i64(nc_i64 number_one, nc_i64 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val);
            return (nc_i64){.val = 0};
        }
        return (nc_i64){.val = 0};
    }

    int64_t quotient = (int64_t)number_one.val / (int64_t)number_two.val;

    if (check_overflow(quotient, NC_I64_MAX)) {
        send_bounds_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (check_underflow(quotient, NC_I64_MIN)) {
        send_bounds_error_msg(64, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

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

/* nc_convert_i64_to_libc_primitive */
static inline int nc_i64_convert_to_int(nc_i64 primitive) { return primitive.val; }
static inline int8_t nc_i64_convert_to_int8_t(nc_i64 primitive) { return primitive.val; }
static inline uint8_t nc_i64_convert_to_uint8_t(nc_i64 primitive) { return primitive.val; }
static inline int16_t nc_i64_convert_to_int16_t(nc_i64 primitive) { return primitive.val; }
static inline uint16_t nc_i64_convert_to_uint16_t(nc_i64 primitive) { return primitive.val; }
static inline int32_t nc_i64_convert_to_int32_t(nc_i64 primitive) { return primitive.val; }
static inline uint32_t nc_i64_convert_to_uint32_t(nc_i64 primitive) { return primitive.val; }
static inline int64_t nc_i64_convert_to_int64_t(nc_i64 primitive) { return primitive.val; }
static inline uint64_t nc_i64_convert_to_uint64_t(nc_i64 primitive) { return primitive.val; }

/* nc_get_val */
static inline int64_t nc_get_val_i64(nc_i64 primitive) { return primitive.val; }

/* nc_get_size */
static inline size_t nc_get_size_i64() { return sizeof(nc_i64); }

#endif /* NC_I64_H */