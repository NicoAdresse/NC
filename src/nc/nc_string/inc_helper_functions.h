/* src/nc/nc_string/inc_helper_functions.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Helper Functions for nc_string. Private, and is not meant to be used by users.
*/

#ifndef INC_HELPER_FUNCTIONS_H
#define INC_HELPER_FUNCTIONS_H

#include "../nc_log.h"

static inline void inc_failed_to_allocate_memory() {
    nc_println_err("Failed to allocate memory for string. Returning NULL.");
}

static inline void inc_failed_to_allocate_must_memory() {
    nc_println_err("Failed to allocate memory for string. Crashing.");
}

#endif /* INC_HELPER_FUNCTIONS_H */