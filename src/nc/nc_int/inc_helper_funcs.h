/* src/nc/nc_int/inc_helper_funcs.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Helper Functions for NC integer primitives. Private, and is not meant to be used by users.
*/

#ifndef INC_INT_HELPER_FUNCS_H
#define INC_INT_HELPER_FUNCS_H

#include <stdint.h>
#include <stdlib.h>
#include "../nc_log.h"
#include "nc_int_macros.h"

typedef enum {
    ERROR_OVERFLOW,
    ERROR_UNDERFLOW
} error_int_bound_t;

static inline int check_overflow(int64_t val, int64_t max) { return val > max; }
static inline int check_underflow(int64_t val, int64_t min) { return val < min; }
static inline int check_overflow_for_u64(uint64_t val, uint64_t max) { return val > max; }
static inline int check_underflow_for_u64(uint64_t val, uint64_t min) { return val < min; }

static inline void send_bounds_error_msg(
    int number_of_bits,
    int is_integer_signed,
    int64_t number_one_val,
    int64_t number_two_val,
    error_int_bound_t bound_err_type,
    int64_t bounds_max
) {
    nc_println_err(
        "Error. %s Integer (%d Bits) %s detected. Check your variables. (Values received: %lld & %lld). Defaulting to %lld.",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (bound_err_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        (long long)number_one_val,
        (long long)number_two_val,
        (long long)bounds_max
    );
}

static inline void send_bounds_must_error_msg(
    int number_of_bits,
    int is_integer_signed,
    int64_t number_one_val,
    int64_t number_two_val,
    error_int_bound_t bound_err_type,
    int64_t bounds_max
) {
    nc_println_err(
        "Error. %s Integer (%d Bits) %s detected. Check your variables. (Values received: %lld & %lld). Exiting with error code of 1.",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (bound_err_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        (long long)number_one_val,
        (long long)number_two_val,
        (long long)bounds_max
    );
}

static inline void send_bounds_ptr_error_msg(
    int number_of_bits,
    int is_integer_signed,
    int64_t number_one_val,
    int64_t number_two_val,
    error_int_bound_t bound_err_type,
    int64_t bounds_max
) {
    nc_println_err(
        "Error. %s Pointer Integer (%d bits) %s detected. Check your variables. (Values received: %lld & %lld). Defaulting to %lld.",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (bound_err_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        (long long)number_one_val,
        (long long)number_two_val,
        bounds_max
    );
}

static inline void send_constructor_error_msg(
    int number_of_bits,
    int is_integer_signed,
    error_int_bound_t overflow_type,
    int64_t val,
    int64_t bounds_max
) {
    nc_println_err(
        "Error. %s Integer (%d Bits) %s detected. Construction failed. (Value received: %lld). Defaulting to %lld.",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (overflow_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        (long long)val,
        (long long)bounds_max
    );
}

static inline void send_constructor_runtime_fail_error_msg(
    int number_of_bits,
    int is_integer_signed,
    error_int_bound_t bound_err_type,
    int64_t val
) {
    nc_println_err(
        "Error. %s Integer (%d Bits) %s detected. Construction failed. The Runtime will hereby be terminated (Value Received: %lld).",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (bound_err_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        (long long)val
    );
}

static inline void send_zero_denominator_error_msg(
    int is_integer_signed,
    int64_t numerator,
    int64_t denominator
) {
    nc_println_err(
        "Error. %s Integer was not allowed to be divided by 0. (Value received: %lld & %lld) Defaulting to 0.",
        is_integer_signed ? "Signed" : "Unsigned",
        (long long)numerator,
        (long long)denominator
    );
}

static inline void send_allocation_error_msg(
    int is_integer_signed,
    long long amount_of_bytes_allocated,
    char* type_of_primitive
) {
    nc_println_err(
        "Error. %s Integer (%s) failed to allocate %lld bytes. Setting pointer to NULL.",
        is_integer_signed ? "Signed" : "Unsigned",
        type_of_primitive,
        amount_of_bytes_allocated
    );
}

static inline void send_allocation_must_error_msg(
    int is_integer_signed,
    long long amount_of_bytes_allocated,
    char* type_of_primitive
) {
    nc_println_err(
        "Error. %s Integer (%s) failed to allocate %lld bytes. Automatically exiting. (Hint: You don't get a memory leak.).",
        is_integer_signed ? "Signed" : "Unsigned",
        type_of_primitive,
        amount_of_bytes_allocated
    );
}

static inline void send_null_pointer_error_msg(
    int is_integer_signed,
    char* type_of_primitive
) {
    nc_println_err(
        "Error. Attempted to deference a null pointer of a %s integer (%s).",
        is_integer_signed ? "signed" : "unsigned",
        type_of_primitive
    );
}

/*
    If Successful: returns the result of the operation as nc_i8.
    If Overflow: returns NC_I8_MAX and sends an error message to stderr.
    If Underflow: returns NC_I8_MIN and sends an error message to stderr.
    Must equivalent functions will exit the program if an error occurs.
*/
static inline nc_i8 inc_check_for_bound_errs_i8(int64_t number, nc_i8 previous_number_one, nc_i8 previous_number_two) {
    if (check_overflow(number, NC_I8_MAX)) {
        send_bounds_error_msg(8, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_OVERFLOW, NC_I8_MAX);
        return (nc_i8){.val = NC_I8_MAX};
    }

    if (check_underflow(number, NC_I8_MIN)) {
        send_bounds_error_msg(8, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_UNDERFLOW, NC_I8_MIN);
        return (nc_i8){.val = (int8_t)NC_I8_MIN};
    }

    return (nc_i8){.val = (int8_t)number};
}

static inline void inc_check_for_bound_must_errs_i8(int64_t number, nc_i8 previous_number_one, nc_i8 previous_number_two) {
    if (check_overflow(number, NC_I8_MAX)) {
        send_bounds_must_error_msg(8, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_OVERFLOW, NC_I8_MAX);
        exit(EXIT_FAILURE);
    }

    if (check_underflow(number, NC_I8_MIN)) {
        send_bounds_must_error_msg(8, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_UNDERFLOW, NC_I8_MIN);
        exit(EXIT_FAILURE);
    }
}

static inline nc_i16 inc_check_for_bound_errs_i16(int64_t number, nc_i16 previous_number_one, nc_i16 previous_number_two) {
    if (check_overflow(number, NC_I16_MAX)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_OVERFLOW, NC_I16_MAX);
        return (nc_i16){.val = NC_I16_MAX};
    }

    if (check_underflow(number, NC_I16_MIN)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_UNDERFLOW, NC_I16_MIN);
        return (nc_i16){.val = (int16_t)NC_I16_MIN};
    }

    return (nc_i16){.val = (int16_t)number};
}

static inline void inc_check_for_bound_must_errs_i16(int64_t number, nc_i16 previous_number_one, nc_i16 previous_number_two) {
    if (check_overflow(number, NC_I16_MAX)) {
        send_bounds_must_error_msg(16, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_OVERFLOW, NC_I16_MAX);
        exit(EXIT_FAILURE);
    }

    if (check_underflow(number, NC_I16_MIN)) {
        send_bounds_must_error_msg(16, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_UNDERFLOW, NC_I16_MIN);
        exit(EXIT_FAILURE);
    }
}

static inline nc_i32 inc_check_for_bound_errs_i32(int64_t number, nc_i32 previous_number_one, nc_i32 previous_number_two) {
    if (check_overflow(number, NC_I32_MAX)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_OVERFLOW, NC_I32_MAX);
        return (nc_i32){.val = NC_I32_MAX};
    }

    if (check_underflow(number, NC_I32_MIN)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_UNDERFLOW, NC_I32_MIN);
        return (nc_i32){.val = (int32_t)NC_I32_MIN};
    }

    return (nc_i32){.val = (int32_t)number};
}

static inline void inc_check_for_bound_must_errs_i32(int64_t number, nc_i32 previous_number_one, nc_i32 previous_number_two) {
    if (check_overflow(number, NC_I32_MAX)) {
        send_bounds_must_error_msg(32, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_OVERFLOW, NC_I32_MAX);
        exit(EXIT_FAILURE);
    }

    if (check_underflow(number, NC_I32_MIN)) {
        send_bounds_must_error_msg(32, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_UNDERFLOW, NC_I32_MIN);
        exit(EXIT_FAILURE);
    }
}

static inline nc_i64 inc_check_for_bound_errs_i64(int64_t number, nc_i64 previous_number_one, nc_i64 previous_number_two) {
    if (number > NC_I64_MAX) {
        send_bounds_error_msg(64, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (number < NC_I64_MIN) {
        send_bounds_error_msg(64, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

    return (nc_i64){.val = (int64_t)number};
}

static inline void inc_check_for_bound_must_errs_i64(int64_t number, nc_i64 previous_number_one, nc_i64 previous_number_two) {
    if (number > NC_I64_MAX) {
        send_bounds_must_error_msg(64, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        exit(EXIT_FAILURE);
    }

    if (number < NC_I64_MIN) {
        send_bounds_must_error_msg(64, IS_SIGNED, (int64_t)previous_number_one.val, (int64_t)previous_number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        exit(EXIT_FAILURE);
    }
}

static inline nc_i64 inc_check_for_bound_errs_i64_mul(__int128_t number, nc_i64 previous_number_one, nc_i64 previous_number_two) {
    if (number > NC_I64_MAX) {
        send_bounds_error_msg(64, IS_SIGNED, previous_number_one.val, previous_number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (number < NC_I64_MIN) {
        send_bounds_error_msg(64, IS_SIGNED, previous_number_one.val, previous_number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

    return (nc_i64){.val = (int64_t)number};
}

static inline void inc_check_for_bound_must_errs_i64_mul(__int128_t number, nc_i64 previous_number_one, nc_i64 previous_number_two) {
    if (number > NC_I64_MAX) {
        send_bounds_must_error_msg(64, IS_SIGNED, previous_number_one.val, previous_number_two.val, ERROR_OVERFLOW, NC_I64_MAX);
        exit(EXIT_FAILURE);
    }

    if (number < NC_I64_MIN) {
        send_bounds_must_error_msg(64, IS_SIGNED, previous_number_one.val, previous_number_two.val, ERROR_UNDERFLOW, NC_I64_MIN);
        exit(EXIT_FAILURE);
    }
}

static inline nc_u8 inc_check_for_bound_errs_u8(uint64_t number, nc_u8 previous_number_one, nc_u8 previous_number_two) {
    if (check_overflow(number, NC_U8_MAX)) {
        send_bounds_error_msg(8, IS_UNSIGNED, (uint64_t)previous_number_one.val, (uint64_t)previous_number_two.val, ERROR_OVERFLOW, NC_U8_MAX);
        return (nc_u8){.val = NC_U8_MAX};
    }

    return (nc_u8){.val = (uint8_t)number};
}

static inline void inc_check_for_bound_must_errs_u8(uint64_t number, nc_u8 previous_number_one, nc_u8 previous_number_two) {
    if (check_overflow(number, NC_U8_MAX)) {
        send_bounds_must_error_msg(8, IS_UNSIGNED, (uint64_t)previous_number_one.val, (uint64_t)previous_number_two.val, ERROR_OVERFLOW, NC_U8_MAX);
        exit(EXIT_FAILURE);
    }
}

static inline nc_u16 inc_check_for_bound_errs_u16(uint64_t number, nc_u16 previous_number_one, nc_u16 previous_number_two) {
    if (check_overflow(number, NC_U16_MAX)) {
        send_bounds_error_msg(16, IS_UNSIGNED, (uint64_t)previous_number_one.val, (uint64_t)previous_number_two.val, ERROR_OVERFLOW, NC_U16_MAX);
        return (nc_u16){.val = (uint16_t)NC_U16_MAX};  
    }

    return (nc_u16){.val = (uint16_t)number};
}

static inline void inc_check_for_bound_must_errs_u16(uint16_t number, nc_u16 previous_number_one, nc_u16 previous_number_two) {
    if (check_overflow(number, NC_U16_MAX)) {
        send_bounds_must_error_msg(16, IS_UNSIGNED, (uint64_t)previous_number_one.val, (uint64_t)previous_number_two.val, ERROR_OVERFLOW, NC_U16_MAX);
        exit(EXIT_FAILURE);
    }
}

static inline nc_u32 inc_check_for_bound_errs_u32(uint64_t number, nc_u32 previous_number_one, nc_u32 previous_number_two) {
    if (check_overflow(number, NC_U32_MAX)) {
        send_bounds_error_msg(32, IS_UNSIGNED, (uint64_t)previous_number_one.val, (uint64_t)previous_number_two.val, ERROR_OVERFLOW, NC_U32_MAX);
        return (nc_u32){.val = (uint32_t)NC_U32_MAX};
    }

    return (nc_u32){.val = (uint32_t)number};
}

static inline void inc_check_for_bound_must_errs_u32(uint64_t number, nc_u32 previous_number_one, nc_u32 previous_number_two) {
    if (check_overflow(number, NC_U32_MAX)) {
        send_bounds_must_error_msg(32, IS_UNSIGNED, (uint64_t)previous_number_one.val, (uint64_t)previous_number_two.val, ERROR_OVERFLOW, NC_U32_MAX);
        exit(EXIT_FAILURE);
    }
}

static inline nc_u64 inc_check_for_bound_errs_u64(__uint128_t number, nc_u64 previous_number_one, nc_u64 previous_number_two) {
    if (check_overflow(number, NC_U64_MAX)) {
        send_bounds_error_msg(64, IS_UNSIGNED, (uint64_t)previous_number_one.val, (uint64_t)previous_number_two.val, ERROR_OVERFLOW, NC_U64_MAX);
        return (nc_u64){.val = NC_U64_MAX};
    }

    return (nc_u64){.val = (uint64_t)number};
}

static inline void inc_check_for_bound_must_errs_u64(__uint128_t number, nc_u64 previous_number_one, nc_u64 previous_number_two) {
    if (check_overflow(number, NC_U64_MAX)) {
        send_bounds_error_msg(64, IS_UNSIGNED, (uint64_t)previous_number_one.val, (uint64_t)previous_number_two.val, ERROR_OVERFLOW, NC_U64_MAX);
        exit(EXIT_FAILURE);
    }
}

#endif /* INC_INT_HELPER_FUNCS_H */