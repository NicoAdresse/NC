/* src/nc/nc_string/nc_string_definition.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    nc_string struct definition.
*/

#ifndef NC_STRING_DEFINITION_H
#define NC_STRING_DEFINITION_H

typedef struct {
    char* data;
    int length;
    int capacity; 
} nc_string;

#endif /* NC_STRING_DEFINTION_H */