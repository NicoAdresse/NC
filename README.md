# NC <->

Created on 29.08.2026 (Saturday)

Author: Nico Erdmann

## About <->

**NC** is designed to bring modern programming concepts to C, focusing on safety, predictability, and developer ergonomics.

Features such as:
- Primitive Datatypes with safety barriers

## Testing <->

To test certain files like `test_nc_i8.c`, run this:

```bash
chmod +x TEST.sh
./TEST.sh test_nc_i8.c # Adds a compiled binary called 'test_nc_i8' in 'build'.
```

## Cleaning <->

To remove compiled binaries or just to clean the ***'build'*** directory, run this:

```bash
chmod +x CLEAN.sh
./CLEAN.sh # Automatically cleans the build for you.
```

## File Structure <->

```text
NC
├── CLEAN.sh
├── LICENSE
├── README.md
├── src
│   ├── main.c
│   └── nc
│       └── nc_int_types.h
├── tests
│   └── nc_int_types
│       ├── signed
│       │   ├── nc_i16
│       │   │   ├── test_nc_i16.c
│       │   │   ├── test_nc_i16_checked_add_overflow.c
│       │   │   ├── test_nc_i16_checked_add_underflow.c
│       │   │   ├── test_nc_i16_constructor_overflow.c
│       │   │   └── test_nc_i16_constructor_underflow.c
│       │   ├── nc_i32
│       │   │   ├── test_nc_i32.c
│       │   │   ├── test_nc_i32_checked_add_overflow.c
│       │   │   ├── test_nc_i32_checked_add_underflow.c
│       │   │   ├── test_nc_i32_constructor_overflow.c
│       │   │   └── test_nc_i32_constructor_underflow.c
│       │   └── nc_i8
│       │       ├── test_nc_i8.c
│       │       ├── test_nc_i8_checked_add_overflow.c
│       │       ├── test_nc_i8_checked_add_underflow.c
│       │       ├── test_nc_i8_constructor_overflow.c
│       │       └── test_nc_i8_constructor_underflow.c
│       └── unsigned
│           ├── nc_u16
│           │   ├── test_nc_u16.c
│           │   ├── test_nc_u16_checked_add_overflow.c
│           │   ├── test_nc_u16_constructor_overflow.c
│           │   └── test_nc_u16_constructor_underflow.c
│           ├── nc_u32
│           │   ├── test_nc_u32.c
│           │   ├── test_nc_u32_checked_add_overflow.c
│           │   ├── test_nc_u32_constructor_overflow.c
│           │   └── test_nc_u32_constructor_underflow.c
│           └── nc_u8
│               ├── test_nc_u8.c
│               ├── test_nc_u8_checked_add_overflow.c
│               ├── test_nc_u8_constructor_overflow.c
│               └── test_nc_u8_constructor_underflow.c
└── TEST.sh
```

## License <->

License -> `MIT` | Check the `LICENSE` file.

## About README.md

About: Quick Lookup on information about this project.

```text
Initial Commit: INIT
Commit Year: 2026
Licensed Under: MIT
Committer: Nico Erdmann
Author: Nico Erdmann
```