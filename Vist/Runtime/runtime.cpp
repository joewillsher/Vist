//
//  runtime.cpp
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

//  This file implements the Vist runtime. It exposes functions to Vist code
//  by calling to C APIs


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NOMANGLE extern "C"
#define NORETURN __attribute__((noreturn))
#define NOINLINE __attribute__((noinline))
#define ALWAYSINLINE __attribute__((always_inline))

//#define REFCOUNT_DEBUG

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

ALWAYSINLINE
void incrementRefCount(RefcountedObject *object) {
    __atomic_fetch_add(&object->refCount, 1, __ATOMIC_RELAXED);
}

ALWAYSINLINE
void decrementRefCount(RefcountedObject *object) {
    __atomic_fetch_sub(&object->refCount, 1, __ATOMIC_RELAXED);
}


// Ref counting

/// allocates a new heap object and returns the refcounted box
NOMANGLE NOINLINE
RefcountedObject *
vist_allocObject(uint32_t size) {
    // malloc the object storage
    void *object = malloc(size);
    // calloc the box storage -- need calloc so it is initialised
    auto refCountedObject = static_cast<RefcountedObject *>(malloc(sizeof(RefcountedObject)));
    
    // store the object and initial ref count in the box
    refCountedObject->object = object;
    refCountedObject->refCount = 0;
#ifdef REFCOUNT_DEBUG
    printf(">alloc\n");
#endif
    // return heap pointer to ref counted box
    return refCountedObject;
};

/// Deallocs a heap object
NOMANGLE NOINLINE
void
vist_deallocObject(RefcountedObject *object) {
#ifdef REFCOUNT_DEBUG
    printf(">dealloc\n");
#endif
    free(object->object);
    // this is probably leaking -- `object` is on the heap and we can't dispose of it
};

/// Releases this capture. If its now unowned we dealloc
NOMANGLE NOINLINE
void
vist_releaseObject(RefcountedObject *object) {
#ifdef REFCOUNT_DEBUG
    printf(">release %i\n", object->refCount-1);
#endif
    // if no more references, we dealloc it
    if (object->refCount == 1)
        vist_deallocObject(object);
    // otherwise we decrement
    else
        decrementRefCount(object);
};

/// Retain an object
NOMANGLE NOINLINE
void
vist_retainObject(RefcountedObject *object) {
    incrementRefCount(object);
#ifdef REFCOUNT_DEBUG
    printf(">retain %i\n", object->refCount);
#endif
};

/// Release an object without deallocating
NOMANGLE NOINLINE
void
vist_releaseUnretainedObject(RefcountedObject *object) {
    decrementRefCount(object);
#ifdef REFCOUNT_DEBUG
    printf(">release-unretained %i\n", object->refCount);
#endif
};

/// Get the ref count
NOMANGLE NOINLINE
uint32_t
vist_getObjectRefcount(RefcountedObject *object) {
    return object->refCount;
};

/// Check if the object is singly referenced
NOMANGLE NOINLINE
bool
vist_objectHasUniqueReference(RefcountedObject *object) {
    return object->refCount == 1;
};




// Printing

NOMANGLE NOINLINE
void
vist$Uprint_ti64(int64_t i) {
    printf("%lli\n", i);
};

NOMANGLE NOINLINE
void
vist$Uprint_ti32(int32_t i) {
    printf("%i\n", i);
};

NOMANGLE NOINLINE
void
vist$Uprint_tf64(double d)
{
    printf("%f\n", d);
};

NOMANGLE NOINLINE
void
vist$Uprint_tf32(float d) {
    printf("%f\n", d);
};

NOMANGLE NOINLINE
void
vist$Uprint_tb(bool b) {
    printf(b ? "true\n" : "false\n");
};

NOMANGLE NOINLINE
void
vist$Uprint_top(void *str) {
    printf("%s\n", str);
};

