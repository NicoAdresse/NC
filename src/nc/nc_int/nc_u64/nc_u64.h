/* src/nc/nc_int/nc_u64/nc_u64.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_u64'.
*/

#ifndef NC_U64_H
#define NC_U64_H

#include <stdint.h>
#include <stdlib.h>

#include "../inc_helper_funcs.h"
#include "../nc_int_macros.h"
#include "../nc_types.h"
#include "../nc_int_constructors.h"

/* Checked Addition -> nc_u64 */
static inline nc_u64 nc_checked_add_u64(nc_u64 number_one, nc_u64 number_two) {
    uint64_t sum = number_one.val + number_two.val;

    if (sum < number_one.val) {
        send_constructor_error_msg(64, IS_UNSIGNED, ERROR_OVERFLOW, sum, NC_U64_MAX);
        return (nc_u64){.val = (uint64_t)NC_U64_MAX};
    }

    return (nc_u64){.val = sum};
}

/* Checked Subtraction -> nc_u64 */
static inline nc_u64 nc_checked_sub_u64(nc_u64 number_one, nc_u64 number_two) {
    if (number_two.val > number_one.val) {
        send_bounds_error_msg(64, IS_UNSIGNED, number_one.val, number_two.val, ERROR_UNDERFLOW, NC_UNSIGNED_MIN);
        return (nc_u64){.val = (uint64_t)NC_UNSIGNED_MIN};
    }

    uint64_t diff = number_one.val - number_two.val;
    return (nc_u64){.val = diff};
}

/* Checked Multiplication -> nc_u64 */
static inline nc_u64 nc_checked_mul_u64(nc_u64 number_one, nc_u64 number_two) {
    if (number_one.val != 0 && number_two.val > NC_U64_MAX / number_one.val) {
        send_bounds_error_msg(64, IS_UNSIGNED, number_one.val, number_two.val, ERROR_OVERFLOW, NC_U64_MAX);
        return (nc_u64){.val = (uint64_t)NC_U64_MAX};
    }

    uint64_t product = number_one.val * number_two.val;
    return (nc_u64){.val = product};
}

/* Checked Division -> nc_u64 */
static inline nc_u64 nc_checked_div_u64(nc_u64 number_one, nc_u64 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_UNSIGNED, number_one.val, number_two.val);
        }
        return (nc_u64){.val = 0};
    }

    uint64_t quotient = number_one.val / number_two.val;
    return (nc_u64){.val = quotient};
}

/* Checked Modulo -> nc_u64 */
static inline nc_u64 nc_checked_mod_u64(nc_u64 number_one, nc_u64 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_UNSIGNED, (uint64_t)number_one.val, (uint64_t)number_two.val);
            return (nc_u64){.val = 0};
        } 
        return (nc_u64){.val = 0};
    }

    uint64_t remainder = (uint64_t)number_one.val % (uint64_t)number_two.val;
    return (nc_u64){.val = (uint64_t)remainder};
}

/* nc_u64_convert_to */
static inline nc_i8 nc_u64_convert_to_i8(nc_u64 primitive) { return nc_new_i8(primitive.val); }
static inline nc_i16 nc_u64_convert_to_i16(nc_u64 primitive) { return nc_new_i16(primitive.val); }
static inline nc_i32 nc_u64_convert_to_i32(nc_u64 primitive) { return nc_new_i32(primitive.val); }
static inline nc_i64 nc_u64_convert_to_i64(nc_u64 primitive) { return nc_new_i64(primitive.val); }
static inline nc_u8 nc_u64_convert_to_u8(nc_u64 primitive) { return nc_new_u8(primitive.val); }
static inline nc_u16 nc_u64_convert_to_u16(nc_u64 primitive) { return nc_new_u16(primitive.val); }
static inline nc_u32 nc_u64_convert_to_u32(nc_u64 primitive) { return (nc_u32){.val = primitive.val}; }

/* nc_convert_u64_to_libc_primitive */
static inline int nc_u64_convert_to_int(nc_u64 primitive) { return primitive.val; }
static inline int8_t nc_u64_convert_to_int8_t(nc_u64 primitive) { return primitive.val; }
static inline uint8_t nc_u64_convert_to_uint8_t(nc_u64 primitive) { return primitive.val; }
static inline int16_t nc_u64_convert_to_int16_t(nc_u64 primitive) { return primitive.val; }
static inline uint16_t nc_u64_convert_to_uint16_t(nc_u64 primitive) { return primitive.val; }
static inline int32_t nc_u64_convert_to_int32_t(nc_u64 primitive) { return primitive.val; }
static inline uint32_t nc_u64_convert_to_uint32_t(nc_u64 primitive) { return primitive.val; }
static inline int64_t nc_u64_convert_to_int64_t(nc_u64 primitive) { return primitive.val; }
static inline uint64_t nc_u64_convert_to_uint64_t(nc_u64 primitive) { return primitive.val; }

/* nc_libc_primitive_convert_to_u64 */
static inline nc_u64 nc_int_convert_to_u64(int val) { return nc_new_u64(val); }
static inline nc_u64 nc_int8_t_convert_to_u64(int8_t val) { return nc_new_u64(val); }
static inline nc_u64 nc_uint8_t_convert_to_u64(uint8_t val) { return nc_new_u64(val); }
static inline nc_u64 nc_int16_t_convert_to_u64(int16_t val) { return nc_new_u64(val); }
static inline nc_u64 nc_uint16_t_convert_to_u64(uint16_t val) { return nc_new_u64(val); }
static inline nc_u64 nc_int32_t_convert_to_u64(int32_t val) { return nc_new_u64(val); }
static inline nc_u64 nc_uint32_t_convert_to_u64(uint32_t val) { return nc_new_u64(val); }
static inline nc_u64 nc_int64_t_convert_to_u64(int64_t val) { return nc_new_u64(val); }
static inline nc_u64 nc_uint64_t_convert_to_u64(uint64_t val) { return nc_new_u64(val); }

/* nc_get_val */
static inline uint64_t nc_get_val_u64(nc_u64 primitive) { return primitive.val; }

/* nc_get_size */
static inline size_t nc_get_size_u64() { return sizeof(nc_u64); }

/* nc_get_signum */
static inline nc_u64 nc_signum_u64(nc_u64 val) {
    return (nc_u64){.val = (val.val > 0)};
}

#endif /* NC_U64_H */