//
//  RefcountedObject.cpp
//  Vist
//
//  Created by Josef Willsher on 10/5/2016.
//  Copyright © 2015 vistlang. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct RefcountedObject {
    void *object;
    uint32_t refCount;
    TypeMetadata *metadata;
};


// Private
INLINE
void incrementRefCount(RefcountedObject *_Nonnull object) {
    __atomic_fetch_add(&object->refCount, 1, __ATOMIC_RELAXED);
}

INLINE
void decrementRefCount(RefcountedObject *_Nonnull object) {
    __atomic_fetch_sub(&object->refCount, 1, __ATOMIC_RELAXED);
}

// Ref counting

/// allocates a new heap object and returns the refcounted box
RUNTIME_COMPILER_INTERFACE
RefcountedObject *_Nonnull
vist_allocObject(TypeMetadata *metadata) {
    // malloc the object storage
    void *object = malloc(metadata->size);
    // calloc the box storage -- need calloc so it is initialised
    auto refCountedObject = reinterpret_cast<RefcountedObject *_Nonnull>(malloc(sizeof(RefcountedObject)));
    
    // store the object and initial ref count in the box
    refCountedObject->object = object;
    refCountedObject->refCount = 0;
#ifdef RUNTIME_DEBUG
    printf(">alloc  \t%p, rc=%i\n", refCountedObject->object, refCountedObject->refCount);
#endif
    // return heap pointer to ref counted box
    return refCountedObject;
};

/// Deallocs a heap object
RUNTIME_COMPILER_INTERFACE
void vist_deallocObject(RefcountedObject *_Nonnull object) {
#ifdef RUNTIME_DEBUG
    printf(">dealloc\t%p\n", object->object);
#endif
    if (auto destructor = object->metadata->destructor) {
        destructor(object->object);
    }
    free(object->object);
    // this is probably leaking -- `object` is on the heap and we can't dispose of it
};

/// Releases this capture. If its now unowned we dealloc
RUNTIME_COMPILER_INTERFACE
void vist_releaseObject(RefcountedObject *_Nonnull object) {
#ifdef RUNTIME_DEBUG
    printf(">release\t%p, rc=%i\n", object->object, object->refCount-1);
#endif
    // if no more references, we dealloc it
    if (object->refCount == 1)
        vist_deallocObject(object);
    // otherwise we decrement
    else
        decrementRefCount(object);
};

/// Retain an object
RUNTIME_COMPILER_INTERFACE
void vist_retainObject(RefcountedObject *_Nonnull object) {
    incrementRefCount(object);
#ifdef RUNTIME_DEBUG
    printf(">retain \t%p, rc=%i\n", object->object, object->refCount);
#endif
};

/// Release an object without deallocating
RUNTIME_COMPILER_INTERFACE
void vist_releaseUnownedObject(RefcountedObject *_Nonnull object) {
    decrementRefCount(object);
#ifdef RUNTIME_DEBUG
    printf(">release-unowned \t%p, rc=%i\n", object->object, object->refCount);
#endif
};

/// Deallocate a -1 object if it is unowned
RUNTIME_COMPILER_INTERFACE
void vist_deallocUnownedObject(RefcountedObject *_Nonnull object) {
#ifdef RUNTIME_DEBUG
    printf(">dealloc-unowned\t%p, rc=%i\n", object->object, object->refCount);
#endif
    if (object->refCount == 0)
        vist_deallocObject(object);
};

/// Get the ref count
RUNTIME_COMPILER_INTERFACE
uint32_t vist_getObjectRefcount(RefcountedObject *_Nonnull object) {
    return object->refCount;
};

/// Check if the object is singly referenced
RUNTIME_COMPILER_INTERFACE
bool vist_objectHasUniqueReference(RefcountedObject *_Nonnull object) {
    return object->refCount == 1;
};


