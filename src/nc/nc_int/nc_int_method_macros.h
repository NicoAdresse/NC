/* src/nc/nc_int/nc_int_method_macros.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Generic Macros used by users.
*/

#ifndef NC_INT_METHOD_MACROS_H
#define NC_INT_METHOD_MACROS_H

#include "nc_types.h"
#include "nc_int_macros.h"
#include "inc_helper_funcs.h"

#include "nc_i8/nc_i8.h"
#include "nc_i16/nc_i16.h"
#include "nc_i32/nc_i32.h"
#include "nc_i64/nc_i64.h"
#include "nc_u8/nc_u8.h"
#include "nc_u16/nc_u16.h"
#include "nc_u32/nc_u32.h"
#include "nc_u64/nc_u64.h"

#include "nc_ptr_i8/nc_ptr_i8.h"
#include "nc_ptr_i16/nc_ptr_i16.h"
#include "nc_ptr_i32/nc_ptr_i32.h"
#include "nc_ptr_i64/nc_ptr_i64.h"
#include "nc_ptr_u8/nc_ptr_u8.h"
#include "nc_ptr_u16/nc_ptr_u16.h"
#include "nc_ptr_u32/nc_ptr_u32.h"
#include "nc_ptr_u64/nc_ptr_u64.h"

#define nc_get_val_int(x) _Generic((x), \
    nc_i8: nc_get_val_i8, \
    nc_u8: nc_get_val_u8,  \
    nc_i16: nc_get_val_i16, \
    nc_u16: nc_get_val_u16, \
    nc_i32: nc_get_val_i32, \
    nc_u32: nc_get_val_u32, \
    nc_i64: nc_get_val_i64, \
    nc_u64: nc_get_val_u64, \
    nc_ptr_i8: nc_get_val_ptr_i8, \
    nc_ptr_u8: nc_get_val_ptr_u8, \
    nc_ptr_i16: nc_get_val_ptr_i16, \
    nc_ptr_u16: nc_get_val_ptr_u16, \
    nc_ptr_i32: nc_get_val_ptr_i32, \
    nc_ptr_u32: nc_get_val_ptr_u32, \
    nc_ptr_i64: nc_get_val_ptr_i64, \
    nc_ptr_u64: nc_get_val_ptr_u64, \
    default: nc_get_val_i32 \
)(x)

#define nc_get_size_int(x) _Generic((x), \
    nc_i8:  nc_get_size_i8(), \
    nc_u8:  nc_get_size_u8(), \
    nc_i16: nc_get_size_i16(), \
    nc_u16: nc_get_size_u16(), \
    nc_i32: nc_get_size_i32(), \
    nc_u32: nc_get_size_u32(), \
    nc_i64: nc_get_size_i64(), \
    nc_u64: nc_get_size_u64(), \
    nc_ptr_i8: nc_get_size_ptr_i8(), \
    nc_ptr_u8: nc_get_size_ptr_u8(), \
    nc_ptr_i16: nc_get_size_ptr_i16(), \
    nc_ptr_u16: nc_get_size_ptr_u16(), \
    nc_ptr_i32: nc_get_size_ptr_i32(), \
    nc_ptr_u32: nc_get_size_ptr_u32(), \
    nc_ptr_i64: nc_get_size_ptr_i64(), \
    nc_ptr_u64: nc_get_size_ptr_u64(), \
    default: nc_get_size_i32() \
)

#define nc_new_int(val) _Generic((val), \
    int8_t:    nc_new_i8, \
    uint8_t:   nc_new_u8, \
    int16_t:   nc_new_i16, \
    uint16_t:  nc_new_u16, \
    int32_t:   nc_new_i32, \
    uint32_t:  nc_new_u32, \
    int64_t:   nc_new_i64, \
    uint64_t:  nc_new_u64, \
    default: nc_new_i32 \
)(val)

#define nc_new_must_int(val) _Generic((val), \
    int8_t: nc_new_must_i8, \
    uint8_t: nc_new_must_u8, \
    int16_t: nc_new_must_i16, \
    uint16_t: nc_new_must_u16, \
    int32_t: nc_new_must_i32, \
    uint32_t: nc_new_must_u32, \
    int64_t: nc_new_must_i64, \
    uint64_t: nc_new_must_u64, \
    default: nc_new_must_i32 \
)(val)

#define nc_new_ptr_int(val) _Generic((val), \
    nc_ptr_i8:    nc_new_ptr_i8, \
    nc_ptr_u8:   nc_new_ptr_u8, \
    nc_ptr_i16:   nc_new_ptr_i16, \
    nc_ptr_u16:  nc_new_ptr_u16, \
    nc_ptr_i32:   nc_new_ptr_i32, \
    nc_ptr_u32:  nc_new_ptr_u32, \
    nc_ptr_i64:   nc_new_ptr_i64, \
    nc_ptr_u64:  nc_new_ptr_u64, \
    default: nc_new_ptr_i32 \
)(val)

