/* src/nc/nc_int/nc_int_constructors.h */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Constructors for NC integer primitives.
*/

#ifndef NC_INT_CONSTRUCTORS_H
#define NC_INT_CONSTRUCTORS_H

#include <stdlib.h>

#include "nc_types.h"
#include "nc_int_macros.h"
#include "inc_helper_funcs.h"

/* nc_i8's constructor */
static inline nc_i8 nc_new_i8(int64_t val) {
    if (check_overflow(val, NC_I8_MAX)) {
        send_constructor_error_msg(8, IS_SIGNED, ERROR_OVERFLOW, val, NC_I8_MAX);
        return (nc_i8){.val = (int8_t)NC_I8_MAX};
    }

    if (check_underflow(val, NC_I8_MIN)) {
        send_constructor_error_msg(8, IS_SIGNED, ERROR_UNDERFLOW, val, NC_I8_MIN);
        return (nc_i8){.val = (int8_t)NC_I8_MIN};
    }

    return (nc_i8){.val = (int8_t)val};
}

/* nc_i8's runtime fail constructor */
static inline nc_i8 nc_new_must_i8(int64_t val) {
    if (check_overflow(val, NC_I8_MAX)) {
        send_constructor_runtime_fail_error_msg(8, IS_SIGNED, ERROR_OVERFLOW, val);
        exit(1);
    }

    if (check_underflow(val, NC_I8_MIN)) {
        send_constructor_runtime_fail_error_msg(8, IS_SIGNED, ERROR_UNDERFLOW, val);
        exit(1);
    }

    return (nc_i8){.val = (int8_t)val};
}

/* nc_i16's constructor */
static inline nc_i16 nc_new_i16(int64_t val) {
    if (check_overflow(val, NC_I16_MAX)) {
        send_constructor_error_msg(16, IS_SIGNED, ERROR_OVERFLOW, val, NC_I16_MAX);
        return (nc_i16){.val = (int16_t)NC_I16_MAX};
    }

    if (check_underflow(val, NC_I16_MIN)) {
        send_constructor_error_msg(16, IS_SIGNED, ERROR_UNDERFLOW, val, NC_I16_MIN);
        return (nc_i16){.val = (int16_t)NC_I16_MIN};
    }

    return (nc_i16){.val = (int16_t)val};
}

/* nc_i16's runtime fail constructor */
static inline nc_i16 nc_new_must_i16(int64_t val) {
    if (check_overflow(val, NC_I16_MAX)) {
        send_constructor_runtime_fail_error_msg(16, IS_SIGNED, ERROR_OVERFLOW, val);
        exit(1);
    }

    if (check_underflow(val, NC_I16_MIN)) {
        send_constructor_runtime_fail_error_msg(16, IS_SIGNED, ERROR_UNDERFLOW, val);
        exit(1);
    }

    return (nc_i16){.val = (int16_t)val};
}

/* nc_i32's constructor */
static inline nc_i32 nc_new_i32(int64_t val) {
    if (check_overflow(val, NC_I32_MAX)) {
        send_constructor_error_msg(32, IS_SIGNED, ERROR_OVERFLOW, val, NC_I32_MAX);
        return (nc_i32){.val = (int32_t)NC_I32_MAX};
    }

    if (check_underflow(val, NC_I32_MIN)) {
        send_constructor_error_msg(32, IS_SIGNED, ERROR_UNDERFLOW, val, NC_I32_MIN);
        return (nc_i32){.val = (int32_t)NC_I32_MIN};
    }

    return (nc_i32){.val = (int32_t)val};
}

/* nc_i32's runtime fail constructor */
static inline nc_i32 nc_new_must_i32(int64_t val) {
    if (check_overflow(val, NC_I32_MAX)) {
        send_constructor_runtime_fail_error_msg(32, IS_SIGNED, ERROR_OVERFLOW, val);
        exit(1);
    }

    if (check_underflow(val, NC_I32_MIN)) {
        send_constructor_runtime_fail_error_msg(32, IS_SIGNED, ERROR_UNDERFLOW, val);
        exit(1);
    }

    return (nc_i32){.val = (int32_t)val};
}

