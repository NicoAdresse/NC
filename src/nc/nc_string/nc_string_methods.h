/* src/nc/nc_string/nc_string_methods.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Methods for 'nc_string'.
*/

#ifndef NC_STRING_METHODS_H
#define NC_STRING_METHODS_H

#include "nc_string_definition.h"
#include "inc_helper_functions.h"
#include "nc_string_constructor.h"

#include <stdlib.h>
#include <string.h>

/* Dynamic Resizing */
static inline void nc_string_resize(nc_string* str, int new_capacity) {
    if (new_capacity <= str->capacity) {
        inc_failed_to_resize();
        exit(EXIT_FAILURE);
    }

    char* temp = (char*)realloc(str->data, new_capacity);
    if (!temp) {
        inc_failed_to_allocate_must_memory();
        exit(EXIT_FAILURE);
    }

    str->data = temp;
    str->capacity = new_capacity;
}

/* Setting nc_string->data with a value */
static inline void nc_string_set(nc_string* str, char* value) {
    if (!str || !value) {
        inc_null_must_error();
        exit(EXIT_FAILURE);
    }

    int value_len = strlen(value);
    if (value_len + 1 > str->capacity) {
        nc_string_resize(str, value_len + 50);
    }

    strncpy(str->data, value, str->capacity - 1);
    str->data[str->capacity - 1] = '\0';
    str->length = value_len;
}

/* Clearing data and length */
static inline void nc_string_clear(nc_string* str) {
    if (str) {
        str->data[0] = '\0';
        str->length = 0;
    }
}

/* Appending */
static inline void nc_string_append(nc_string* str, const char* append) {
    if (!str || !append) {
        inc_null_must_error();
        exit(EXIT_FAILURE);
    }
    
    int append_len = strlen(append);
    int new_length = str->length + append_len;
    
    if (new_length + 1 > str->capacity) {
        nc_string_resize(str, new_length + 50);
    }
    
    strcat(str->data, append);
    str->length = new_length;
}

/* Inserting at position */
static inline void nc_string_insert(nc_string* str, int pos, const char* insert) {
    if (!str || !insert || pos < 0 || pos > str->length) {
        inc_null_must_error();
        exit(EXIT_FAILURE);
    }
    
    int insert_len = strlen(insert);
    int new_length = str->length + insert_len;
    
    if (new_length + 1 > str->capacity) {
        nc_string_resize(str, new_length + 50);
    }
    
    memmove(str->data + pos + insert_len, str->data + pos, str->length - pos + 1);
    memcpy(str->data + pos, insert, insert_len);
    str->length = new_length;
}

/* String Clone */
static inline nc_string* nc_string_clone(nc_string* str) {
    if (!str) {
        inc_null_error();
        return NULL;
    }

    nc_string* clone = nc_string_create(str->length + 10);
    if (!clone) {
        inc_null_error();
        return NULL;
    }

    nc_string_set(clone, str->data);
    return clone;
}

/* Removing substring */
static inline void nc_string_remove(nc_string* str, int pos, int count) {
    if (!str || pos < 0 || pos >= str->length || count < 0) {
        inc_null_must_error();
        exit(EXIT_FAILURE);
    }
    
    if (pos + count > str->length) {
        count = str->length - pos;
    }
    
    memmove(str->data + pos, str->data + pos + count, str->length - pos - count + 1);
    str->length -= count;
}

/* Finding substring */
static inline int nc_string_find(nc_string* str, const char* substring) {
    if (!str || !substring) {
        return -1;
    }
    
    char* pos = strstr(str->data, substring);
    return pos ? (pos - str->data) : -1;
}

/* Get character at position */
static inline char nc_string_at(nc_string* str, int pos) {
    if (!str || pos < 0 || pos >= str->length) {
        return '\0';
    }
    return str->data[pos];
}

/* Getters */
static inline int nc_string_get_capacity(nc_string* str) { return str ? str->capacity : 0; }
static inline int nc_string_get_length(nc_string* str) { return str ? str->length : 0; }
static inline char* nc_string_get_data(nc_string* str) { return str ? str->data : NULL; }

#endif /* NC_STRING_METHODS_H */