#define nc_new_must_ptr_int(val) _Generic((val), \
    nc_ptr_i8:    nc_new_must_ptr_i8, \
    nc_ptr_u8:   nc_new_must_ptr_u8, \
    nc_ptr_i16:   nc_new_must_ptr_i16, \
    nc_ptr_u16:  nc_new_must_ptr_u16, \
    nc_ptr_i32:   nc_new_must_ptr_i32, \
    nc_ptr_u32:  nc_new_must_ptr_u32, \
    nc_ptr_i64:   nc_new_must_ptr_i64, \
    nc_ptr_u64:  nc_new_must_ptr_u64, \
    default: nc_new_must_ptr_i32 \
)(val)

#define nc_free_int(ptr) _Generic((ptr), \
    nc_ptr_i8:    nc_free_ptr_i8, \
    nc_ptr_u8:    nc_free_ptr_u8, \
    nc_ptr_i16:   nc_free_ptr_i16, \
    nc_ptr_u16:   nc_free_ptr_u16, \
    nc_ptr_i32:   nc_free_ptr_i32, \
    nc_ptr_u32:   nc_free_ptr_u32, \
    nc_ptr_i64:   nc_free_ptr_i64, \
    nc_ptr_u64:   nc_free_ptr_u64, \
    default:      nc_free_ptr_i32 \
)(ptr)

#define nc_convert_int(target_type, val) _Generic((val), \
    nc_i8: _Generic((target_type){0}, \
        nc_i8:  (val), \
        nc_u8:  nc_i8_convert_to_u8, \
        nc_i16: nc_i8_convert_to_i16, \
        nc_u16: nc_i8_convert_to_u16, \
        nc_i32: nc_i8_convert_to_i32, \
        nc_u32: nc_i8_convert_to_u32, \
        nc_i64: nc_i8_convert_to_i64, \
        nc_u64: nc_i8_convert_to_u64, \
        int:    nc_i8_convert_to_int \
    ), \
    nc_u8: _Generic((target_type){0}, \
        nc_i8:  nc_u8_convert_to_i8, \
        nc_u8:  (val), \
        nc_i16: nc_u8_convert_to_i16, \
        nc_u16: nc_u8_convert_to_u16, \
        nc_i32: nc_u8_convert_to_i32, \
        nc_u32: nc_u8_convert_to_u32, \
        nc_i64: nc_u8_convert_to_i64, \
        nc_u64: nc_u8_convert_to_u64, \
        int:    nc_u8_convert_to_int \
    ), \
    nc_i16: _Generic((target_type){0}, \
        nc_i8:  nc_i16_convert_to_i8, \
        nc_u8:  nc_i16_convert_to_u8, \
        nc_i16: (val), \
        nc_u16: nc_i16_convert_to_u16, \
        nc_i32: nc_i16_convert_to_i32, \
        nc_u32: nc_i16_convert_to_u32, \
        nc_i64: nc_i16_convert_to_i64, \
        nc_u64: nc_i16_convert_to_u64, \
        int:    nc_i16_convert_to_int \
    ), \
    nc_u16: _Generic((target_type){0}, \
        nc_i8:  nc_u16_convert_to_i8, \
        nc_u8:  nc_u16_convert_to_u8, \
        nc_i16: nc_u16_convert_to_i16, \
        nc_u16: (val), \
        nc_i32: nc_u16_convert_to_i32, \
        nc_u32: nc_u16_convert_to_u32, \
        nc_i64: nc_u16_convert_to_i64, \
        nc_u64: nc_u16_convert_to_u64, \
        int:    nc_u16_convert_to_int \
    ), \
    nc_i32: _Generic((target_type){0}, \
        nc_i8:  nc_i32_convert_to_i8, \
        nc_u8:  nc_i32_convert_to_u8, \
        nc_i16: nc_i32_convert_to_i16, \
        nc_u16: nc_i32_convert_to_u16, \
        nc_i32: (val), \
        nc_u32: nc_i32_convert_to_u32, \
        nc_i64: nc_i32_convert_to_i64, \
        nc_u64: nc_i32_convert_to_u64, \
        int:    nc_i32_convert_to_int \
    ), \
    nc_u32: _Generic((target_type){0}, \
        nc_i8:  nc_u32_convert_to_i8, \
        nc_u8:  nc_u32_convert_to_u8, \
        nc_i16: nc_u32_convert_to_i16, \
        nc_u16: nc_u32_convert_to_u16, \
        nc_i32: nc_u32_convert_to_i32, \
        nc_u32: (val), \
        nc_i64: nc_u32_convert_to_i64, \
        nc_u64: nc_u32_convert_to_u64, \
        int:    nc_u32_convert_to_int \
    ), \
    nc_i64: _Generic((target_type){0}, \
        nc_i8:  nc_i64_convert_to_i8, \
        nc_u8:  nc_i64_convert_to_u8, \
        nc_i16: nc_i64_convert_to_i16, \
        nc_u16: nc_i64_convert_to_u16, \
        nc_i32: nc_i64_convert_to_i32, \
        nc_u32: nc_i64_convert_to_u32, \
        nc_i64: (val), \
        nc_u64: nc_i64_convert_to_u64, \
        int:    nc_i64_convert_to_int \
    ), \
    nc_u64: _Generic((target_type){0}, \
        nc_i8:  nc_u64_convert_to_i8, \
        nc_u8:  nc_u64_convert_to_u8, \
        nc_i16: nc_u64_convert_to_i16, \
        nc_u16: nc_u64_convert_to_u16, \
        nc_i32: nc_u64_convert_to_i32, \
        nc_u32: nc_u64_convert_to_u32, \
        nc_i64: nc_u64_convert_to_i64, \
        nc_u64: (val), \
        int:    nc_u64_convert_to_int \
    ) \
)(val)

