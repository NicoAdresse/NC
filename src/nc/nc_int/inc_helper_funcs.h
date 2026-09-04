/* src/nc/nc_int/inc_helper_funcs.h */

/*
    About: Header file for helper functions.
    Initial Commit: NC_INT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

/* NOT MEANT TO BE PUBLIC FOR USERS TO USE. */

#ifndef INC_HELPER_FUNCS_H
#define INC_HELPER_FUNCS_H

#include <stdint.h>
#include "../nc_log.h"

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
    error_int_bound_t overflow_type,
    int64_t bounds_max
) {
    println_err(
        "Error. %s Integer (%d Bits) %s detected. Check your variables. (Values received: %lld & %lld). Defaulting to %lld.",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (overflow_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        (long long)number_one_val,
        (long long)number_two_val,
        (long long)bounds_max
    );
}

static inline void send_constructor_error_msg(
    int number_of_bits,
    int is_integer_signed,
    error_int_bound_t overflow_type,
    int64_t val,
    int64_t bounds_max
) {
    println_err(
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
    error_int_bound_t overflow_type,
    int64_t val
) {
    println_err(
        "Error. %s Integer (%d Bits) %s detected. Construction failed. The Runtime will hereby be terminated (Value Received: %lld).",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (overflow_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        (long long)val
    );
}

static inline void send_zero_denominator_error_msg(
    int is_integer_signed,
    int64_t numerator,
    int64_t denominator
) {
    println_err(
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
    println_err(
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
    println_err(
        "Error. %s Integer (%s) failed to allocate %lld bytes. Automatically exiting. (Hint: You don't get a memory leak.).",
        is_integer_signed ? "Signed" : "Unsigned",
        type_of_primitive,
        amount_of_bytes_allocated
    );
}

#endif /* INC_HELPER_FUNCS_H */