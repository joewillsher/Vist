//
//  helper.cpp
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>

extern "C"
void
__attribute__ ((noinline))
_$print_i64(int64_t i)
{
    printf("%llu\n", i);
};

extern "C"
void
__attribute__ ((noinline))
_$print_i32(int i)
{
    printf("%i\n", i);
};

extern "C"
void
__attribute__ ((noinline))
_$print_FP64(double d)
{
    printf("%f\n", d);
};

extern "C"
void
__attribute__ ((noinline))
_$print_FP32(float d)
{
    printf("%f\n", d);
};

extern "C"
void
__attribute__ ((noinline))
_$print_b(bool b)
{
    if (b) { printf("true\n"); } else { printf("false\n"); };
};



