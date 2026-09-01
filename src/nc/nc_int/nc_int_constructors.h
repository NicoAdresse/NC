/* src/nc/nc_int/nc_int_constructors.h */

/*
    About: Header file for the primitive datatypes' constructors.
    Initial Commit: NC_INT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
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

/* nc_i16 runtime fail constructor */
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

/* nc_i32 runtime fail constructor */
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
    if (check_overflow(val, NC_I64_MAX)) {
        send_constructor_error_msg(64, IS_SIGNED, ERROR_OVERFLOW, val, NC_I64_MAX);
        return (nc_i64){.val = (int64_t)NC_I64_MAX};
    }

    if (check_underflow(val, NC_I64_MIN)) {
        send_constructor_error_msg(64, IS_SIGNED, ERROR_UNDERFLOW, val, NC_I64_MIN);
        return (nc_i64){.val = (int64_t)NC_I64_MIN};
    }

    return (nc_i64){.val = val};
}

/* nc_i64 runtime fail constructor */
static inline nc_i64 nc_new_must_i64(int64_t val) {
    if (check_overflow(val, NC_I64_MAX)) {
        send_constructor_error_msg(64, IS_SIGNED, ERROR_OVERFLOW, val, NC_I64_MAX);
        exit(1);
    }

    if (check_underflow(val, NC_I64_MIN)) {
        send_constructor_error_msg(64, IS_SIGNED, ERROR_UNDERFLOW, val, NC_I64_MIN);
        exit(1);
    }

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

/* nc_u8 runtime fail constructor */
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

/* nc_u16 runtime fail constructor */
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

/* nc_u32 runtime fail constructor */
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
    if (check_overflow(val, NC_U64_MAX)) {
        send_constructor_error_msg(64, IS_UNSIGNED, ERROR_OVERFLOW, val, NC_U64_MAX);
        return (nc_u64){.val = (uint64_t)NC_U64_MAX};
    }

    if (check_underflow(val, NC_UNSIGNED_MIN)) {
        send_constructor_error_msg(64, IS_UNSIGNED, ERROR_UNDERFLOW, val, NC_UNSIGNED_MIN);
        return (nc_u64){.val = (uint64_t)NC_UNSIGNED_MIN};
    }

    return (nc_u64){.val = val};
}

/* nc_u64 runtime fail constructor */
static inline nc_u64 nc_new_must_u64(uint64_t val) {
    if (check_overflow(val, NC_U64_MAX)) {
        send_constructor_error_msg(64, IS_UNSIGNED, ERROR_OVERFLOW, val, NC_U64_MAX);
        exit(1);
    }

    if (check_underflow(val, NC_UNSIGNED_MIN)) {
        send_constructor_error_msg(64, IS_UNSIGNED, ERROR_UNDERFLOW, val, NC_UNSIGNED_MIN);
        exit(1);
    }

    return (nc_u64){.val = val};
}

#endif /* NC_INT_CONSTRUCTORS_H */