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
    
    void print()
    {
        printf("sup meme\n");
    };
    
    void printNum(int64_t i)
    {
        printf("%llu\n", i);
    };
    
}
