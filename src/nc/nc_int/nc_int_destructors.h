/* src/nc/nc_int/nc_int_destructors.h */

/*
    About: Header file for the primitive datatypes' destructors.
    Initial Commit: NC_INT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
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