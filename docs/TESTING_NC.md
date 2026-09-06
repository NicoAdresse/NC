# Testing NC <->
Testing the code is straightforward using the provided automation script.

## Running Tests <->
To execute a test, run the `TEST.sh` script and provide the path to your test file:

```bash
./TEST.sh tests/nc_int_types/signed/nc_i8/test_nc_i8.c
```

## How It Works <->
* **Validation:** The script verifies if the specified path exists. If not, it returns an error and terminates safely.
* **Compilation:** If the path is valid, it uses GCC to compile the file. The resulting binary is stored in the local `build/` directory (which is excluded from version control via `.gitignore`).
* **Execution:** The script automatically runs the compiled binary. 

This approach ensures fast iteration times while keeping NC lightweight and compatible with virtually any architecture that supports `libc`.

## Project Status <->
The project is currently small and lightweight, meaning no heavy build tools like CMake are required at this stage.
