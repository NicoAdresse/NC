/* src/nc/nc_int/nc_i16/nc_i16.h */

/*
    About: Header file for the primitive datatype 'nc_i16'.
    Initial Commit: NC_INT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#ifndef NC_I16_H
#define NC_I16_H

#include <stdint.h>
#include <stdlib.h>

#include "../nc_int_macros.h"
#include "../inc_helper_funcs.h"
#include "../nc_int_macros.h"
#include "../nc_types.h"
#include "../nc_int_constructors.h"

/* Checked Addition -> nc_i16 */
static inline nc_i16 nc_checked_add_i16(nc_i16 number_one, nc_i16 number_two) {
    int64_t sum = (int64_t)number_one.val + (int64_t)number_two.val;
    
    if (check_overflow(sum, NC_I16_MAX)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I16_MAX);
        return (nc_i16){.val = (int16_t)NC_I16_MAX};
    }

    if (check_underflow(sum, NC_I16_MIN)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I16_MIN);
        return (nc_i16){.val = (int16_t)NC_I16_MIN};
    }

    return (nc_i16){.val = (int16_t)sum};
}

/* Checked Subtraction -> nc_i16 */
static inline nc_i16 nc_checked_sub_i16(nc_i16 number_one, nc_i16 number_two) {
    int64_t diff = (int64_t)number_one.val - (int64_t)number_two.val;

    if (check_overflow(diff, NC_I16_MAX)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I16_MAX);
        return (nc_i16){.val = (int16_t)NC_I16_MAX};
    }

    if (check_underflow(diff, NC_I16_MIN)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I16_MIN);
        return (nc_i16){.val = (int16_t)NC_I16_MIN};
    }

    return (nc_i16){.val = (int16_t)diff};
}

/* Checked Multiplication -> nc_i16 */
static inline nc_i16 nc_checked_mul_i16(nc_i16 number_one, nc_i16 number_two) {
    int64_t product = (int64_t)number_one.val * (int64_t)number_two.val;

    if (check_overflow(product, NC_I16_MAX)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I16_MAX);
        return (nc_i16){.val = (int16_t)NC_I16_MAX};
    }

    if (check_underflow(product, NC_I16_MIN)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I16_MIN);
        return (nc_i16){.val = (int16_t)NC_I16_MIN};
    }

    return (nc_i16){.val = (int16_t)product};
}

/* Checked Division -> nc_i16 */
static inline nc_i16 nc_checked_div_i16(nc_i16 number_one, nc_i16 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val);
            return (nc_i16){.val = 0};
        }
        return (nc_i16){.val = 0};
    }

    int64_t quotient = (int64_t)number_one.val / (int64_t)number_two.val;

    if (check_overflow(quotient, NC_I16_MAX)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I16_MAX);
        return (nc_i16){.val = (int16_t)NC_I16_MAX};
    }

    if (check_underflow(quotient, NC_I16_MIN)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I16_MIN);
        return (nc_i16){.val = (int16_t)NC_I16_MIN};
    }

    return (nc_i16){.val = (int16_t)quotient};
}

/* nc_i16_convert_to */
static inline nc_i8 nc_i16_convert_to_i8(nc_i16 primitive) { return nc_new_i8(primitive.val); }
static inline nc_i32 nc_i16_convert_to_i32(nc_i16 primitive) { return nc_new_i32(primitive.val); }
static inline nc_i64 nc_i16_convert_to_i64(nc_i16 primitive) { return nc_new_i64(primitive.val); }
static inline nc_u8 nc_i16_convert_to_u8(nc_i16 primitive) { return nc_new_u8(primitive.val); }
static inline nc_u16 nc_i16_convert_to_u16(nc_i16 primitive) { return nc_new_u16(primitive.val); }
static inline nc_u32 nc_i16_convert_to_u32(nc_i16 primitive) { return nc_new_u32(primitive.val); }
static inline nc_u64 nc_i16_convert_to_u64(nc_i16 primitive) { return nc_new_u64(primitive.val); }

/* nc_convert_i16_to_libc_primitive */
static inline int nc_i16_convert_to_int(nc_i16 primitive) { return primitive.val; }
static inline int8_t nc_i16_convert_to_int8_t(nc_i16 primitive) { return primitive.val; }
static inline uint8_t nc_i16_convert_to_uint8_t(nc_i16 primitive) { return primitive.val; }
static inline int16_t nc_i16_convert_to_int16_t(nc_i16 primitive) { return primitive.val; }
static inline uint16_t nc_i16_convert_to_uint16_t(nc_i16 primitive) { return primitive.val; }
static inline int32_t nc_i16_convert_to_int32_t(nc_i16 primitive) { return primitive.val; }
static inline uint32_t nc_i16_convert_to_uint32_t(nc_i16 primitive) { return primitive.val; }
static inline int64_t nc_i16_convert_to_int64_t(nc_i16 primitive) { return primitive.val; }
static inline uint64_t nc_i16_convert_to_uint64_t(nc_i16 primitive) { return primitive.val; }

/* nc_libc_primitive_convert_to_i16 */
static inline nc_i16 nc_int_convert_to_i16(int val) { return nc_new_i16(val); }
static inline nc_i16 nc_int8_t_convert_to_i16(int8_t val) { return nc_new_i16(val); }
static inline nc_i16 nc_uint8_t_convert_to_i16(uint8_t val) { return nc_new_i16(val); }
static inline nc_i16 nc_int16_t_convert_to_i16(int16_t val) { return nc_new_i16(val); }
static inline nc_i16 nc_uint16_t_convert_to_i16(uint16_t val) { return nc_new_i16(val); }
static inline nc_i16 nc_int32_t_convert_to_i16(int32_t val) { return nc_new_i16(val); }
static inline nc_i16 nc_uint32_t_convert_to_i16(uint32_t val) { return nc_new_i16(val); }
static inline nc_i16 nc_int64_t_convert_to_i16(int64_t val) { return nc_new_i16(val); }
static inline nc_i16 nc_uint64_t_convert_to_i16(uint64_t val) { return nc_new_i16((int64_t)val); }

/* nc_get_val */
static inline int16_t nc_get_val_i16(nc_i16 primitive) { return primitive.val; }

/* nc_get_size */
static inline size_t nc_get_size_i16() { return sizeof(nc_i16); }

#endif /* NC_I16_H */