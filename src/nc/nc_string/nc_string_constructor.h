/* src/nc/nc_string/nc_string_constructor.h */

/*
	SPDX-License-Identifier: MIT
	Copyright (c) 2026 Nico Erdmann
	nc_string constructors.
*/

#ifndef NC_STRING_CONSTRUCTOR_H
#define NC_STRING_CONSTRUCTOR_H

#include "inc_helper_functions.h"
#include "nc_string_definition.h"

#include <stdlib.h>

/* nc_string Constructor */
static inline nc_string* nc_string_create(int capacity) {
	nc_string* str = (nc_string*)malloc(sizeof(nc_string));
	if (!str) {
		inc_failed_to_allocate_memory();
		return NULL;
	}

	str->data = (char*)malloc(capacity);
	if (!str->data) {
		inc_failed_to_allocate_memory();
		free(str);
		return NULL;
	}

	str->data[0] = '\0';
	str->length = 0;
	str->capacity = capacity;
	return str;
}

/* nc_string Must Constructor */
static inline nc_string* nc_string_must_create(int capacity) {
	nc_string* str = (nc_string*)malloc(sizeof(nc_string));
	if (!str) {
		inc_failed_to_allocate_must_memory();
		exit(EXIT_FAILURE);
	}

	str->data = (char*)malloc(capacity);
	if (!str->data) {
		inc_failed_to_allocate_must_memory();
		free(str);
		exit(EXIT_FAILURE);
	}

	str->data[0] = '\0';
	str->length = 0;
	str->capacity = capacity;
	return str;
}

#endif /* NC_STRING_CONSTRUCTOR_H */