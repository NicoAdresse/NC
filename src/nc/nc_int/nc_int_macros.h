/* src/nc/nc_int/nc_int_macros.h */

/*
    About: Header file for integer NC datatypes macros.
    Initial Commit: NC_INT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#ifndef NC_INT_MACROS_H
#define NC_INT_MACROS_H

#define IS_SIGNED 1
#define IS_UNSIGNED 0
#define NC_UNSIGNED_MIN 0

#define NC_I8_MAX 127
#define NC_I8_MIN -128
#define NC_U8_MAX 255

#define NC_I16_MAX 32767
#define NC_I16_MIN -32768
#define NC_U16_MAX 65535

#define NC_I32_MAX 2147483647
#define NC_I32_MIN -2147483648
#define NC_U32_MAX 4294967295U

#define NC_I64_MAX INT64_C(9223372036854775807)
#define NC_I64_MIN (INT64_C(-9223372036854775807) - 1)
#define NC_U64_MAX UINT64_C(18446744073709551615)

#endif /* NC_INT_MACROS_H */