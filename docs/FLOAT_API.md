# NC Float API Documentation <->

## Overview <->

The NC Float API provides type-safe, checked floating-point arithmetic operations for both 32-bit (`nc_f32`) and 64-bit (`nc_f64`) floating-point numbers. All operations include comprehensive error handling for NaN, infinity, overflow, and underflow conditions.

## Table of Contents <->

1. [Data Types](#data-types)
2. [Constructors](#constructors)
3. [Arithmetic Operations](#arithmetic-operations)
4. [Utility Functions](#utility-functions)
5. [Error Handling](#error-handling)
6. [Examples](#examples)

---

## Data Types <->

### `nc_f32`

A type-safe wrapper around a 32-bit floating-point number.

```c
typedef struct {
    float val;
} nc_f32;
```

### `nc_f64`

A type-safe wrapper around a 64-bit floating-point number (double).

```c
typedef struct {
    double val;
} nc_f64;
```

---

## Constructors <->

### `nc_new_f32(double val)` / `nc_new_f64(double val)`

Creates an nc_f32 or nc_f64 from a double value. Returns 0.0 on error.

```c
nc_f32 a = nc_new_f32(3.14);
nc_f64 b = nc_new_f64(2.71828);
```

**Error Conditions:**
- Input is NaN → error reported, returns 0.0
- Input is Infinity → error reported, returns 0.0
- Overflow during conversion (f32 only) → error reported, returns 0.0

### `nc_new_must_f32(double val)` / `nc_new_must_f64(double val)`

**Fatal** constructor. Exits the program if input is invalid.

```c
nc_f32 a = nc_new_must_f32(3.14);  // Program exits if val is NaN or Inf
```

---

## Arithmetic Operations <->

All arithmetic operations are **type-generic** using `_Generic`. You can call the same macro name regardless of whether you're working with `nc_f32` or `nc_f64`.

### Addition <->

**Macro:** `nc_checked_add_float(n1, n2)`

Adds two floating-point numbers with overflow detection.

```c
nc_f32 a = nc_new_f32(5.0);
nc_f32 b = nc_new_f32(3.0);
nc_f32 result = nc_checked_add_float(a, b);  // 8.0
```

**Error Conditions:**
- Either operand is NaN → error, returns 0.0
- Either operand is Infinity → error, returns 0.0
- Result overflows to Infinity → error, returns 0.0

### Subtraction <->

**Macro:** `nc_checked_sub_float(n1, n2)`

Subtracts two floating-point numbers with overflow detection.

```c
nc_f32 a = nc_new_f32(5.0);
nc_f32 b = nc_new_f32(3.0);
nc_f32 result = nc_checked_sub_float(a, b);  // 2.0
```

**Error Conditions:**
- Either operand is NaN → error, returns 0.0
- Either operand is Infinity → error, returns 0.0
- Result overflows to Infinity → error, returns 0.0

### Multiplication <->

**Macro:** `nc_checked_mul_float(n1, n2)`

Multiplies two floating-point numbers with overflow detection.

```c
nc_f32 a = nc_new_f32(4.0);
nc_f32 b = nc_new_f32(2.5);
nc_f32 result = nc_checked_mul_float(a, b);  // 10.0
```

**Error Conditions:**
- Either operand is NaN → error, returns 0.0
- Either operand is Infinity → error, returns 0.0
- Result overflows to Infinity → error, returns 0.0

### Division <->

**Macro:** `nc_checked_div_float(n1, n2, is_zero_division_allowed)`

Divides two floating-point numbers.

```c
nc_f32 a = nc_new_f32(10.0);
nc_f32 b = nc_new_f32(2.0);
nc_f32 result = nc_checked_div_float(a, b, 0);  // 5.0
```

**Parameters:**
- `n1` — numerator
- `n2` — denominator
- `is_zero_division_allowed` — if 0, returns error on division by zero; if non-zero, allows Infinity result

**Error Conditions:**
- Either operand is NaN → error, returns 0.0
- Either operand is Infinity → error, returns 0.0
- `n2` is 0.0 and `is_zero_division_allowed == 0` → error, returns 0.0
- Result overflows to Infinity → error, returns 0.0

### Modulo (Remainder) <->

**Macro:** `nc_checked_mod_float(n1, n2, is_zero_division_allowed)`

Computes the floating-point remainder using `fmod()`.

```c
nc_f32 a = nc_new_f32(5.5);
nc_f32 b = nc_new_f32(2.0);
nc_f32 result = nc_checked_mod_float(a, b, 0);  // 1.5
```

**Parameters:**
- `n1` — dividend
- `n2` — divisor
- `is_zero_division_allowed` — if 0, returns error on division by zero

**Note:** `fmod` returns a remainder with the same sign as the dividend.

**Error Conditions:**
- Either operand is NaN → error, returns 0.0
- Either operand is Infinity → error, returns 0.0
- `n2` is 0.0 and `is_zero_division_allowed == 0` → error, returns 0.0
- Result is Infinity → error, returns 0.0

---

## Utility Functions <->

### Signum <->

**Macro:** `nc_checked_signum_float(n)`

Returns the sign of a floating-point number as 1.0, -1.0, or 0.0.

```c
nc_f32 a = nc_new_f32(5.0);
nc_f32 sign = nc_checked_signum_float(a);  // 1.0

nc_f32 b = nc_new_f32(-3.0);
nc_f32 sign = nc_checked_signum_float(b);  // -1.0

nc_f32 c = nc_new_f32(0.0);
nc_f32 sign = nc_checked_signum_float(c);  // 0.0
```

**Error Conditions:**
- Input is NaN → error, returns 0.0
- Input is Infinity → error, returns 0.0

---

## Error Handling <->

All checked operations follow a consistent error handling pattern:

1. **Input validation** — NaN and Infinity checks on operands
2. **Operation execution** — perform the arithmetic
3. **Result validation** — check for overflow/underflow
4. **Error reporting** — call `send_float_error()` or `send_float_error_overflow()`
5. **Safe return** — return 0.0 on any error

### Error Functions <->

- `send_float_error(bits, error_type, val1, val2)` — Reports input validation errors
- `send_float_error_overflow(bits, result)` — Reports overflow/underflow errors
- `send_float_zero_denominator_error_msg(val1, val2)` — Reports division by zero

### Error Types <->

- `ERROR_ISNAN` — Input is NaN
- `ERROR_ISINF` — Input is Infinity

---

## Examples <->

### Basic Arithmetic <->

```c
#include "nc_float/nc_float_method_macros.h"

int main() {
    // Create nc_f32 values
    nc_f32 x = nc_new_f32(10.0);
    nc_f32 y = nc_new_f32(3.0);
    
    // Perform checked arithmetic
    nc_f32 sum = nc_checked_add_float(x, y);      // 13.0
    nc_f32 diff = nc_checked_sub_float(x, y);     // 7.0
    nc_f32 prod = nc_checked_mul_float(x, y);     // 30.0
    nc_f32 quot = nc_checked_div_float(x, y, 0);  // 3.333...
    nc_f32 rem = nc_checked_mod_float(x, y, 0);   // 1.0
    
    return 0;
}
```

### Type-Generic Operations <->

```c
// Works seamlessly with both nc_f32 and nc_f64
nc_f32 a32 = nc_new_f32(5.0);
nc_f64 a64 = nc_new_f64(5.0);

// Same macro works for both types
nc_f32 result32 = nc_checked_add_float(a32, a32);
nc_f64 result64 = nc_checked_add_float(a64, a64);
```

### Error Handling <->

```c
nc_f32 x = nc_new_f32(10.0);
nc_f32 zero = nc_new_f32(0.0);

// Division by zero (not allowed)
nc_f32 result = nc_checked_div_float(x, zero, 0);
// Error reported, result is 0.0

// Division by zero (allowed)
nc_f32 result = nc_checked_div_float(x, zero, 1);
// Result is Infinity (but will fail overflow check)
```

---

## Design Philosophy <->

- **Type Safety:** Wrapped types prevent mixing nc_f32 with plain floats
- **Comprehensive Validation:** All inputs and results are checked
- **Consistent Errors:** All operations follow the same error reporting pattern
- **Type Generic:** Single macro works for both f32 and f64
- **Defensive:** NaN and Infinity are treated as errors by default

---

## Implementation Details <->

### Internal Functions <->

Each macro dispatches to type-specific implementations:

- `nc_f32` operations → `nc_checked_add_f32()`, `nc_checked_sub_f32()`, etc.
- `nc_f64` operations → `nc_checked_add_f64()`, `nc_checked_sub_f64()`, etc.

All implementations are `static inline` for performance.

### Validation Pattern <->

```c
static inline nc_f32 nc_checked_add_f32(nc_f32 n1, nc_f32 n2) {
    // 1. Validate inputs
    if (isnan(n1.val) || isnan(n2.val)) {
        send_float_error(32, ERROR_ISNAN, ...);
        return (nc_f32){.val = 0.0};
    }
    
    // 2. Perform operation
    float sum = n1.val + n2.val;
    
    // 3. Validate result
    if (isinf(sum)) {
        send_float_error_overflow(32, (double)sum);
        return (nc_f32){.val = 0.0};
    }
    
    // 4. Return result
    return (nc_f32){.val = sum};
}
```

---

## See Also <->

- `nc_float_primitives.h` — Type definitions
- `nc_f32/nc_f32.h` — 32-bit implementations
- `nc_f64/nc_f64.h` — 64-bit implementations
- `nc_float_constructors.h` — Constructor implementations