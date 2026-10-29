/* src/nc/nc_string/nc_string_definition.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    nc_string struct definition.
*/

#ifndef NC_STRING_DEFINITION_H
#define NC_STRING_DEFINITION_H

#include <stdlib.h>

typedef struct {
    char* data;
    size_t length;
    size_t capacity; 
} nc_string;

#endif /* NC_STRING_DEFINTION_H */