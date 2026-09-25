/* src/nc/nc_float/nc_float_constructors.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Constructors for NC float primitives.
*/

#ifndef NC_FLOAT_CONSTRUCTORS_H
#define NC_FLOAT_CONSTRUCTORS_H

#include "inc_helper_funcs.h"
#include "nc_float_primitives.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

/* nc_f32's constructor */
static inline nc_f32 nc_new_f32(double val) {
    if (isnan(val)) {
        send_float_error_constructor(32, ERROR_ISNAN, val);
        return (nc_f32){.val = 0.0};
    }

    if (isinf(val)) {
        send_float_error_constructor(32, ERROR_ISINF, val);
        return (nc_f32){.val = 0.0};
    }

    float converted = (float)val;

    if (isinf(converted)) {
        send_float_error_constructor(32, ERROR_ISINF, (double)val);
        return (nc_f32){.val = 0.0};
    }

    return (nc_f32){.val = converted};
}

/* nc_f32's runtime fail constructor */
static inline nc_f32 nc_new_must_f32(double val) {
    if (isnan(val)) {
        float converted = (float)val; 
        uint32_t bits = 0;
        memcpy(&bits, &converted, sizeof(converted));
        send_float_error_must_constructor(32, ERROR_ISNAN, bits);
        exit(1);
    }

    if (isinf(val)) {
        float converted = (float)val;
        uint32_t bits = 0;
        memcpy(&bits, &converted, sizeof(converted));
        send_float_error_must_constructor(32, ERROR_ISINF, bits);
        exit(1);
    }

    float converted = (float)val;

    if (isinf(converted)) {
        uint32_t bits = 0;
        memcpy(&bits, &converted, sizeof(converted));
        send_float_error_must_constructor(32, ERROR_ISINF, bits);
        exit(1);
    }

    return (nc_f32){.val = converted};
}

/* nc_f64's constructor */
static inline nc_f64 nc_new_f64(double val) {
    if (isnan(val)) {
        send_float_error_constructor(64, ERROR_ISNAN, val);
        return (nc_f64){.val = 0.0};
    }

    if (isinf(val)) {
        send_float_error_constructor(64, ERROR_ISINF, val);
        return (nc_f64){.val = 0.0};
    }

    return (nc_f64){.val = val};
}

/* nc_f64's runtime fail constructor */
static inline nc_f64 nc_new_must_f64(double val) {
    if (isnan(val)) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(64, ERROR_ISNAN, bits);
        exit(1);
    }

    if (isinf(val)) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(64, ERROR_ISINF, bits);
        exit(1);
    }

    return (nc_f64){.val = val};
}

/* nc_ptr_f32's constructor */
static inline nc_ptr_f32 nc_new_ptr_f32(double val) {
    if (isnan(val)) {
        send_float_error_constructor(32, ERROR_ISNAN, val);
        return (nc_ptr_f32){.val = NULL};
    }

    if (isinf(val)) {
        send_float_error_constructor(32, ERROR_ISINF, val);
        return (nc_ptr_f32){.val = NULL};
    }

    float* converted = malloc(sizeof(float));
    if (!converted) {
        return (nc_ptr_f32){.val = NULL};
    }

    *converted = (float)val;

    if (isinf(*converted)) {
        send_float_error_constructor(32, ERROR_ISINF, val);
        free(converted);
        return (nc_ptr_f32){.val = NULL};
    }

    return (nc_ptr_f32){.val = (nc_f32*)converted};
}

/* nc_ptr_f32's runtime fail constructor */
static inline nc_ptr_f32 nc_new_must_ptr_f32(double val) {
    if (isnan(val)) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(32, ERROR_ISNAN, bits);
        exit(1);
    }

    if (isinf(val)) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(32, ERROR_ISINF, bits);
        exit(1);
    }

    float* coverted = malloc(sizeof(float));
    if (!coverted) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(32, ERROR_ISINF, bits);
        exit(1);
    }

    *coverted = (float)val;

    if (isinf(val)) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(32, ERROR_ISINF, bits);
        exit(1);
    }

    return (nc_ptr_f32){.val = (nc_f32*)coverted};
}

/* nc_ptr_f64's constructor */
static inline nc_ptr_f64 nc_new_ptr_f64(double val) {
    if (isnan(val)) {
        send_float_error_constructor(64, ERROR_ISNAN, val);
        return (nc_ptr_f64){.val = NULL};
    }

    if (isinf(val)) {
        send_float_error_constructor(64, ERROR_ISINF, val);
        return (nc_ptr_f64){.val = NULL};
    }

    double* converted = malloc(sizeof(double));
    if (!converted) {
        return (nc_ptr_f64){.val = NULL};
    }

    *converted = val;

    if (isinf(*converted)) {
        send_float_error_constructor(64, ERROR_ISINF, val);
        free(converted);
        return (nc_ptr_f64){.val = NULL};
    }

    return (nc_ptr_f64){.val = (nc_f64*)converted};
}

/* nc_ptr_f64's runtime fail constructor */
static inline nc_ptr_f64 nc_new_must_ptr_f64(double val) {
    if (isnan(val)) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(64, ERROR_ISNAN, bits);
        exit(1);
    }

    if (isinf(val)) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(64, ERROR_ISINF, bits);
        exit(1);
    }

    double* coverted = malloc(sizeof(double));
    if (!coverted) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(64, ERROR_ISINF, bits);
        exit(1);
    }

    *coverted = val;

    if (isinf(val)) {
        uint64_t bits = 0;
        memcpy(&bits, &val, sizeof(val));
        send_float_error_must_constructor(64, ERROR_ISINF, bits);
        exit(1);
    }

    return (nc_ptr_f64){.val = (nc_f64*)coverted};
}

#endif /* NC_FLOAT_CONSTRUCTORS_H */