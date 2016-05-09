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
#include <setjmp.h>

#define NOMANGLE extern "C"
#define NORETURN __attribute__((noreturn))
#define NOINLINE __attribute__((noinline))
#define ALWAYSINLINE __attribute__((always_inline))

// Currently all exposed functions NOINLINE because optimiser cant copy over the string data across modules

/// Name Mangling:
///     - If you want the function to be called by vist users, write the full, mangled name
///       like `vist$Uprint_i64` can be called as `vist_print`.
///     - Note that any `-` has to be replaced with a `$`. The importer will switch it back
///     - All functions in this namespace should be prefixed with vist_
///     - If the function is just for the compiler to call, dont mangle it, eg. `vist_getAccessor`

#define REFCOUNT_DEBUG

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
NOMANGLE ALWAYSINLINE
RefcountedObject *
vist_allocObject(uint32_t size) {
    // malloc the object storage
    void *object = malloc(size);
    // calloc the box storage -- need calloc so it is initialised
    auto refCountedObject = (RefcountedObject *)(malloc(sizeof(RefcountedObject)));
    
    // store the object and initial ref count in the box
    refCountedObject->object = object;
    refCountedObject->refCount = 0;
#ifdef REFCOUNT_DEBUG
    printf(">alloc %p, %i\n", refCountedObject->object, refCountedObject->refCount);
#endif
    // return heap pointer to ref counted box
    return refCountedObject;
};

/// Deallocs a heap object
NOMANGLE ALWAYSINLINE
void
vist_deallocObject(RefcountedObject *object) {
#ifdef REFCOUNT_DEBUG
    printf(">dealloc %p\n", object->object);
#endif
    free(object->object);
    // this is probably leaking -- `object` is on the heap and we can't dispose of it
};

/// Releases this capture. If its now unowned we dealloc
NOMANGLE ALWAYSINLINE
void
vist_releaseObject(RefcountedObject *object) {
#ifdef REFCOUNT_DEBUG
    printf(">release %p, %i\n", object->object, object->refCount-1);
#endif
    // if no more references, we dealloc it
    if (object->refCount == 1)
        vist_deallocObject(object);
    // otherwise we decrement
    else
        decrementRefCount(object);
};

/// Retain an object
NOMANGLE ALWAYSINLINE
void
vist_retainObject(RefcountedObject *object) {
    incrementRefCount(object);
#ifdef REFCOUNT_DEBUG
    printf(">retain %p, %i\n", object->object, object->refCount);
#endif
};

/// Release an object without deallocating
NOMANGLE ALWAYSINLINE
void
vist_releaseUnownedObject(RefcountedObject *object) {
    decrementRefCount(object);
#ifdef REFCOUNT_DEBUG
    printf(">release-unowned %p, %i\n", object->object, object->refCount);
#endif
};

/// Deallocate a -1 object if it is unowned
NOMANGLE ALWAYSINLINE
void
vist_deallocUnownedObject(RefcountedObject *object) {
#ifdef REFCOUNT_DEBUG
    printf(">dealloc-unowned %p, %i\n", object->object, object->refCount);
#endif
    if (object->refCount == 0)
        vist_deallocObject(object);
};

/// Get the ref count
NOMANGLE ALWAYSINLINE
uint32_t
vist_getObjectRefcount(RefcountedObject *object) {
    return object->refCount;
};

/// Check if the object is singly referenced
NOMANGLE ALWAYSINLINE
bool
vist_objectHasUniqueReference(RefcountedObject *object) {
    return object->refCount == 1;
};



// Generator logic

static jmp_buf yieldTarget;

/// Returns to the saved stack position
NOMANGLE ALWAYSINLINE
void
vist_yieldUnwind() {
    return longjmp(yieldTarget, 1);
}

/// Sets this stack state as the target state
/// \returns whether we got to this spot by yielding
NOMANGLE ALWAYSINLINE
bool
vist_setYieldTarget() {
    return setjmp(yieldTarget);
}


int main() {



    return 0;
}