#define nc_checked_add_int(n1, n2) _Generic((n1), \
    nc_i8: nc_checked_add_i8, \
    nc_u8: nc_checked_add_u8, \
    nc_i16: nc_checked_add_i16, \
    nc_u16: nc_checked_add_u16, \
    nc_i32: nc_checked_add_i32, \
    nc_u32: nc_checked_add_u32, \
    nc_i64: nc_checked_add_i64, \
    nc_u64: nc_checked_add_u64, \
    nc_ptr_i8: nc_checked_add_ptr_i8, \
    nc_ptr_u8: nc_checked_add_ptr_u8, \
    nc_ptr_i16: nc_checked_add_ptr_i16, \
    nc_ptr_u16: nc_checked_add_ptr_u16, \
    nc_ptr_i32: nc_checked_add_ptr_i32, \
    nc_ptr_u32: nc_checked_add_ptr_u32, \
    nc_ptr_i64: nc_checked_add_ptr_i64, \
    nc_ptr_u64: nc_checked_add_ptr_u64, \
    default: nc_checked_add_i32 \
)((n1), (n2))

#define nc_checked_sub_int(n1, n2) _Generic((n1), \
    nc_i8: nc_checked_sub_i8, \
    nc_u8: nc_checked_sub_u8, \
    nc_i16: nc_checked_sub_i16, \
    nc_u16: nc_checked_sub_u16, \
    nc_i32: nc_checked_sub_i32, \
    nc_u32: nc_checked_sub_u32, \
    nc_i64: nc_checked_sub_i64, \
    nc_u64: nc_checked_sub_u64, \
    nc_ptr_i8: nc_checked_sub_ptr_i8, \
    nc_ptr_u8: nc_checked_sub_ptr_u8, \
    nc_ptr_i16: nc_checked_sub_ptr_i16, \
    nc_ptr_u16: nc_checked_sub_ptr_u16, \
    nc_ptr_i32: nc_checked_sub_ptr_i32, \
    nc_ptr_u32: nc_checked_sub_ptr_u32, \
    nc_ptr_i64: nc_checked_sub_ptr_i64, \
    nc_ptr_u64: nc_checked_sub_ptr_u64, \
    default: nc_checked_sub_i32 \
)((n1), (n2))

#define nc_checked_mul_int(n1, n2) _Generic((n1), \
    nc_i8: nc_checked_mul_i8, \
    nc_u8: nc_checked_mul_u8, \
    nc_i16: nc_checked_mul_i16, \
    nc_u16: nc_checked_mul_u16, \
    nc_i32: nc_checked_mul_i32, \
    nc_u32: nc_checked_mul_u32, \
    nc_i64: nc_checked_mul_i64, \
    nc_u64: nc_checked_mul_u64, \
    nc_ptr_i8: nc_checked_mul_ptr_i8, \
    nc_ptr_u8: nc_checked_mul_ptr_u8, \
    nc_ptr_i16: nc_checked_mul_ptr_i16, \
    nc_ptr_u16: nc_checked_mul_ptr_u16, \
    nc_ptr_i32: nc_checked_mul_ptr_i32, \
    nc_ptr_u32: nc_checked_mul_ptr_u32, \
    nc_ptr_i64: nc_checked_mul_ptr_i64, \
    nc_ptr_u64: nc_checked_mul_ptr_u64, \
    default: nc_checked_mul_i32 \
)((n1), (n2))

#define nc_checked_div_int(n1, n2, is_zero_division_allowed) _Generic((n1), \
    nc_i8: nc_checked_div_i8, \
    nc_u8: nc_checked_div_u8, \
    nc_i16: nc_checked_div_i16, \
    nc_u16: nc_checked_div_u16, \
    nc_i32: nc_checked_div_i32, \
    nc_u32: nc_checked_div_u32, \
    nc_i64: nc_checked_div_i64, \
    nc_u64: nc_checked_div_u64, \
    nc_ptr_i8: nc_checked_div_ptr_i8, \
    nc_ptr_u8: nc_checked_div_ptr_u8, \
    nc_ptr_i16: nc_checked_div_ptr_i16, \
    nc_ptr_u16: nc_checked_div_ptr_u16, \
    nc_ptr_i32: nc_checked_div_ptr_i32, \
    nc_ptr_u32: nc_checked_div_ptr_u32, \
    nc_ptr_i64: nc_checked_div_ptr_i64, \
    nc_ptr_u64: nc_checked_div_ptr_u64, \
    default: nc_checked_div_i32 \
)((n1), (n2), (is_zero_division_allowed))

#endif /* NC_INT_METHOD_MACROS_H */