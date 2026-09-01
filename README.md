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
├── CODE_OF_CONDUCT.md
├── LICENSE
├── README.md
├── src
│   ├── main.c
│   └── nc
│       ├── nc_int
│       │   ├── inc_helper_funcs.h
│       │   ├── nc_i16
│       │   │   └── nc_i16.h
│       │   ├── nc_i32
│       │   │   └── nc_i32.h
│       │   ├── nc_i64
│       │   │   └── nc_i64.h
│       │   ├── nc_i8
│       │   │   └── nc_i8.h
│       │   ├── nc_int_constructors.h
│       │   ├── nc_int_macros.h
│       │   ├── nc_types.h
│       │   ├── nc_u16
│       │   │   └── nc_u16.h
│       │   ├── nc_u32
│       │   │   └── nc_u32.h
│       │   ├── nc_u64
│       │   │   └── nc_u64.h
│       │   └── nc_u8
│       │       └── nc_u8.h
│       ├── nc_int_types.h
│       └── nc_log.h
├── tests
│   ├── nc_int_types
│   │   ├── conversion
│   │   │   └── test_nc_convert.c
│   │   ├── signed
│   │   │   ├── nc_i16
│   │   │   │   └── test_nc_i16.c
│   │   │   ├── nc_i32
│   │   │   │   └── test_nc_i32.c
│   │   │   └── nc_i8
│   │   │       └── test_nc_i8.c
│   │   └── unsigned
│   │       ├── nc_u16
│   │       │   └── test_nc_u16.c
│   │       ├── nc_u32
│   │       │   └── test_nc_u32.c
│   │       └── nc_u8
│   │           └── test_nc_u8.c
│   └── nc_log
│       └── test_nc_log.c
├── TEST.sh
└── vcpkg.json
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