/* nc_i64's constructor */
static inline nc_i64 nc_new_i64(int64_t val) {
    return (nc_i64){.val = val};
}

/* nc_u8's constructor */
static inline nc_u8 nc_new_u8(int64_t val) {
    if (check_overflow(val, NC_U8_MAX)) {
        send_constructor_error_msg(8, IS_UNSIGNED, ERROR_OVERFLOW, val, NC_U8_MAX);
        return (nc_u8){.val = (uint8_t)NC_U8_MAX};
    }

    if (check_underflow(val, NC_UNSIGNED_MIN)) {
        send_constructor_error_msg(8, IS_UNSIGNED, ERROR_UNDERFLOW, val, NC_UNSIGNED_MIN);
        return (nc_u8){.val = (uint8_t)NC_UNSIGNED_MIN};
    }

    return (nc_u8){.val = (uint8_t)val};
}

/* nc_u8's runtime fail constructor */
static inline nc_u8 nc_new_must_u8(int64_t val) {
    if (check_overflow(val, NC_U8_MAX)) {
        send_constructor_runtime_fail_error_msg(8, IS_UNSIGNED, ERROR_OVERFLOW, val);
        exit(1);
    }

    if (check_underflow(val, NC_UNSIGNED_MIN)) {
        send_constructor_runtime_fail_error_msg(8, IS_UNSIGNED, ERROR_UNDERFLOW, val);
        exit(1);
    }

    return (nc_u8){.val = (uint8_t)val};
}

/* nc_u16's constructor */
static inline nc_u16 nc_new_u16(int64_t val) {
    if (check_overflow(val, NC_U16_MAX)) {
        send_constructor_error_msg(16, IS_UNSIGNED, ERROR_OVERFLOW, val, NC_U16_MAX);
        return (nc_u16){.val = (uint16_t)NC_U16_MAX};
    }

    if (check_underflow(val, NC_UNSIGNED_MIN)) {
        send_constructor_error_msg(16, IS_UNSIGNED, ERROR_UNDERFLOW, val, NC_UNSIGNED_MIN);
        return (nc_u16){.val = (uint16_t)NC_UNSIGNED_MIN};
    }

    return (nc_u16){.val = (uint16_t)val};
}

/* nc_u16's runtime fail constructor */
static inline nc_u16 nc_new_must_u16(int64_t val) {
    if (check_overflow(val, NC_U16_MAX)) {
        send_constructor_runtime_fail_error_msg(16, IS_UNSIGNED, ERROR_OVERFLOW, val);
        exit(1);
    }

    if (check_underflow(val, NC_UNSIGNED_MIN)) {
        send_constructor_runtime_fail_error_msg(16, IS_UNSIGNED, ERROR_UNDERFLOW, val);
        exit(1);
    }

    return (nc_u16){.val = (uint16_t)val};
}

/* nc_u32's constructor */
static inline nc_u32 nc_new_u32(int64_t val) {
    if (check_overflow(val, NC_U32_MAX)) {
        send_constructor_error_msg(32, IS_UNSIGNED, ERROR_OVERFLOW, val, NC_U32_MAX);
        return (nc_u32){.val = (uint32_t)NC_U32_MAX};
    }

    if (check_underflow(val, NC_UNSIGNED_MIN)) {
        send_constructor_error_msg(32, IS_UNSIGNED, ERROR_UNDERFLOW, val, NC_UNSIGNED_MIN);
        return (nc_u32){.val = (uint32_t)NC_UNSIGNED_MIN};
    }

    return (nc_u32){.val = (uint32_t)val};
}

/* nc_u32's runtime fail constructor */
static inline nc_u32 nc_new_must_u32(int64_t val) {
    if (check_overflow(val, NC_U32_MAX)) {
        send_constructor_runtime_fail_error_msg(32, IS_UNSIGNED, ERROR_OVERFLOW, val);
        exit(1);
    }

    if (check_underflow(val, NC_UNSIGNED_MIN)) {
        send_constructor_runtime_fail_error_msg(32, IS_UNSIGNED, ERROR_UNDERFLOW, val);
        exit(1);
    }

    return (nc_u32){.val = (uint32_t)val};
}

