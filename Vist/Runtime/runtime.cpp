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

// Currently all NOINLINE because optimiser cant copy over the string data across modules

/// Name Mangling:
///     - If you want the function to be called by vist users, write the full, mangled name
///       like `vist$Uprint_i64` can be called as `vist_print`.
///     - Note that any `-` has to be replaced with a `$`. The importer will switch it back
///     - All functions in this namespace should be prefixed with vist_
///     - If the function is just for the compiler to call, dont mangle it, eg. `vist_getAccessor`

struct RefcountedObject {
    void *object;
    uint32_t refCount;
};

// Private

void incrementRefCount(RefcountedObject *object) {
    __atomic_fetch_add(&object->refCount, 1, __ATOMIC_RELAXED);
}

void decrementRefCount(RefcountedObject *object) {
    __atomic_fetch_sub(&object->refCount, 1, __ATOMIC_RELAXED);
}


NOMANGLE NOINLINE
void *
vist_allocObject(uint32_t size) {
    return malloc(size);
};


NOMANGLE NOINLINE
void
vist_deallocObject(RefcountedObject *object) {
    free(object);
};

NOMANGLE NOINLINE
void
vist_releaseObject(RefcountedObject *object,
                   uint32_t size) {
    
    // if no more references, we dealloc it
    if (object->refCount == 1)
        vist_deallocObject(object);
    // otherwise we decrement
    else
        decrementRefCount(object);
};

NOMANGLE NOINLINE
void
vist_retainObject(RefcountedObject *object) {
    incrementRefCount(object);
};






NOMANGLE NOINLINE void
vist$Uprint_ti64(int64_t i) {
    printf("%lli\n", i);
};

NOMANGLE NOINLINE void
vist$Uprint_ti32(int32_t i) {
    printf("%i\n", i);
};

NOMANGLE NOINLINE void
vist$Uprint_tf64(double d)
{
    printf("%f\n", d);
};

NOMANGLE NOINLINE void
vist$Uprint_tf32(float d) {
    printf("%f\n", d);
};

NOMANGLE NOINLINE void
vist$Uprint_tb(bool b) {
    printf(b ? "true\n" : "false\n");
};

NOMANGLE NOINLINE void
vist$Uprint_top(void *str) {
    printf("%s\n", str);
};

