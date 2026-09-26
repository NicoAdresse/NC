/* src/nc/nc_int/nc_u16/nc_u16.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Header file for the primitive datatype 'nc_u16'.
*/

#ifndef NC_U16_H
#define NC_U16_H

#include <stdint.h>
#include <stdlib.h>

#include "../nc_int_macros.h"
#include "../inc_helper_funcs.h"
#include "../nc_types.h"
#include "../nc_int_constructors.h"

/* Checked Addition -> nc_u16 */
static inline nc_u16 nc_checked_add_u16(nc_u16 number_one, nc_u16 number_two) {
    uint64_t sum = (uint64_t)number_one.val + (uint64_t)number_two.val;
    return inc_check_for_bound_errs_u16(sum, number_one, number_two);
}

/* Checked Must Addition -> nc_u16 */
static inline nc_u16 nc_checked_add_must_u16(nc_u16 number_one, nc_u16 number_two) {
    uint64_t sum = (uint64_t)number_one.val + (uint64_t)number_two.val;
    inc_check_for_bound_must_errs_u16(sum, number_one, number_two);
    return (nc_u16){.val = (uint16_t)sum};
}

/* Checked Subtraction -> nc_u16 */
static inline nc_u16 nc_checked_sub_u16(nc_u16 number_one, nc_u16 number_two) {
    uint64_t diff = (uint64_t)number_one.val - (uint64_t)number_two.val;
    return inc_check_for_bound_errs_u16(diff, number_one, number_two);
}

/* Checked Must Subtraction -> nc_u16 */
static inline nc_u16 nc_checked_sub_must_u16(nc_u16 number_one, nc_u16 number_two) {
    uint64_t diff = (uint64_t)number_one.val - (uint64_t)number_two.val;
    inc_check_for_bound_must_errs_u16(diff, number_one, number_two);
    return (nc_u16){.val = (uint16_t)diff};
}

/* Checked Multiplication -> nc_u16 */
static inline nc_u16 nc_checked_mul_u16(nc_u16 number_one, nc_u16 number_two) {
    uint64_t product = (uint64_t)number_one.val * (uint64_t)number_two.val;
    return inc_check_for_bound_errs_u16(product, number_one, number_two);
}

/* Checked Must Multiplication -> nc_u16 */
static inline nc_u16 nc_checked_mul_must_u16(nc_u16 number_one, nc_u16 number_two) {
    uint64_t product = (uint64_t)number_one.val * (uint64_t)number_two.val;
    inc_check_for_bound_must_errs_u16(product, number_one, number_two);
    return (nc_u16){.val = (uint16_t)product};
}

/* Checked Division -> nc_u16 */
static inline nc_u16 nc_checked_div_u16(nc_u16 number_one, nc_u16 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_UNSIGNED, (uint64_t)number_one.val, (uint64_t)number_two.val);
            return (nc_u16){.val = 0};
        }
        return (nc_u16){.val = 0};
    }

    uint64_t quotient = (uint64_t)number_one.val / (uint64_t)number_two.val;
    return inc_check_for_bound_errs_u16(quotient, number_one, number_two);
}

/* Checked Must Division -> nc_u16 */
static inline nc_u16 nc_checked_div_must_u16(nc_u16 number_one, nc_u16 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_UNSIGNED, (uint64_t)number_one.val, (uint64_t)number_two.val);
            exit(EXIT_FAILURE);
        }
        return (nc_u16){.val = 0};
    }

    uint64_t quotient = (uint64_t)number_one.val / (uint64_t)number_two.val;
    inc_check_for_bound_must_errs_u16(quotient, number_one, number_two);
    return (nc_u16){.val = (uint16_t)quotient};
}

/* Checked Modulo -> nc_u16 */
static inline nc_u16 nc_checked_mod_u16(nc_u16 number_one, nc_u16 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_UNSIGNED, (uint64_t)number_one.val, (uint64_t)number_two.val);
            return (nc_u16){.val = 0};
        } 
        return (nc_u16){.val = 0};
    }

    uint64_t remainder = (uint64_t)number_one.val % (uint64_t)number_two.val;
    return (nc_u16){.val = (uint16_t)remainder};
}

