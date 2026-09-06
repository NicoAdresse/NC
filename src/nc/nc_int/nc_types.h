/* src/nc/nc_int/nc_types.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    NC Primitives Definitions.
*/

#ifndef NC_TYPES_H
#define NC_TYPES_H

#include <stdint.h>

/* Normal Primitives */
typedef struct { int8_t val; } nc_i8;
typedef struct { uint8_t val; } nc_u8;
typedef struct { int16_t val; } nc_i16;
typedef struct { uint16_t val; } nc_u16;
typedef struct { int32_t val; } nc_i32;
typedef struct { uint32_t val; } nc_u32;
typedef struct { int64_t val; } nc_i64;
typedef struct { uint64_t val; } nc_u64;

/* Ptrs Primitives */
typedef struct { nc_i8* ptr; } nc_ptr_i8;
typedef struct { nc_i16* ptr; } nc_ptr_i16;
typedef struct { nc_i32* ptr; } nc_ptr_i32;
typedef struct { nc_i64* ptr; } nc_ptr_i64;

#endif /* NC_TYPES_H */
