/* tests/nc_int_types/must_operators/test_must_operators.c */

/*
    SPDX-License-Identifier: MIT
    Copyright (c) 2026 Nico Erdmann
    Tests for for must operators like nc_checked_add_must_i32, nc_checked_mul_must_u64... etc.
*/

#include "../../../src/nc.h"

int main(void) {
    printf("=== Testing NC Must Operators ===\n\n");

    nc_i32 a = nc_new_int((int32_t)10);
    nc_i32 b = nc_new_int((int32_t)5);
    nc_u8  x = nc_new_int((uint8_t)200);
    nc_u8  y = nc_new_int((uint8_t)2);

    nc_i32 mul_res = nc_checked_mul_must_int(a, b);
    nc_println_info("[MUL] 10 * 5 = %d", nc_get_val_int(mul_res));

    nc_i32 div_res = nc_checked_div_must_int(a, b, 0);
    nc_println_info("[DIV] 10 / 5 = %d", nc_get_val_int(div_res));

    nc_i32 mod_res = nc_checked_mod_must_int(a, b, 0);
    nc_println_info("[MOD] 10 %% 5 = %d", nc_get_val_int(mod_res));

    nc_println_info("\n=== Testing Unsigned 8-bit Overflow Protection ===");
    nc_println_info("Multiplying 200 * 2 (Should trigger inc_check_for_errs_must_u8):");
    
    nc_u8 overflow_res = nc_checked_mul_must_int(x, y);
    (void)overflow_res; /* This just exists to silence a GCC warning, since this variable is unused. */
    
    nc_println_info("If you see this, then must has failed to do its duty. If you don't, then the test is successful.");

    return 0;
}
