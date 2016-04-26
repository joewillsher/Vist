//
//  Shims.c
//  Vist
//
//  Created by Josef Willsher on 26/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define NORETURN __attribute__((noreturn))
#define NOINLINE __attribute__((noinline))
#define ALWAYSINLINE __attribute__((always_inline))

// Printing

NOINLINE
void
vist$Uprint_ti64(int64_t i) {
    printf("%lli\n", i);
};

NOINLINE
void
vist$Uprint_ti32(int32_t i) {
    printf("%i\n", i);
};

NOINLINE
void
vist$Uprint_tf64(double d)
{
    printf("%f\n", d);
};

NOINLINE
void
vist$Uprint_tf32(float d) {
    printf("%f\n", d);
};

NOINLINE
void
vist$Uprint_tb(bool b) {
    printf(b ? "true\n" : "false\n");
};


// MARK: vist c-shim functions

ALWAYSINLINE
void
vist$Ucshim$Uwrite_topi64(const void *str, int64_t size) {
    fwrite(str, size, 1, stdout);
};

NOINLINE
void
vist$Ucshim$Uputchar_ti8(char c) {
    putchar_unlocked(c);
};

