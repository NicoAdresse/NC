# NC Integer API Documentation <->

## Overview <->

The NC Integer API provides type-safe, checked arithmetic operations for signed and unsigned integers of various sizes (8-bit, 16-bit, 32-bit, 64-bit), as well as pointer types. All operations include overflow/underflow detection and consistent error handling.

## Table of Contents <->

1. [Data Types](#data-types)
2. [Constructors](#constructors)
3. [Memory Management (Pointers)](#memory-management-pointers)
4. [Arithmetic Operations](#arithmetic-operations)
5. [Utility Functions](#utility-functions)
6. [Type Conversion](#type-conversion)
7. [Error Handling](#error-handling)
8. [Testing & Assertions](#testing--assertions)
9. [Examples](#examples)

---

## Data Types <->

### Signed Integer Types <->

- `nc_i8` — 8-bit signed integer (-128 to 127)
- `nc_i16` — 16-bit signed integer (-32,768 to 32,767)
- `nc_i32` — 32-bit signed integer (-2,147,483,648 to 2,147,483,647)
- `nc_i64` — 64-bit signed integer

### Unsigned Integer Types <->

- `nc_u8` — 8-bit unsigned integer (0 to 255)
- `nc_u16` — 16-bit unsigned integer (0 to 65,535)
- `nc_u32` — 32-bit unsigned integer (0 to 4,294,967,295)
- `nc_u64` — 64-bit unsigned integer

### Pointer Types <->

- `nc_ptr_i8`, `nc_ptr_i16`, `nc_ptr_i32`, `nc_ptr_i64` — Pointers to signed integers
- `nc_ptr_u8`, `nc_ptr_u16`, `nc_ptr_u32`, `nc_ptr_u64` — Pointers to unsigned integers

### Type Structure <->

All integer types follow the same structure:

```c
typedef struct {
    <base_type> val;  // int8_t, int16_t, int32_t, int64_t, etc.
} nc_i8;  // (example for nc_i8)
```

### Pointer Type Structure <->

```c
typedef struct {
    <base_type> *ptr;  // int16_t*, int32_t*, etc.
} nc_ptr_i16;  // (example for nc_ptr_i16)
```

---

## Constructors <->

### Direct Value Constructors <->

#### `nc_new_i8(val)` / `nc_new_i16(val)` / `nc_new_i32(val)` / `nc_new_i64(val)`
#### `nc_new_u8(val)` / `nc_new_u16(val)` / `nc_new_u32(val)` / `nc_new_u64(val)`

Creates a type-safe integer wrapper from a native C integer value.

```c
nc_i16 val_a = nc_new_i16(10);
nc_i16 val_b = nc_new_i16(5);
nc_i16 val_zero = nc_new_i16(0);
nc_i16 val_max = nc_new_i16(NC_I16_MAX);
```

**Error Conditions:**
- Returns 0 if input overflows the target type's bounds

### Generic Constructor <->

#### `nc_new_int(val)`

Type-generic macro that automatically selects the correct constructor based on the input type.

```c
nc_i8 a = nc_new_int((int8_t)5);      // Dispatches to nc_new_i8
nc_u32 b = nc_new_int((uint32_t)100); // Dispatches to nc_new_u32
nc_i64 c = nc_new_int((int64_t)-999); // Dispatches to nc_new_i64
```

### Fatal Constructors <->

#### `nc_new_must_i8(val)` / ... / `nc_new_must_i64(val)`
#### `nc_new_must_u8(val)` / ... / `nc_new_must_u64(val)`
#### `nc_new_must_int(val)`

**Fatal** constructors that exit the program if the value cannot be safely stored.

```c
nc_i16 safe = nc_new_must_i16(100);  // OK
nc_i16 fail = nc_new_must_i16(40000); // Overflow, program exits
```

---

## Memory Management (Pointers) <->

### Pointer Constructors <->

#### `nc_new_ptr_i8(ptr)` / `nc_new_ptr_i16(ptr)` / ... / `nc_new_ptr_i64(ptr)`
#### `nc_new_ptr_u8(ptr)` / ... / `nc_new_ptr_u64(ptr)`

Creates a type-safe pointer wrapper for dynamically allocated integers.

```c
nc_ptr_i16 ptr_a = nc_new_ptr_i16(val_a);
nc_ptr_i16 ptr_max = nc_new_ptr_i16(val_max);
nc_ptr_i16 ptr_null = {.ptr = NULL};  // Null pointer
```

**Structure:**
```c
typedef struct {
    int16_t *ptr;
} nc_ptr_i16;
```

### Generic Pointer Constructor <->

#### `nc_new_ptr_int(ptr)`

Type-generic macro for creating pointer wrappers.

```c
int32_t *raw = malloc(sizeof(int32_t));
nc_ptr_i32 safe_ptr = nc_new_ptr_int(raw);
```

### Fatal Pointer Constructor <->

#### `nc_new_must_ptr_int(ptr)`

Exits if pointer is NULL or invalid.

```c
nc_ptr_i32 safe_ptr = nc_new_must_ptr_int(raw_ptr);
```

### Memory Deallocation <->

#### `nc_free_ptr_i8(ptr)` / ... / `nc_free_ptr_i64(ptr)`
#### `nc_free_int(ptr)`

Safely deallocates memory for pointer types.

```c
nc_ptr_i16 ptr_a = nc_new_ptr_i16(val_a);
// ... use pointer ...
nc_free_ptr_i16(ptr_a);  // Safe deallocation
```

---

## Arithmetic Operations <->

All arithmetic operations are **type-generic** using `_Generic`. The same macro works for both direct integers and pointer types.

### Addition <->

#### Direct: `nc_checked_add_i8(n1, n2)` / `nc_checked_add_i16(n1, n2)` / ... / `nc_checked_add_i64(n1, n2)`
#### Generic: `nc_checked_add_int(n1, n2)`
#### Pointer: `nc_checked_add_ptr_i16(ptr, val)` (pointer + value)

Adds two integers or a pointer and a value, with overflow detection.

```c
nc_i16 val_a = nc_new_i16(10);
nc_i16 val_b = nc_new_i16(5);
nc_ptr_i16 ptr_a = nc_new_ptr_i16(val_a);

// Direct addition
nc_i16 result = nc_checked_add_int(val_a, val_b);  // 15

// Pointer addition
nc_ptr_i16 res_add = nc_checked_add_ptr_i16(ptr_a, val_b);
printf("10 + 5 = %d\n", nc_get_val_int(*res_add.ptr));  // 15
```

**Error Conditions:**
- Result exceeds maximum value → error, returns 0
- Result below minimum value → error, returns 0

**Overflow Example:**
```c
nc_i16 val_max = nc_new_i16(NC_I16_MAX);  // 32767
nc_i16 val_b = nc_new_i16(5);

nc_ptr_i16 res_overflow = nc_checked_add_ptr_i16(ptr_max, val_b);
printf("32767 + 5 -> Expected: clamped | Got: %d\n", 
       nc_get_val_int(*res_overflow.ptr));  // Error, returns 0
```

### Subtraction <->

#### Direct: `nc_checked_sub_i8(n1, n2)` / ... / `nc_checked_sub_i64(n1, n2)`
#### Generic: `nc_checked_sub_int(n1, n2)`
#### Pointer: `nc_checked_sub_ptr_i16(ptr, val)`

Subtracts two integers or a pointer and a value, with underflow detection.

```c
nc_i16 val_a = nc_new_i16(10);
nc_i16 val_b = nc_new_i16(5);
nc_ptr_i16 ptr_a = nc_new_ptr_i16(val_a);

nc_ptr_i16 res_sub = nc_checked_sub_ptr_i16(ptr_a, val_b);
printf("10 - 5 = %d\n", nc_get_val_int(*res_sub.ptr));  // 5
```

**Error Conditions:**
- Result exceeds maximum value → error, returns 0
- Result below minimum value → error, returns 0

### Multiplication <->

#### Direct: `nc_checked_mul_i8(n1, n2)` / ... / `nc_checked_mul_i64(n1, n2)`
#### Generic: `nc_checked_mul_int(n1, n2)`
#### Pointer: `nc_checked_mul_ptr_i16(ptr, val)`

Multiplies two integers with overflow detection.

```c
nc_i16 val_a = nc_new_i16(10);
nc_i16 val_b = nc_new_i16(5);
nc_ptr_i16 ptr_a = nc_new_ptr_i16(val_a);

nc_ptr_i16 res_mul = nc_checked_mul_ptr_i16(ptr_a, val_b);
printf("10 * 5 = %d\n", nc_get_val_int(*res_mul.ptr));  // 50
```

**Error Conditions:**
- Result overflows → error, returns 0
- Result underflows → error, returns 0

### Division <->

#### Direct: `nc_checked_div_i8(n1, n2, is_zero_division_allowed)` / ... / `nc_checked_div_i64(n1, n2, is_zero_division_allowed)`
#### Generic: `nc_checked_div_int(n1, n2, is_zero_division_allowed)`
#### Pointer: `nc_checked_div_ptr_i16(ptr, val, is_zero_division_allowed)`

Divides two integers with division-by-zero protection.

```c
nc_i16 val_a = nc_new_i16(10);
nc_i16 val_b = nc_new_i16(5);
nc_i16 val_zero = nc_new_i16(0);
nc_ptr_i16 ptr_a = nc_new_ptr_i16(val_a);

// Normal division
nc_ptr_i16 res_div = nc_checked_div_ptr_i16(ptr_a, val_b, 0);
printf("10 / 5 = %d\n", nc_get_val_int(*res_div.ptr));  // 2

// Division by zero (disallowed)
nc_ptr_i16 res_div_zero = nc_checked_div_ptr_i16(ptr_a, val_zero, 0);
printf("10 / 0 = %d\n", nc_get_val_int(*res_div_zero.ptr));  // Error, returns 0
```

**Parameters:**
- `n1` / `ptr` — dividend (numerator)
- `n2` / `val` — divisor (denominator)
- `is_zero_division_allowed` — 0 to reject division by zero, non-zero to allow

**Error Conditions:**
- Divisor is 0 and `is_zero_division_allowed == 0` → error, returns 0
- Result causes overflow (e.g., MIN_INT / -1) → error, returns 0

### Modulo (Remainder) <->

#### Direct: `nc_checked_mod_i8(n1, n2, is_zero_division_allowed)` / ... / `nc_checked_mod_i64(n1, n2, is_zero_division_allowed)`
#### Generic: `nc_checked_mod_int(n1, n2, is_zero_division_allowed)`
#### Pointer: `nc_checked_mod_ptr_i16(ptr, val, is_zero_division_allowed)`

Computes the remainder of integer division.

```c
nc_i16 val_a = nc_new_i16(10);
nc_i16 val_b = nc_new_i16(3);

nc_i16 rem = nc_checked_mod_int(val_a, val_b, 0);
printf("10 %% 3 = %d\n", nc_get_val_int(rem));  // 1

// With assertion
nc_assert_eq(nc_get_val_int(nc_checked_mod_int(val_a, val_b, 0)), 1);
```

**Parameters:**
- `n1` — dividend
- `n2` — divisor
- `is_zero_division_allowed` — 0 to reject modulo by zero

**Note:** Remainder has the same sign as the dividend.

**Error Conditions:**
- Divisor is 0 and `is_zero_division_allowed == 0` → error, returns 0

---

## Utility Functions <->

### Signum <->

#### `nc_signum_i8(n)` / ... / `nc_signum_i64(n)`
#### `nc_signum_u8(n)` / ... / `nc_signum_u64(n)`
#### `nc_signum_int(n)`

Returns the sign of an integer as a new wrapped integer.

```c
nc_i16 val_a = nc_new_i16(10);
nc_i16 sign = nc_signum_int(val_a);
printf("SIGNUM(10) = %d\n", nc_get_val_int(sign));  // 1

nc_i16 val_neg = nc_new_i16(-42);
nc_i16 sign_neg = nc_signum_int(val_neg);
printf("SIGNUM(-42) = %d\n", nc_get_val_int(sign_neg));  // -1

nc_i16 val_zero = nc_new_i16(0);
nc_i16 sign_zero = nc_signum_int(val_zero);
printf("SIGNUM(0) = %d\n", nc_get_val_int(sign_zero));  // 0
```

**Return Values:**
- `1` for positive numbers
- `-1` for negative numbers
- `0` for zero

**Note:** For unsigned types, signum returns 1 for any positive value, 0 for zero.

### Value Retrieval <->

#### `nc_get_val_i8(x)` / ... / `nc_get_val_i64(x)`
#### `nc_get_val_int(x)`

Extracts the raw value from a wrapped integer (works with pointers too).

```c
nc_i16 wrapped = nc_new_i16(42);
int16_t raw = nc_get_val_int(wrapped);  // 42

nc_ptr_i16 ptr = nc_new_ptr_i16(wrapped);
int16_t ptr_val = nc_get_val_int(*ptr.ptr);  // Dereference then get value
```

### Size Information <->

#### `nc_get_size_i8()` / ... / `nc_get_size_i64()`
#### `nc_get_size_int(x)`

Returns the size in bytes of the integer type.

```c
nc_i16 x = nc_new_i16(0);
size_t size = nc_get_size_int(x);  // 2 (bytes)
```

---

## Type Conversion <->

### `nc_convert_int(target_type, val)`

Safely converts between different integer types with overflow/underflow checking.

```c
nc_i32 large = nc_new_int((int32_t)1000);
nc_i8 small = nc_convert_int(nc_i8, large);  // Converts to nc_i8

nc_i8 neg = nc_new_int((int8_t)-5);
nc_u8 unsigned_val = nc_convert_int(nc_u8, neg);  // Error! Negative can't fit in unsigned
```

**Parameters:**
- `target_type` — the type to convert to (e.g., `nc_i8`, `nc_u32`)
- `val` — the value to convert

**Error Conditions:**
- Target type cannot hold the source value → error, returns 0

**Supported Conversions:**
- Between any signed and unsigned types
- Between any size combinations (i8 ↔ i16 ↔ i32 ↔ i64, etc.)

---

## Error Handling <->

All checked operations follow a consistent error handling pattern:

1. **Operation execution** — Perform the arithmetic
2. **Boundary checking** — Validate result fits in target type
3. **Error reporting** — Call appropriate error handler
4. **Safe return** — Return 0 on error (or special value)

### Error Functions <->

- `send_bounds_error_msg()` — Reports general integer boundary errors
- `send_bounds_ptr_error_msg()` — Reports general integer boundary errors (ptr version)
- `send_constructor_error_msg()` — Reports general integer constructor failure
- `send_constructor_runtime_fail_error_msg()` — Reports general integer constructor failure, crashes at runtime
- `send_zero_denominator_error_msg()` — Reports if zero division wasn't allowed
- `send_allocation_error_msg()` — Reports if memory allocated failed
- `send_allocation_must_error_msg()` — Reports if memory allocated failed, crashes at runtime
- `send_null_pointer_error_msg()` — Reports if a null pointer was detected


### Error Types <->

Common error codes:
- `ERROR_OVERFLOW` — Result exceeded maximum value
- `ERROR_UNDERFLOW` — Result below minimum value

---

## Testing & Assertions <->

The NC Integer API includes testing utilities for validation:

### Assertions <->

#### `nc_assert_eq(actual, expected)`

Asserts that `actual` equals `expected`. Fails with error message if not.

```c
nc_assert_eq(nc_get_val_int(nc_checked_mod_int(val_a, val_b, 0)), 0);
// Passes if actual modulo result equals 0
```

### Debug Logging <->

#### `nc_debug_log(message)`

Logs a debug message (typically only in debug builds).

```c
nc_debug_log("Should appear if successful.");
```

---

## Examples <->

### Complete Test Example

This demonstrates the full workflow with various operations:

```c
#include "nc/nc_int_types.h"
#include <stdio.h>

int main(void) {
    // Create values
    nc_i16 val_a = nc_new_i16(10);
    nc_i16 val_b = nc_new_i16(5);
    nc_i16 val_zero = nc_new_i16(0);
    nc_i16 val_max = nc_new_i16(NC_I16_MAX);  // 32767
    
    // Create pointers
    nc_ptr_i16 ptr_a = nc_new_ptr_i16(val_a);
    nc_ptr_i16 ptr_max = nc_new_ptr_i16(val_max);
    nc_ptr_i16 ptr_null = {.ptr = NULL};
    
    printf("=== SUCCESS CASES (i16) ===\n");
    
    // Addition
    nc_ptr_i16 res_add = nc_checked_add_ptr_i16(ptr_a, val_b);
    printf("ADD [10 + 5] -> Expected: 15 | Got: %d\n", 
           nc_get_val_int(*res_add.ptr));
    
    // Subtraction
    nc_ptr_i16 res_sub = nc_checked_sub_ptr_i16(ptr_a, val_b);
    printf("SUB [10 - 5] -> Expected: 5 | Got: %d\n", 
           nc_get_val_int(*res_sub.ptr));
    
    // Multiplication
    nc_ptr_i16 res_mul = nc_checked_mul_ptr_i16(ptr_a, val_b);
    printf("MUL [10 * 5] -> Expected: 50 | Got: %d\n", 
           nc_get_val_int(*res_mul.ptr));
    
    // Division
    nc_ptr_i16 res_div = nc_checked_div_ptr_i16(ptr_a, val_b, 0);
    printf("DIV [10 / 5] -> Expected: 2 | Got: %d\n", 
           nc_get_val_int(*res_div.ptr));
    
    // Modulo
    nc_i16 mod_result = nc_checked_mod_int(val_a, val_b, 0);
    printf("MOD [10 % 5] -> Expected: 0 | Got: %d\n", 
           nc_get_val_int(mod_result));
    
    // Signum
    printf("SIGNUM(10) -> Expected: 1 | Got: %d\n", 
           nc_get_val_int(nc_signum_int(val_a)));
    
    printf("\n=== ERROR CASES (i16) ===\n");
    
    // Overflow
    nc_ptr_i16 res_overflow = nc_checked_add_ptr_i16(ptr_max, val_b);
    printf("ADD Overflow [32767 + 5] -> Expected: error (0) | Got: %d\n", 
           nc_get_val_int(*res_overflow.ptr));
    
    // Division by zero
    nc_ptr_i16 res_div_zero = nc_checked_div_ptr_i16(ptr_a, val_zero, 0);
    printf("DIV Zero [10 / 0] -> Expected: error (0) | Got: %d\n", 
           nc_get_val_int(*res_div_zero.ptr));
    
    // Null pointer
    nc_ptr_i16 res_null = nc_checked_add_ptr_i16(ptr_null, val_b);
    printf("ADD Null Pointer -> Expected: NULL | Got: %p\n", 
           (void*)res_null.ptr);
    
    // Assertions
    nc_assert_eq(nc_get_val_int(nc_checked_mod_int(val_a, val_b, 0)), 0);
    nc_debug_log("Assertion passed!");
    
    // Cleanup
    nc_free_ptr_i16(ptr_a);
    nc_free_ptr_i16(ptr_max);
    nc_free_ptr_i16(ptr_null);
    nc_free_ptr_i16(res_add);
    nc_free_ptr_i16(res_sub);
    nc_free_ptr_i16(res_mul);
    nc_free_ptr_i16(res_div);
    nc_free_ptr_i16(res_div_zero);
    nc_free_ptr_i16(res_null);
    nc_free_ptr_i16(res_overflow);
    
    return 0;
}
```

### Type-Generic Operations <->

```c
// Works seamlessly with all integer types
nc_i8 a8 = nc_new_i8(5);
nc_i32 a32 = nc_new_i32(5);
nc_i64 a64 = nc_new_i64(5);

// Same macro works for all types
nc_i8 result8 = nc_checked_add_int(a8, a8);
nc_i32 result32 = nc_checked_add_int(a32, a32);
nc_i64 result64 = nc_checked_add_int(a64, a64);
```

### Pointer Arithmetic <->

```c
nc_i32 value = nc_new_i32(100);
nc_ptr_i32 ptr = nc_new_ptr_i32(value);

// Use pointer arithmetic
nc_ptr_i32 incremented = nc_checked_add_ptr_i32(ptr, nc_new_i32(50));
printf("100 + 50 = %d\n", nc_get_val_int(*incremented.ptr));  // 150

// Clean up
nc_free_ptr_i32(ptr);
nc_free_ptr_i32(incremented);
```

---

## Design Philosophy <->

- **Type Safety:** Wrapped types prevent mixing nc_i32 with plain int
- **Comprehensive Validation:** All arithmetic checks for overflow/underflow
- **Multiple Sizes:** Support for i8, i16, i32, i64 (signed and unsigned)
- **Pointer Support:** Type-safe pointers with arithmetic operations
- **Type Generic:** Single macro works for all integer types
- **Consistent API:** All operations follow the same error handling pattern
- **Testability:** Built-in assertions and debug logging

---

## Constants <->

Common constants for boundary checking:

```c
NC_I8_MAX   // 127
NC_I8_MIN   // -128
NC_I16_MAX  // 32767
NC_I16_MIN  // -32768
NC_I32_MAX  // 2147483647
NC_I32_MIN  // -2147483648
NC_I64_MAX  // 9223372036854775807
NC_I64_MIN  // -9223372036854775808

NC_U8_MAX   // 255
NC_U16_MAX  // 65535
NC_U32_MAX  // 4294967295
NC_U64_MAX  // 18446744073709551615
```

---

## See Also <->

- `nc_int_types.h` — Main include file for all integer types
- `nc_i8/nc_i8.h`, `nc_i16/nc_i16.h`, `nc_i32/nc_i32.h`, `nc_i64/nc_i64.h` — Signed implementations
- `nc_u8/nc_u8.h`, `nc_u16/nc_u16.h`, `nc_u32/nc_u32.h`, `nc_u64/nc_u64.h` — Unsigned implementations
- `nc_ptr_i*/nc_ptr_i*.h`, `nc_ptr_u*/nc_ptr_u*.h` — Pointer implementations
- `nc_int_method_macros.h` — Generic macro definitions