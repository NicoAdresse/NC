/* src/main.c */

/*
    About: Placeholder 'main.c'.
    Initial Commit: INIT
    Commit Year: 2026
    Licensed Under: MIT
    Committer: Nico Erdmann
    Author: Nico Erdmann
*/

#include "nc/nc_int_types.h"

int main() {
    nc_i8 a = nc_new_i8(100);
    nc_i16 b = nc_new_i16(200);
    nc_i32 c = nc_new_i32(300);

    printf("%ld\n", nc_get_size(a));
    printf("%ld\n", nc_get_size(b));
    printf("%ld\n", nc_get_size(c));

    return 0; 
}