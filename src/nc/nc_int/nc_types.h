/* src/nc/nc_int/nc_types.h */

/*
    About: Header file for the definition of the primitive integer datatypes.
    Initial Commit: INIT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#ifndef NC_TYPES_H
#define NC_TYPES_H

#include <stdint.h>

typedef struct { int8_t val; } nc_i8;
typedef struct { uint8_t val; } nc_u8;
typedef struct { int16_t val; } nc_i16;
typedef struct { uint16_t val; } nc_u16;
typedef struct { int32_t val; } nc_i32;
typedef struct { uint32_t val; } nc_u32;
typedef struct { int64_t val; } nc_i64;
typedef struct { uint64_t val; } nc_u64;

#endif /* NC_TYPES_H */