/* Checked Must Modulo -> nc_u16 */
static inline nc_u16 nc_checked_mod_must_u16(nc_u16 number_one, nc_u16 number_two, int is_zero_denominator_allowed) {
    if (number_two.val == 0) {
        if (!is_zero_denominator_allowed) {
            send_zero_denominator_error_msg(IS_UNSIGNED, (uint64_t)number_one.val, (uint64_t)number_two.val);
            exit(EXIT_FAILURE);
        } 
        return (nc_u16){.val = 0};
    }

    uint64_t remainder = (uint64_t)number_one.val % (uint64_t)number_two.val;
    return (nc_u16){.val = (uint16_t)remainder};
}

/* nc_u16_convert_to */
static inline nc_i8 nc_u16_convert_to_i8(nc_u16 primitive) { return nc_new_i8(primitive.val); }
static inline nc_i16 nc_u16_convert_to_i16(nc_u16 primitive) { return nc_new_i16(primitive.val); }
static inline nc_i32 nc_u16_convert_to_i32(nc_u16 primitive) { return nc_new_i32(primitive.val); }
static inline nc_i64 nc_u16_convert_to_i64(nc_u16 primitive) { return nc_new_i64(primitive.val); }
static inline nc_u8 nc_u16_convert_to_u8(nc_u16 primitive) { return nc_new_u8(primitive.val); }
static inline nc_u32 nc_u16_convert_to_u32(nc_u16 primitive) { return nc_new_u32(primitive.val); }
static inline nc_u64 nc_u16_convert_to_u64(nc_u16 primitive) { return nc_new_u64(primitive.val); }

/* nc_convert_u16_to_libc_primitive */
static inline int nc_u16_convert_to_int(nc_u16 primitive) { return primitive.val; }
static inline int8_t nc_u16_convert_to_int8_t(nc_u16 primitive) { return primitive.val; }
static inline uint8_t nc_u16_convert_to_uint8_t(nc_u16 primitive) { return primitive.val; }
static inline int16_t nc_u16_convert_to_int16_t(nc_u16 primitive) { return primitive.val; }
static inline uint16_t nc_u16_convert_to_uint16_t(nc_u16 primitive) { return primitive.val; }
static inline int32_t nc_u16_convert_to_int32_t(nc_u16 primitive) { return primitive.val; }
static inline uint32_t nc_u16_convert_to_uint32_t(nc_u16 primitive) { return primitive.val; }
static inline int64_t nc_u16_convert_to_int64_t(nc_u16 primitive) { return primitive.val; }
static inline uint64_t nc_u16_convert_to_uint64_t(nc_u16 primitive) { return primitive.val; }

/* nc_libc_primitive_convert_to_u16 */
static inline nc_u16 nc_int_convert_to_u16(int val) { return nc_new_u16(val); }
static inline nc_u16 nc_int8_t_convert_to_u16(int8_t val) { return nc_new_u16(val); }
static inline nc_u16 nc_uint8_t_convert_to_u16(uint8_t val) { return nc_new_u16(val); }
static inline nc_u16 nc_int16_t_convert_to_u16(int16_t val) { return nc_new_u16(val); }
static inline nc_u16 nc_uint16_t_convert_to_u16(uint16_t val) { return nc_new_u16(val); }
static inline nc_u16 nc_int32_t_convert_to_u16(int32_t val) { return nc_new_u16(val); }
static inline nc_u16 nc_uint32_t_convert_to_u16(uint32_t val) { return nc_new_u16(val); }
static inline nc_u16 nc_int64_t_convert_to_u16(int64_t val) { return nc_new_u16(val); }
static inline nc_u16 nc_uint64_t_convert_to_u16(uint64_t val) { return nc_new_u16((int64_t)val); }

/* nc_get_val */
static inline uint16_t nc_get_val_u16(nc_u16 primitive) { return primitive.val; }

/* nc_get_size */
static inline size_t nc_get_size_u16() { return sizeof(nc_u16); }

/* nc_get_signum */
static inline nc_u16 nc_signum_u16(nc_u16 val) {
    return (nc_u16){.val = (val.val > 0)};
}

#endif /* NC_U16_H */