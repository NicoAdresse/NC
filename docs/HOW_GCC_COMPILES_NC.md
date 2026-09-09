# How GCC Compiles NC <->
Because NC is a header-centric C library relying heavily on static inline functions, macro metaprogramming, and zero-cost abstractions, GCC compilation behaves differently than a traditional compiled library (.a or .so).

### Header and Static Inlining Architecture

- **Direct Inlining**: Functions are defined with static inline so they are expanded directly into your compilation units. This allows GCC to optimize away bounds checks and arithmetic wrappers entirely when possible.
- **Internal Linkage**: The static keyword ensures each translation unit receives its own private instance of helper functions, preventing multiple-definition linker errors without requiring a separate build step for the library itself.

### GNU Variadic Extensions

- NC's logging and debug macros use the GNU extension __VA_OPT__(,) (Or ##__VA_ARGS__, if your using an older version of C) to cleanly swallow trailing commas when formatting strings with zero optional arguments.
- ***Requirement: Because of this, files must be compiled with standard C99 or later (e.g., -std=c99 or -std=gnu99). Compiling under strict ancient ISO C flags without GNU extensions will cause preprocessor errors.***

### Rust-Style Debug Defaults via NDEBUG

Unlike traditional C headers that require you to opt-in to debugging, NC keeps safety checks and debug logging active by default out of the box.

To strip out assertions and debug logs for production binaries—matching Rust's release profile behavior—compile using standard release flags:

```bash
gcc -O3 -DNDEBUG main.c -o my_program
```

A common point of confusion is that `-DNDEBUG` or `DNC_RELEASE` disables NC's safety. That is false, it disables debugging and assertions. It does not disable any safety checking (like overflow checking).

Check [ASSERTIONS.md](ASSERTIONS.md) for more documentation on debugging.