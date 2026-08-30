/* src/nc/nc_int_types.h */

/*
    About: Header file for all NC datatypes and their methods.
    Initial Commit: INIT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#ifndef NC_INT_TYPES_H
#define NC_INT_TYPES_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Datatypes declarations */
typedef struct {
    int8_t val;
} nc_i8;

typedef struct {
    uint8_t val;
} nc_u8;

typedef struct {
    int16_t val;
} nc_i16;

typedef struct {
    uint16_t val;
} nc_u16;

typedef struct {
    int32_t val;
} nc_i32;

typedef struct {
    uint32_t val;
} nc_u32;

/* Helper Structs & Enums */
typedef enum {
    ERROR_OVERFLOW,
    ERROR_UNDERFLOW
} error_int_bound_t;

/* Helper Functions */
static inline int check_overflow(int64_t val, int64_t max) { return val > max; }
static inline int check_underflow(int64_t val, int64_t min) { return val < min; }

static inline void send_bounds_error_msg(
    int number_of_bits,
    int is_integer_signed,
    int64_t number_one_val,
    int64_t number_two_val,
    error_int_bound_t overflow_type,
    int64_t bounds_max
) {
    fprintf(stderr,
        "Error. %s Integer (%d Bits) %s detected. Check your variables. (Values received: %lld & %lld). Defaulting to %lld.\n",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (overflow_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        (long long)number_one_val,
        (long long)number_two_val,
        (long long)bounds_max
    );
}

static inline void send_constructor_error_msg(
    int number_of_bits,
    int is_integer_signed,
    error_int_bound_t overflow_type,
    int64_t val,
    int64_t bounds_max
) {
    fprintf(stderr,
        "Error. %s Integer (%d Bits) %s detected. Construction failed. (Value received: %ld) Defaulting to %ld.\n",
        is_integer_signed ? "Signed" : "Unsigned",
        number_of_bits,
        (overflow_type == ERROR_OVERFLOW) ? "overflow" : "underflow",
        val,
        bounds_max
    );
}

/* Helper Macros */
/* Signed / Unsigned */
#define IS_SIGNED 1
#define IS_UNSIGNED 0
#define UNSIGNED_MIN 0

/* Integer Value Sizes */
#define NC_I8_MAX 127
#define NC_I8_MIN -128
#define NC_U8_MAX 255

#define NC_I16_MAX 32767
#define NC_I16_MIN -32768
#define NC_U16_MAX 65535

#define NC_I32_MAX 2147483647
#define NC_I32_MIN -2147483648
#define NC_U32_MAX 4294967295

/* Constructors */
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

/* nc_u8's constructor */
static inline nc_u8 nc_new_u8(int64_t val) {
    if (check_overflow(val, NC_U8_MAX)) {
        send_constructor_error_msg(8, IS_UNSIGNED, ERROR_OVERFLOW, val, NC_U8_MAX);
        return (nc_u8){.val = (uint8_t)NC_U8_MAX};
    }

    if (check_underflow(val, UNSIGNED_MIN)) {
        send_constructor_error_msg(8, IS_UNSIGNED, ERROR_UNDERFLOW, val, UNSIGNED_MIN);
        return (nc_u8){.val = (uint8_t)UNSIGNED_MIN};
    }

    return (nc_u8){.val = (uint8_t)val};
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

/* nc_u16's constructor */
static inline nc_u16 nc_new_u16(int64_t val) {
    if (check_overflow(val, NC_U16_MAX)) {
        send_constructor_error_msg(16, IS_UNSIGNED, ERROR_OVERFLOW, val, NC_U16_MAX);
        return (nc_u16){.val = (uint16_t)NC_U16_MAX};
    }

    if (check_underflow(val, UNSIGNED_MIN)) {
        send_constructor_error_msg(16, IS_UNSIGNED, ERROR_UNDERFLOW, val, UNSIGNED_MIN);
        return (nc_u16){.val = (uint16_t)UNSIGNED_MIN};
    }

    return (nc_u16){.val = (uint16_t)val};
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

/* nc_u32's constructor */
static inline nc_u32 nc_new_u32(int64_t val) {
    if (check_overflow(val, NC_U32_MAX)) {
        send_constructor_error_msg(32, IS_UNSIGNED, ERROR_OVERFLOW, val, NC_U32_MAX);
        return (nc_u32){.val = (uint32_t)NC_U32_MAX};
    }

    if (check_underflow(val, UNSIGNED_MIN)) {
        send_constructor_error_msg(32, IS_UNSIGNED, ERROR_UNDERFLOW, val, UNSIGNED_MIN);
        return (nc_u32){.val = (uint32_t)UNSIGNED_MIN};
    }

    return (nc_u32){.val = (uint32_t)val};
}

/* Methods */
/* nc_get_val */
static inline int8_t nc_get_val_i8(nc_i8 primitive) { return primitive.val; }
static inline uint8_t nc_get_val_u8(nc_u8 primitive) { return primitive.val; }
static inline int16_t nc_get_val_i16(nc_i16 primitive) { return primitive.val; }
static inline uint16_t nc_get_val_u16(nc_u16 primitive) { return primitive.val; }
static inline int32_t nc_get_val_i32(nc_i32 primitive) { return primitive.val; }
static inline uint32_t nc_get_val_u32(nc_u32 primitive) { return primitive.val; }

/* nc_get_size */
static inline size_t nc_get_size_i8() { return sizeof(nc_i8); }
static inline size_t nc_get_size_u8() { return sizeof(nc_u8); }
static inline size_t nc_get_size_i16() { return sizeof(nc_i16); }
static inline size_t nc_get_size_u16() { return sizeof(nc_u16); }
static inline size_t nc_get_size_i32() { return sizeof(nc_i32); }
static inline size_t nc_get_size_u32() { return sizeof(nc_u32); }

/* Checked Additions */
/* Checked Addition -> nc_i8 */
static inline nc_i8 nc_checked_add_i8(nc_i8 number_one, nc_i8 number_two) {
    int64_t sum = (int64_t)number_one.val + (int64_t)number_two.val;

    if (check_overflow(sum, NC_I8_MAX)) {
        send_bounds_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I8_MAX);
        return (nc_i8){.val = (int8_t)NC_I8_MAX};
    }

    if (check_underflow(sum, NC_I8_MIN)) {
        send_bounds_error_msg(8, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I8_MIN);
        return (nc_i8){.val = (int8_t)NC_I8_MIN};
    }

    return (nc_i8){.val = (int8_t)sum};
}

/* Checked Addition -> nc_u8 */
static inline nc_u8 nc_checked_add_u8(nc_u8 number_one, nc_u8 number_two) {
    int64_t sum = (int64_t)number_one.val + (int64_t)number_two.val;

    if (check_overflow(sum, NC_U8_MAX)) {
        send_bounds_error_msg(8, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_U8_MAX);
        return (nc_u8){.val = (uint8_t)NC_U8_MAX};
    }

    if (check_underflow(sum, UNSIGNED_MIN)) {
        send_bounds_error_msg(8, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, UNSIGNED_MIN);
        return (nc_u8){.val = (uint8_t)UNSIGNED_MIN};
    }

    return (nc_u8){.val = (uint8_t)sum};
}

/* Checked Addition -> nc_i16 */
static inline nc_i16 nc_checked_add_i16(nc_i16 number_one, nc_i16 number_two) {
    int64_t sum = (int64_t)number_one.val + (int64_t)number_two.val;
    
    if (check_overflow(sum, NC_I16_MAX)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I16_MAX);
        return (nc_i16){.val = (int16_t)NC_I16_MAX};
    }

    if (check_underflow(sum, NC_I16_MIN)) {
        send_bounds_error_msg(16, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I16_MIN);
        return (nc_i16){.val = (int16_t)NC_I16_MIN};
    }

    return (nc_i16){.val = (int16_t)sum};
}

/* Checked Addition -> nc_u16 */
static inline nc_u16 nc_checked_add_u16(nc_u16 number_one, nc_u16 number_two) {
    int64_t sum = (int64_t)number_one.val + (int64_t)number_two.val;

    if (check_overflow(sum, NC_U16_MAX)) {
        send_bounds_error_msg(16, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_U16_MAX);
        return (nc_u16){.val = (uint16_t)NC_U16_MAX};  
    }

    if (check_underflow(sum, UNSIGNED_MIN)) {
        send_bounds_error_msg(16, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, UNSIGNED_MIN);
        return (nc_u16){.val = (uint16_t)UNSIGNED_MIN};  
    }

    return (nc_u16){.val = (uint16_t)sum};
}

/* Checked Addition -> nc_i32 */
static inline nc_i32 nc_checked_add_i32(nc_i32 number_one, nc_i32 number_two) {
    int64_t sum = (int64_t)number_one.val + (int64_t)number_two.val;

    if (check_overflow(sum, NC_I32_MAX)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_I32_MAX);
        return (nc_i32){.val = (int32_t)NC_I32_MAX};   
    }

    if (check_underflow(sum, NC_I32_MIN)) {
        send_bounds_error_msg(32, IS_SIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, NC_I32_MIN);
        return (nc_i32){.val = (int32_t)NC_I32_MIN};   
    }

    return (nc_i32){.val = (int32_t)sum};
}

