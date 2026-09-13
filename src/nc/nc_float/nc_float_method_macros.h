/* src/nc/nc_float/nc_float_method_macros.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Constructors for NC float primitives.
*/

#ifndef NC_FLOAT_METHOD_MACROS_H
#define NC_FLOAT_METHOD_MACROS_H

#include "nc_float_primitives.h"
#include "nc_float_constructors.h"

#include "nc_f32/nc_f32.h"
#include "nc_f64/nc_f64.h"

#define nc_checked_add_float(n1, n2) _Generic((n1), \
    nc_f32: nc_checked_add_f32, \
    nc_f64: nc_checked_add_f64, \
    default: nc_checked_add_f32 \
)((n1), (n2))

#define nc_checked_sub_float(n1, n2) _Generic((n1), \
    nc_f32: nc_checked_sub_f32, \
    nc_f64: nc_checked_sub_f64, \
    default: nc_checked_sub_f32 \
)((n1), (n2))

#define nc_checked_mul_float(n1, n2) _Generic((n1), \
    nc_f32: nc_checked_mul_f32, \
    nc_f64: nc_checked_mul_f64, \
    default: nc_checked_mul_f32 \
)((n1), (n2))

#define nc_checked_div_float(n1, n2, is_zero_division_allowed) _Generic((n1), \
    nc_f32: nc_checked_div_f32, \
    nc_f64: nc_checked_div_f64, \
    default: nc_checked_div_f32 \
)((n1), (n2), (is_zero_division_allowed))

#define nc_checked_mod_float(n1, n2, is_zero_division_allowed) _Generic((n1), \
    nc_f32: nc_checked_mod_f32, \
    nc_f64: nc_checked_mod_f64, \
    default: nc_checked_mod_f32 \
)((n1), (n2), (is_zero_division_allowed))

#define nc_checked_signum_float(n) _Generic((n), \
    nc_f32: nc_checked_signum_f32, \
    nc_f64: nc_checked_signum_f64, \
    default: nc_checked_signum_f32 \
)((n))

#define nc_get_size_float(n) _Generic((n), \
    nc_f32: nc_get_size_f32, \
    nc_f64: nc_get_size_f64, \
    default: nc_get_size_f32 \
)()

#define nc_get_val_float(n) _Generic((n), \
    nc_f32: nc_get_val_f32, \
    nc_f64: nc_get_val_f64, \
    default: nc_get_val_f32 \
)((n))

#endif /* NC_FLOAT_METHOD_MACROS_H */