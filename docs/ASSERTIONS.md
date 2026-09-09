# Assertions <->

The NC programming language uses an assertion model deeply inspired by Rust's standard library macros. In NC, assertions are first-class language mechanics designed to separate unrecoverable production invariants from localized development and debugging checks.

### Architectural Design Goals

1. **Zero Runtime Cost in Release**: When optimizing with flags like `NDEBUG` or `NC_RELEASE`, macro calls resolve cleanly to `((void)0)`, completely vanishing from compiled assembly.
2. **Side-Effect Mitigation**: Variables passed to comparison checks are isolated locally to avoid double-evaluation bugs (e.g., passing iterative functions like `pop_stack()`).
3. **Type-Safe Automated Formatting**: Leverages C11 macro polymorphism to infer data types automatically, eliminating the need to supply manually typed format descriptors.

### Compile-Time Model

The framework uses conditional compilation paths. If either `NDEBUG` or `NC_RELEASE` is globally specified, the engine drops out completely.

```text
 [Source Compilation Run]
                  │
         ┌────────┴────────┐
         ▼                 ▼
   [Debug Profile]   [Release Profile]
  (!NDEBUG & !NC_RELEASE) (NDEBUG || NC_RELEASE)
         │                 │
         ▼                 ▼
 Full Value Validation   Evaluations Strung Out
 & String Formats Stack  via Macro ((void)0)
```