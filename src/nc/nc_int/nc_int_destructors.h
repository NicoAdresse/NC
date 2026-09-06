/* src/nc/nc_int/nc_int_destructors.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Destructors for NC integer primitives.
*/

#ifndef NC_INT_DESTRUCTORS_H
#define NC_INT_DESTRUCTORS_H

#include <stdlib.h>

#include "nc_types.h"

static inline void nc_free_ptr_i8(nc_ptr_i8 ptr) { free(ptr.ptr); }
static inline void nc_free_ptr_i16(nc_ptr_i16 ptr) { free(ptr.ptr); }
static inline void nc_free_ptr_i32(nc_ptr_i32 ptr) { free(ptr.ptr); }
static inline void nc_free_ptr_i64(nc_ptr_i64 ptr) { free(ptr.ptr); }

#endif /* NC_INT_DESTRUCTORS_H */