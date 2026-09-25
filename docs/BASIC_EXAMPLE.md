# Basic Example <->

This document is meant to show you, how an ***'basic example'*** (or multiple examples) looks like, so you can get a feeling on what NC is meant to do.

### Printing To The Console
```c
int main(void) {
    nc_println("Hello, World!");
    /* nc_printlns definition can be found in src/nc/nc_log/nc_print_stmts.h. */
}
```

Expected result:
```text
Hello, World!
```

### Allocate A Heap-Based Variable
```c
int main(void) {
    nc_ptr_i32 x = nc_new_ptr_int(nc_new_int(100));
}
```
Another example of method chaining (`nc_new_ptr_int(nc_new_int(bar))`). See method chaining docs [here](METHOD_CHAINING.md). This implicity allows 4 bytes on the heap, which you then have to manually free using `nc_free_int(foo)`.


### Adding Two Integers Together
```c
int main(void) {
    nc_i32 x = nc_new_int((int32_t)30);
    nc_i32 y = nc_new_int((int32_t)70);
    nc_i32 x_y_res = nc_checked_add_int(x, y);
    nc_println("%d", nc_get_val_int(x_y_res));
}
```
This first creates two integers, `x` with value 30 and `y` with value 70. We add them using `nc_checked_add_int`, which is a macro. Its definition can be found [here](../src/nc/nc_int/nc_int_method_macros.h). Then using `nc_println` to print out the result.

Expected result:
```text
100
```