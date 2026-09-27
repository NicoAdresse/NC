/* src/nc/nc_string/nc_string_unique.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Macros for 'nc_string'.
*/

#ifndef NC_STRING_UNIQUE_H
#define NC_STRING_UNIQUE_H

#include "nc_string_destructor.h"

#define NC_STRING_CLEANUP __attribute__((cleanup(nc_string_destroy)))

#endif /* NC_STRING_UNIQUE_H */