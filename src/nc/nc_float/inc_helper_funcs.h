/* src/nc/nc_float/inc_helper_funcs.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Helper Functions for NC integer primitives. Private, and is not meant to be used by users.
*/

#ifndef INC_FLOAT_HELPER_FUNCS_H
#define INC_FLOAT_HELPER_FUNCS_H

#include "../nc_log.h"

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

#endif /* INC_FLOAT_HELPER_FUNCS_H */