/* Checked Addition -> nc_u32 */
static inline nc_u32 nc_checked_add_u32(nc_u32 number_one, nc_u32 number_two) {
    int64_t sum = (int64_t)number_one.val + (int64_t)number_two.val;

    if (check_overflow(sum, NC_U32_MAX)) {
        send_bounds_error_msg(32, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_OVERFLOW, NC_U32_MAX);
        return (nc_u32){.val = (uint32_t)NC_U32_MAX};  
    }

    if (check_underflow(sum, UNSIGNED_MIN)) {
        send_bounds_error_msg(32, IS_UNSIGNED, (int64_t)number_one.val, (int64_t)number_two.val, ERROR_UNDERFLOW, UNSIGNED_MIN);
        return (nc_u32){.val = (uint32_t)UNSIGNED_MIN};   
    }

    return (nc_u32){.val = (uint32_t)sum};
}

/* Macros */
#define nc_get_val(x) _Generic((x), \
    nc_i8: nc_get_val_i8, \
    nc_u8: nc_get_val_u8,  \
    nc_i16: nc_get_val_i16, \
    nc_u16: nc_get_val_u16, \
    nc_i32: nc_get_val_i32, \
    nc_u32: nc_get_val_u32, \
    default: nc_get_val_i32 \
)(x)

#define nc_get_size(x) _Generic((x), \
    nc_i8:  nc_get_size_i8(), \
    nc_u8:  nc_get_size_u8(), \
    nc_i16: nc_get_size_i16(), \
    nc_u16: nc_get_size_u16(), \
    nc_i32: nc_get_size_i32(), \
    nc_u32: nc_get_size_u32(), \
    default: nc_get_size_i32() \
)

#define nc_checked_add(n1, n2) _Generic((n1), \
    nc_i8: nc_checked_add_i8, \
    nc_u8: nc_checked_add_u8, \
    nc_i16: nc_checked_add_i16, \
    nc_u16: nc_checked_add_u16, \
    nc_i32: nc_checked_add_i32, \
    nc_u32: nc_checked_add_u32, \
    default: nc_checked_add_i32 \
)((n1), (n2))

#endif /* NC_INT_TYPES_H */