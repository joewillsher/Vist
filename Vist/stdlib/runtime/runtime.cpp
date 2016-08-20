//
//  runtime.cpp
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

//  The runtime is exposed to the compiler, and allows it to inspect details
//  of the program state, like type metadata and reference counts, as well as
//  being responsible for allocating and deallocating objects


// Existential logic

#include <setjmp.h>
#include <stdint.h>
#include <stdlib.h>

// setjmp functions

static jmp_buf yieldTarget;

/// Returns to the saved stack position
RUNTIME_COMPILER_INTERFACE
void vist_yieldUnwind() {
    return longjmp(yieldTarget, 1);
}

/// Sets this stack state as the target state
/// \returns whether we got to this spot by yielding
RUNTIME_COMPILER_INTERFACE
bool vist_setYieldTarget() {
    return setjmp(yieldTarget);
}

// expose vist types

struct VistInt_t {
    int64_t value;
};
struct VistBool_t {
    bool value;
};
struct VistInt32_t {
    int32_t value;
};
struct VistString_t {
    void *base;
    int64_t size;
    int64_t _capacityAndEncoding;
};
//
//extern "C"
//getSpecialisedType ...









