# Method Chaining <->

C has no `.` method-call syntax, so nested calls stack up instead of chaining left-to-right like they would in Rust or C++. You'll see this throughout tests:
```c
nc_assert_eq(nc_get_val_int(nc_checked_mod_int(val_a, val_b, 0)), 0); // test_nc_ptr_i64.c
```
Read from the inside out: nc_checked_mod_int runs first, its result is passed straight into nc_get_val_int, and that result is finally compared with nc_assert_eq. It's compact, but the evaluation order isn't obvious at a glance.

The same logic, unrolled into intermediate variables, is easier to step through and debug:

```c
nc_ptr_i64 res = nc_checked_mod_int(val_a, val_b, 0); // compute a % b, checked
nc_i64* val    = nc_get_val_int(res);                 // unwrap the result
nc_assert_eq(val, 0);                                 // assert it's 0
```

**Tip**: if a nested expression grows past 2–3 calls deep, prefer unrolling it. A `res.value` obscured three parentheses deep is a common source of bugs when debugging test failures, since debuggers can't easily step to the middle of an expression.