/* nc_u64's constructor */
static inline nc_u64 nc_new_u64(uint64_t val) {
    return (nc_u64){.val = val};
}

/* nc_ptr_i8's constructor */
static inline nc_ptr_i8 nc_new_ptr_i8(nc_i8 val) {    
    nc_i8* heap_val = malloc(sizeof(nc_i8));

    if (!heap_val) {
        send_allocation_error_msg(IS_SIGNED, sizeof(nc_i8), "nc_ptr_i8");
        return (nc_ptr_i8){.ptr = NULL};
    }
    
    *heap_val = val;
    return (nc_ptr_i8){.ptr = heap_val};
}

/* nc_ptr_i8 runtime fail constructor */
static inline nc_ptr_i8 nc_new_must_ptr_i8(nc_i8 val) {
    nc_i8* heap_val = malloc(sizeof(nc_i8));

    if (!heap_val) {
        send_allocation_must_error_msg(IS_SIGNED, sizeof(nc_i8), "nc_ptr_i8");
        exit(1);
    }

    *heap_val = val;
    return (nc_ptr_i8){.ptr = heap_val};
}

/* nc_ptr_i16's constructor */
static inline nc_ptr_i16 nc_new_ptr_i16(nc_i16 val) {
    nc_i16* heap_val = malloc(sizeof(nc_i16));

    if (!heap_val) {
        send_allocation_error_msg(IS_SIGNED, sizeof(nc_i16), "nc_ptr_i16");
        return (nc_ptr_i16){.ptr = NULL};
    }

    *heap_val = val;
    return (nc_ptr_i16){.ptr = heap_val};
}

/* nc_ptr_i16's runtime fail constructor */
static inline nc_ptr_i16 nc_new_must_ptr_i16(nc_i16 val) {
    nc_i16* heap_val = malloc(sizeof(nc_i16));
    
    if (!heap_val) {
        send_allocation_must_error_msg(IS_SIGNED, sizeof(nc_i16), "nc_ptr_i16");
        exit(1);
    }

    *heap_val = val;
    return (nc_ptr_i16){.ptr = heap_val};
}

/* nc_ptr_i32's constructor */
static inline nc_ptr_i32 nc_new_ptr_i32(nc_i32 val) {
    nc_i32* heap_val = malloc(sizeof(nc_i32));

    if (!heap_val) {
        send_allocation_error_msg(IS_SIGNED, sizeof(nc_i32), "nc_ptr_i32");
        return (nc_ptr_i32){.ptr = NULL};
    }

    *heap_val = val;
    return (nc_ptr_i32){.ptr = heap_val};
}

/* nc_ptr_i32's runtime fail constructor */
static inline nc_ptr_i32 nc_new_must_ptr_i32(nc_i32 val) {
    nc_i32* heap_val = malloc(sizeof(nc_i32));
    
    if (!heap_val) {
        send_allocation_must_error_msg(IS_SIGNED, sizeof(nc_i32), "nc_ptr_i32");
        exit(1);
    }

    *heap_val = val;
    return (nc_ptr_i32){.ptr = heap_val};
}

/* nc_ptr_i64's constructor */
static inline nc_ptr_i64 nc_new_ptr_i64(nc_i64 val) {
    nc_i64* heap_val = malloc(sizeof(nc_i64));

    if (!heap_val) {
        send_allocation_error_msg(IS_SIGNED, sizeof(nc_i64), "nc_ptr_i64");
        return (nc_ptr_i64){.ptr = NULL};
    }

    *heap_val = val;
    return (nc_ptr_i64){.ptr = heap_val};
}

/* nc_ptr_i64's runtime fail constructor */
static inline nc_ptr_i64 nc_new_must_ptr_i64(nc_i64 val) {
    nc_i64* heap_val = malloc(sizeof(nc_i64));
    
    if (!heap_val) {
        send_allocation_must_error_msg(IS_SIGNED, sizeof(nc_i64), "nc_ptr_i64");
        exit(1);
    }

    *heap_val = val;
    return (nc_ptr_i64){.ptr = heap_val};
}

