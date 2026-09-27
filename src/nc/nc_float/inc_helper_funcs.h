/* src/nc/nc_float/inc_helper_funcs.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Helper Functions for NC integer primitives. Private, and is not meant to be used by users.
*/

#ifndef INC_FLOAT_HELPER_FUNCS_H
#define INC_FLOAT_HELPER_FUNCS_H

#include "../nc_log.h"
#include "nc_float_primitives.h"

#include <math.h>

typedef enum {
    ERROR_ISNAN,
    ERROR_ISINF,
} float_error_t;

static inline void send_float_error_constructor(
    int number_of_bits,
    float_error_t type_of_error,
    double error_val
) {
    nc_println_err("Float (%d) received an error of %s. Check value %lf if it is NaN or Inf. Defaulting to 0.0.",
        number_of_bits,
        (type_of_error == ERROR_ISNAN) ? "NaN" : "Inf",
        error_val
    );
}

static inline void send_float_error_must_constructor(
    int number_of_bits,
    float_error_t type_of_error,
    double error_val
) {
    nc_println_err("Float (%d) received an error of %s. Check value %lf if it is NaN or Inf. Exiting program.",
        number_of_bits,
        (type_of_error == ERROR_ISNAN) ? "NaN" : "Inf",
        error_val
    );
}

static inline void send_float_error(
    int number_of_bits,
    float_error_t type_of_error,
    double error_val_one,
    double error_val_two
) {
    nc_println_err("Float (%d) received an error of %s. Check value %lf or %lf if they're is NaN or Inf. Defaulting to 0.0",
        number_of_bits,
        (type_of_error == ERROR_ISNAN) ? "NaN" : "Inf",
        error_val_one,
        error_val_two
    );
}

static inline void send_float_error_overflow(
    int number_of_bits,
    double result
) {
    nc_println_err("Float (%d), with a value of %lf received an Inf error because it overflowed. Defaulting to 0.0.",
        number_of_bits,
        result
    );
}

static inline void send_float_zero_denominator_error_msg(
    double numerator,
    double denominator
) {
    nc_println_err("Error. Float was not allowed to be divided by 0.0. (Value received: %lf & %lf) Defaulting to 0.0.",
        numerator,
        denominator
    );
}

static inline nc_f32 inc_check_for_errs_f32(float number, nc_f32 previous_number_one, nc_f32 previous_number_two) {
    if (isnan(previous_number_one.val) || isnan(previous_number_two.val)) {
        send_float_error(32, ERROR_ISNAN, (double)previous_number_one.val, (double)previous_number_two.val);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(previous_number_one.val) || isinf(previous_number_two.val)) {
        send_float_error(32, ERROR_ISINF, (double)previous_number_one.val, (double)previous_number_two.val);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(number)) {
        send_float_error_overflow(32, (double)number);
        return (nc_f32){.val = 0.0};
    }

    return (nc_f32){.val = number};
}

static inline void inc_check_for_errs_must_f32(float number, nc_f32 previous_number_one, nc_f32 previous_number_two) {
    if (isnan(previous_number_one.val) || isnan(previous_number_two.val)) {
        send_float_error_must_constructor(32, ERROR_ISNAN, (double)previous_number_one.val);
        exit(EXIT_FAILURE);
    }

    if (isinf(previous_number_one.val) || isinf(previous_number_two.val)) {
        send_float_error_must_constructor(32, ERROR_ISINF, (double)previous_number_one.val);
        exit(EXIT_FAILURE);
    }

    if (isinf(number)) {
        send_float_error_overflow(32, (double)number);
        exit(EXIT_FAILURE);
    }
}

#endif /* INC_FLOAT_HELPER_FUNCS_H */