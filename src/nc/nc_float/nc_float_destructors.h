/* src/nc/nc_float/nc_float_destructors.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Destructors for NC float primitives.
*/

#ifndef NC_FLOAT_DESTRUCTORS_H
#define NC_FLOAT_DESTRUCTORS_H

#include <stdlib.h>

#include "nc_float_primitives.h"

static inline void nc_free_ptr_f32(nc_ptr_f32 ptr) { free(ptr.val); }
static inline void nc_free_ptr_f64(nc_ptr_f64 ptr) { free(ptr.val); }

#endif /* NC_FLOAT_DESTRUCTORS_H */