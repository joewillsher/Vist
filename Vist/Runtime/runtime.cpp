//
//  helper.cpp
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

//  This file implements the Vist runtime. It exposes functions to Vist code
//  by calling to C APIs
//
//  All functions here are declared using their mangled names


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NOMANGLE extern "C"
#define NORETURN __attribute__((noreturn))
#define NOINLINE __attribute__((noinline))
#define ALWAYSINLINE __attribute__((always_inline))

// SwiftShims defines putchar function https://github.com/apple/swift/blob/master/stdlib/public/stubs/LibcShims.cpp#L31
// When I have strings working, use this implementation to write all of a string to stdout https://github.com/apple/swift/blob/master/stdlib/public/core/OutputStream.swift#L258
// Make a Printable protocol which returns a string of self
// make a stdlib private `writeString` function which writes a String hcar by char to stdout
// print function takes a Printable, and calls writeString on it (plus "\n")

NOMANGLE NOINLINE void
vist$Uprint_i64(int64_t i) {
    printf("%lli\n", i);
};

NOMANGLE NOINLINE void
vist$Uprint_i32(int i) {
    printf("%i\n", i);
};

NOMANGLE NOINLINE void
vist$Uprint_f64(double d)
{
    printf("%f\n", d);
};

NOMANGLE NOINLINE void
vist$Uprint_f32(float d) {
    printf("%f\n", d);
};

NOMANGLE NOINLINE void
vist$Uprint_b(bool b) {
    printf(b ? "true\n" : "false\n");
};

