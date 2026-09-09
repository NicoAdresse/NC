# NC <->

Created on 29.08.2026 (Saturday)

Author: Nico Erdmann

## About <->

See [`docs/ABOUT_NC.md`](./docs/ABOUT_NC.md).

## Testing <->

See [`docs/TESTING_NC.md`](./docs/TESTING_NC.md).

## How To Install <->

1. **Clone The Repository**

```bash
git clone https://github.com/NicoAdresse/NC.git
```

2. **Enjoy + Advice**

This project is still in version **0.0.1.** Do not add it in `usr/include`. PLay around with it in the `tests` directory.

This is a header-only library with **zero dependencies**. You do not need CMake, make, or any external package manager. However, we are planning to add it to `vcpkg` in the future.

## File Structure <->

```text
NC
├── CLEAN.sh
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── docs
│   ├── ABOUT_NC.md
│   ├── HOW_GCC_COMPILES_NC.md
│   └── TESTING_NC.md
├── LICENSE
├── README.md
├── src
│   └── nc
│       ├── nc_int
│       │   ├── inc_helper_funcs.h
│       │   ├── nc_i16
│       │   │   └── nc_i16.h
│       │   ├── nc_i32
│       │   │   └── nc_i32.h
│       │   ├── nc_i64
│       │   │   └── nc_i64.h
│       │   ├── nc_i8
│       │   │   └── nc_i8.h
│       │   ├── nc_int_constructors.h
│       │   ├── nc_int_destructors.h
│       │   ├── nc_int_macros.h
│       │   ├── nc_int_method_macros.h
│       │   ├── nc_ptr_i16
│       │   │   └── nc_ptr_i16.h
│       │   ├── nc_ptr_i32
│       │   │   └── nc_ptr_i32.h
│       │   ├── nc_ptr_i64
│       │   │   └── nc_ptr_i64.h
│       │   ├── nc_ptr_i8
│       │   │   └── nc_ptr_i8.h
│       │   ├── nc_ptr_u16
│       │   │   └── nc_ptr_u16.h
│       │   ├── nc_ptr_u32
│       │   │   └── nc_ptr_u32.h
│       │   ├── nc_ptr_u64
│       │   │   └── nc_ptr_u64.h
│       │   ├── nc_ptr_u8
│       │   │   └── nc_ptr_u8.h
│       │   ├── nc_types.h
│       │   ├── nc_u16
│       │   │   └── nc_u16.h
│       │   ├── nc_u32
│       │   │   └── nc_u32.h
│       │   ├── nc_u64
│       │   │   └── nc_u64.h
│       │   └── nc_u8
│       │       └── nc_u8.h
│       ├── nc_int_types.h
│       ├── nc_log
│       │   ├── nc_debug_stmts.h
│       │   └── nc_print_stmts.h
│       └── nc_log.h
├── tests
│   ├── nc_int_types
│   │   ├── conversion
│   │   │   └── test_nc_convert.c
│   │   ├── macros
│   │   │   └── test_nc_macros.c
│   │   ├── signed
│   │   │   ├── nc_i16
│   │   │   │   └── test_nc_i16.c
│   │   │   ├── nc_i32
│   │   │   │   └── test_nc_i32.c
│   │   │   ├── nc_i64
│   │   │   │   └── test_nc_i64.c
│   │   │   ├── nc_i8
│   │   │   │   └── test_nc_i8.c
│   │   │   ├── nc_ptr_i16
│   │   │   │   └── test_nc_ptr_i16.c
│   │   │   ├── nc_ptr_i32
│   │   │   │   └── test_nc_ptr_i32.c
│   │   │   ├── nc_ptr_i64
│   │   │   │   └── test_nc_ptr_i64.c
│   │   │   └── nc_ptr_i8
│   │   │       └── test_nc_ptr_i8.c
│   │   └── unsigned
│   │       ├── nc_ptr_u16
│   │       │   └── test_nc_ptr_u16.c
│   │       ├── nc_ptr_u32
│   │       │   └── test_nc_ptr_u32.c
│   │       ├── nc_ptr_u64
│   │       │   └── test_nc_ptr_u64.c
│   │       ├── nc_ptr_u8
│   │       │   └── test_nc_ptr_u8.c
│   │       ├── nc_u16
│   │       │   └── test_nc_u16.c
│   │       ├── nc_u32
│   │       │   └── test_nc_u32.c
│   │       ├── nc_u64
│   │       │   └── test_nc_u64.c
│   │       └── nc_u8
│   │           └── test_nc_u8.c
│   └── nc_log
│       ├── test_nc_debug.c
│       └── test_nc_log.c
├── TEST.sh
└── vcpkg.json
```

## License <->

License -> `MIT` | Check the [`LICENSE`](LICENSE) file.