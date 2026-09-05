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

static inline void nc_free_ptr_i8(nc_ptr_i8 ptr) {
    if (ptr.ptr) {
        free(ptr.ptr);
    }
}

#endif /* NC_INT_DESTRUCTORS_H */