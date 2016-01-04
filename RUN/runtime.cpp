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
_print__Int64(int64_t i)
{
    printf("%llu\n", i);
};

extern "C"
void
__attribute__ ((noinline))
_print__FP64(double d)
{
    printf("%f\n", d);
};
