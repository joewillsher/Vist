//
//  helper.cpp
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <algorithm>

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

extern "C"
void
__attribute__ ((noinline))
_$fatalError()
{
    abort();
};

extern "C"
void
__attribute__ ((noinline))
_$demangle_Pi8Pi8i64(char* output, char* input, int64_t length) {
    if(!input || !output) return;
    std::string accum;
    int underscore_seen = 0;
    for(int i = 0; i < length && input[i] && underscore_seen != 2; i++) {
        switch(input[i]) {
            case '_':
                if(underscore_seen == 1) {
                    underscore_seen = 2;
                    break;
                } else {
                    underscore_seen = 1;
                    break;
                }
            case '$':
                accum += '_';
                break;
            default:
                accum += input[i];
                break;
        }
    }
    strlcpy(output, accum.c_str(), length);
};





