//
//  Shims.c
//  Vist
//
//  Created by Josef Willsher on 26/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

// these shims expose to the stdlib compiler c untility functions

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

#define NORETURN __attribute__((noreturn))
#define NOINLINE __attribute__((noinline))
#define ALWAYSINLINE __attribute__((always_inline))

// Printing

void
_Vvist$Ucshim$Uwrite_topi64(const void *str, int64_t size) {
    fwrite(str, size, 1, stdout);
};

void
_Vvist$Ucshim$Uputchar_ti8(char c) {
    putchar_unlocked(c);
};

NOINLINE
int64_t
_Vvist$Ucshim$Ustrlen_top(void *c) {
    return strlen(c);
};

struct timeval {
    time_t      tv_sec;     /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};

NOINLINE
double
_Vvist$Ucshim$Utime_t() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (double)time.tv_sec + (double)time.tv_usec*1e-6;
};

// Legacy shims:

NOINLINE
void
_Vvist$Ucshim$Uprint_ti64(int64_t i) {
    printf("%lli\n", i);
};

NOINLINE
void
_Vvist$Ucshim$Uprint_ti32(int32_t i) {
    printf("%i\n", i);
};

NOINLINE
void
_Vvist$Ucshim$Uprint_tf64(double d)
{
    printf("%lf\n", d);
};

NOINLINE
void
_Vvist$Ucshim$Uprint_tf32(float d) {
    printf("%f\n", d);
};

NOINLINE
void
_Vvist$Ucshim$Uprint_tb(bool b) {
    printf(b ? "true\n" : "false\n");
};

NOINLINE
void
_Vvist$Ucshim$Ulog_t() {
    static int i = 0;
    printf(">LOG=%i\n", i);
    i += 1;
};

