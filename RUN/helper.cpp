//
//  helper.cpp
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>

extern "C" {
    
    void printStr()
    {
        printf("sup meme\n");
    };
    
    void print(int64_t i)
    {
        printf("%llu\n", i);
    };
    
    void printd(double d)
    {
        printf("%f\n", d);
    };
        
    void *memcpy(void * a, const void * b, size_t s)
    {
        return memcpy(a, b, s);
    };
}