/* nc_ptr_u8's constructor */
static inline nc_ptr_u8 nc_new_ptr_u8(nc_u8 val) {
    nc_u8* heap_val = malloc(sizeof(nc_u8));

    if (!heap_val) {
        send_allocation_error_msg(IS_SIGNED, sizeof(nc_u8), "nc_ptr_u8");
        return (nc_ptr_u8){.ptr = NULL};
    }

    *heap_val = val;
    return (nc_ptr_u8){.ptr = heap_val};
}

/* nc_ptr_u8's runtime fail constructor */
static inline nc_ptr_u8 nc_new_must_ptr_u8(nc_u8 val) {
    nc_u8* heap_val = malloc(sizeof(nc_u8));

    if (!heap_val) {
        send_allocation_must_error_msg(IS_SIGNED, sizeof(nc_u8), "nc_ptr_u8");
        exit(1);
    }

    *heap_val = val;
    return (nc_ptr_u8){.ptr = heap_val};
}

/* nc_ptr_u16's constructor */
static inline nc_ptr_u16 nc_new_ptr_u16(nc_u16 val) {
    nc_u16* heap_val = malloc(sizeof(nc_u16));

    if (!heap_val) {
        send_allocation_error_msg(IS_SIGNED, sizeof(nc_u16), "nc_ptr_u16");
        return (nc_ptr_u16){.ptr = NULL};
    }

    *heap_val = val;
    return (nc_ptr_u16){.ptr = heap_val};
}

/* nc_ptr_u16's runtime fail constructor */
static inline nc_ptr_u16 nc_new_must_ptr_u16(nc_u16 val) {
    nc_u16* heap_val = malloc(sizeof(nc_u16));

    if (!heap_val) {
        send_allocation_must_error_msg(IS_SIGNED, sizeof(nc_u16), "nc_ptr_u16");
        exit(1);
    }

    *heap_val = val;
    return (nc_ptr_u16){.ptr = heap_val};
}

/* nc_ptr_u32's constructor */
static inline nc_ptr_u32 nc_new_ptr_u32(nc_u32 val) {
    nc_u32* heap_val = malloc(sizeof(nc_u32));

    if (!heap_val) {
        send_allocation_error_msg(IS_SIGNED, sizeof(nc_u32), "nc_ptr_u32");
        return (nc_ptr_u32){.ptr = NULL};
    }

    *heap_val = val;
    return (nc_ptr_u32){.ptr = heap_val};
}

/* nc_ptr_u32's runtime fail constructor */
static inline nc_ptr_u32 nc_new_must_ptr_u32(nc_u32 val) {
    nc_u32* heap_val = malloc(sizeof(nc_u32));

    if (!heap_val) {
        send_allocation_must_error_msg(IS_SIGNED, sizeof(nc_u32), "nc_ptr_u32");
        exit(1);
    }

    *heap_val = val;
    return (nc_ptr_u32){.ptr = heap_val};
}

/* nc_ptr_u64's constructor */
static inline nc_ptr_u64 nc_new_ptr_u64(nc_u64 val) {
    nc_u64* heap_val = malloc(sizeof(nc_u64));

    if (!heap_val) {
        send_allocation_error_msg(IS_SIGNED, sizeof(nc_u64), "nc_ptr_u64");
        return (nc_ptr_u64){.ptr = NULL};
    }

    *heap_val = val;
    return (nc_ptr_u64){.ptr = heap_val};
}

/* nc_ptr_u64's runtime fail constructor */
static inline nc_ptr_u64 nc_new_must_ptr_u64(nc_u64 val) {
    nc_u64* heap_val = malloc(sizeof(nc_u64));

    if (!heap_val) {
        send_allocation_must_error_msg(IS_SIGNED, sizeof(nc_u64), "nc_ptr_u64");
        exit(1);
    }

    *heap_val = val;
    return (nc_ptr_u64){.ptr = heap_val};
}

#endif /* NC_INT_CONSTRUCTORS_H */
