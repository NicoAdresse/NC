# About NC <->
NC (Has no meaning), also referred to as 'nc-lib', is a modern C library designed to bring modern programming concepts to C, focusing on safety, predictability, and developer ergonomics.

**Current Version:** *0.0.1* (Work In Progress)

***DISCLAIMER: NC does not guarantee absolute memory safety or thread safety.***

## What Does NC Code Look Like? <->
Instead of complex object models or operator overloading, NC focuses on explicit, expressive function composition and type wrapping.

For example:

```c
#include <stdio.h>
#include "nc.h"

int main(void) {
    nc_i8 x = nc_new((int8_t)15);
    nc_i8 y = nc_new((int8_t)30);

    // If an overflow/underflow occurs, it safely defaults to NC_I8_MAX or NC_I8_MIN.
    printf("%d\n", nc_get_val(nc_checked_add(x, y))); 

    return 0;
}
```

This keeps code concise and expressive, providing modern safety features and predictable behavior without the weight of a heavy runtime environment.
