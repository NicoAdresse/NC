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

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* Dynamic Resizing */
static inline void nc_string_resize(nc_string* str, int new_capacity) {
    if (!str || new_capacity <= 0) {
        inc_null_must_error();
        exit(EXIT_FAILURE);
    }

    char* new_data = (char*)malloc(new_capacity * sizeof(char));
    if (!new_data) {
        inc_null_must_error();
        exit(EXIT_FAILURE);
    }

    if (str->data) {
        memcpy(new_data, str->data, str->length);
        free(str->data);
    }

    str->data = new_data;
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

    memcpy(str->data, value, value_len);
    str->data[value_len] = '\0';
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
    
    strcpy(str->data + str->length, append);
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

/* Converting a C string into an nc_string */
static inline nc_string* nc_string_from_cstr(const char* cstr) {
	if (!cstr) {
		inc_null_error();
		return NULL;
	}

	int len = strlen(cstr);
	nc_string* str = nc_string_create(len + 1);
	if (!str) {
		inc_null_error();
		return NULL;
	}

	memcpy(str->data, cstr, len + 1);
	str->length = len;
	return str;
}

/* Comparing two strings */
static inline int nc_string_compare(nc_string* a, nc_string* b) {
	if (!a || !b) {
		inc_null_must_error();
		exit(EXIT_FAILURE);
	}

	return strcmp(a->data, b->data);
}

/* To Upper */
static inline void nc_string_to_upper(nc_string* str) {
    if (!str) { inc_null_must_error(); exit(EXIT_FAILURE); }
    for (int i = 0; i < str->length; i++)
        str->data[i] = toupper((unsigned char)str->data[i]);
}

/* To Lower */
static inline void nc_string_to_lower(nc_string* str) {
    if (!str) { inc_null_must_error(); exit(EXIT_FAILURE); }
    for (int i = 0; i < str->length; i++)
        str->data[i] = tolower((unsigned char)str->data[i]);
}

/* Trim Left */
static inline void nc_string_trim_left(nc_string* str) {
    if (!str) {
        inc_null_must_error();
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (i < str->length && isspace((unsigned char)str->data[i])) i++;
    if (i > 0) {
        memmove(str->data, str->data + i, str->length - i + 1);
        str->length -= i;
    }
}

/* Trim Right */
static inline void nc_string_trim_right(nc_string* str) {
    if (!str) { inc_null_must_error(); exit(EXIT_FAILURE); }
    while (str->length > 0 && isspace((unsigned char)str->data[str->length - 1]))
        str->data[--str->length] = '\0';
}

/* Trim (both sides) */
static inline void nc_string_trim(nc_string* str) {
    nc_string_trim_right(str);
    nc_string_trim_left(str);
}

/* Reverse */
static inline void nc_string_reverse(nc_string* str) {
    if (!str) { inc_null_must_error(); exit(EXIT_FAILURE); }
    int left = 0, right = str->length - 1;
    while (left < right) {
        char tmp = str->data[left];
        str->data[left++] = str->data[right];
        str->data[right--] = tmp;
    }
}

/* Replace all occurrences of 'from' with 'to' */
static inline void nc_string_replace(nc_string* str, const char* from, const char* to) {
    if (!str || !from || !to) { inc_null_must_error(); exit(EXIT_FAILURE); }

    int from_len = strlen(from);
    int to_len   = strlen(to);
    if (from_len == 0) return;

    int count = 0;
    char* cursor = str->data;

    while ((cursor = strstr(cursor, from))) { count++; cursor += from_len; }
    if (count == 0) return;

    int new_length = str->length + count * (to_len - from_len);
    char* new_data = (char*)malloc((new_length + 1) * sizeof(char));
    if (!new_data) { inc_null_must_error(); exit(EXIT_FAILURE); }

    char* src = str->data;
    char* dst = new_data;
    char* match;
    while ((match = strstr(src, from))) {
        int chunk = match - src;
        memcpy(dst, src, chunk);
        dst += chunk;
        memcpy(dst, to, to_len);
        dst += to_len;
        src = match + from_len;
    }

    strcpy(dst, src);

    free(str->data);
    str->data = new_data;
    str->length = new_length;
    str->capacity = new_length + 1;
}

/* Getters */
static inline int nc_string_get_capacity(nc_string* str) { return str ? str->capacity : 0; }
static inline int nc_string_get_length(nc_string* str) { return str ? str->length : 0; }
static inline char* nc_string_get_data(nc_string* str) { return str ? str->data : NULL; }

#endif /* NC_STRING_METHODS_H */