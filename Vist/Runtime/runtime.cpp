//
//  helper.cpp
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

//  This file implements the Vist runtime. It exposes functions to Vist code
//  by calling to C APIs. These functions are made accessible in runtime.visth.
//
//  All functions here are declared using their mangled names


#include <csignal>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <algorithm>

#define NORETURN __attribute__((noreturn))
#define NOINLINE __attribute__((noinline))
#define ALWAYSINLINE __attribute__((always_inline))


// SwiftShims defines putchar function https://github.com/apple/swift/blob/master/stdlib/public/stubs/LibcShims.cpp#L31
// When I have strings working, use this implementation to write all of a string to stdout https://github.com/apple/swift/blob/master/stdlib/public/core/OutputStream.swift#L258
// Make a Printable protocol which returns a string of self
// make a stdlib private `writeString` function which writes a String hcar by char to stdout
// print function takes a Printable, and calls writeString on it (plus "\n")

extern "C" NOINLINE
void
_$print_i64(int64_t i)
{
    printf("%lli\n", i);
};

extern "C" NOINLINE
void
_$print_i32(int i)
{
    printf("%i\n", i);
};

extern "C" NOINLINE
void
_$print_f64(double d)
{
    printf("%f\n", d);
};

extern "C" NOINLINE
void
_$print_f32(float d)
{
    printf("%f\n", d);
};

extern "C" NOINLINE
void
_$print_b(bool b)
{
    if (b) { printf("true\n"); } else { printf("false\n"); };
};

//extern "C" NOINLINE
//void
//_$fatalError_()
//{
//    abort();
//};

//extern "C" NOINLINE
//void
//_$demangle_Pi8Pi8i64(char* output, char* input, int64_t length) {
//    if(!input || !output) return;
//    std::string accum;
//    int underscore_seen = 0;
//    for(int i = 0; i < length && input[i] && underscore_seen != 2; i++) {
//        switch(input[i]) {
//            case '_':
//                if(underscore_seen == 1) {
//                    underscore_seen = 2;
//                    break;
//                } else {
//                    underscore_seen = 1;
//                    break;
//                }
//            case '$':
//                accum += '_';
//                break;
//            default:
//                accum += input[i];
//                break;
//        }
//    }
//    strlcpy(output, accum.c_str(), length);
//};





