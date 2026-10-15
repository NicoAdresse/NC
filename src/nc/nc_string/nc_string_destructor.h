/* src/nc/nc_string/nc_string_destructor.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    nc_string destructors.
*/

#ifndef NC_STRING_DESTRUCTOR_H
#define NC_STRING_DESTRUCTOR_H

#include "nc_string_definition.h"

#include <stdlib.h>

static inline void nc_string_destroy(nc_string* str) {
    if (str) {
        free(str->data);
        free(str);
    }
}

#endif /* NC_STRING_DESTRUCTOR_H */