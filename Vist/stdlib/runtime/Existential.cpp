//
//  Existential.cpp
//  Vist
//
//  Created by Josef Willsher on 10/5/2016.
//  Copyright © 2015 vistlang. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cstring>


RUNTIME_COMPILER_INTERFACE
void vist_constructExistential(WitnessTable *_Nonnull *_Nonnull conformances, int numConformances,
                               void *_Nonnull instance, TypeMetadata *_Nonnull metadata,
                               bool isNonLocal, ExistentialObject *_Nullable outExistential) {
    uintptr_t ptr;
    if (isNonLocal) {
        auto mem = malloc(metadata->storageSize());
        // copy stack into new buffer
        memcpy(mem, instance, metadata->storageSize());
        ptr = (uintptr_t)mem;
#ifdef RUNTIME_DEBUG
        // DEBUGGING: set stack source to 0, if not a shared heap ptr
        if (!metadata->isRefCounted)
            memset(instance, 0, metadata->storageSize());
        printf("→alloc %s:\t%p\n", metadata->name, mem);
#endif
    } else {
        ptr = (uintptr_t)instance;
#ifdef RUNTIME_DEBUG
        printf("→alloc_stack %s:\t%p\n", metadata->name, instance);
#endif
    }
    
    *outExistential = ExistentialObject(ptr | isNonLocal, metadata, numConformances,
                                        conformances); // <hack, should malloc memory to store the witnesses
}

RUNTIME_COMPILER_INTERFACE
void vist_deallocExistentialBuffer(ExistentialObject *_Nonnull existential) {
#ifdef RUNTIME_DEBUG
    printf("→dealloc %s:\t%p\n", existential->metadata->name, (void*)existential->projectBuffer());
#endif
    auto buff = (void *)existential->projectBuffer();
    if (!buff)
        return;
    // If we have to specially handle releasing ownership of the memory:
    if (existential->metadata->isRefCounted) {
        // release a class instance
#ifdef RUNTIME_DEBUG
        printf("   ↳existential_release↘︎\n");
#endif
        vist_releaseObject((RefcountedObject*)buff);
        return;
    } else if (auto destructor = existential->metadata->destructor) {
        // call any custom destructors -- the instance needs to release
        // ownership of any children
#ifdef RUNTIME_DEBUG
        printf("   ↳destructor_fn=%p\n", destructor);
#endif
        destructor(buff);
    }
    
    // Deallocate the existential buffer
    if (existential->isNonLocal())
        free(buff);
#ifdef RUNTIME_DEBUG
    // DEBUGGING: set stack to 0, if not a shared heap ptr
    else if (!existential->metadata->isRefCounted)
        memset(buff, 0, existential->metadata->storageSize());
#endif
}

RUNTIME_COMPILER_INTERFACE
void vist_exportExistentialBuffer(ExistentialObject *_Nonnull existential) {
    // if it is already on the heap, we are done
    auto in = existential->projectBuffer();
    if (existential->isNonLocal() || existential->metadata->isRefCounted) {
#ifdef RUNTIME_DEBUG
        printf("     ↳dupe_export %s:\t%p\n", existential->metadata->name, (void*)in);
#endif
        return;
    }
    auto mem = malloc(existential->metadata->storageSize());
    // copy stack into new buffer
    memcpy(mem, (void*)existential->projectBuffer(), existential->metadata->storageSize());
    existential->instanceTaggedPtr = (uintptr_t)mem | true;
#ifdef RUNTIME_DEBUG
    printf("   ↳export %s:\t%p to: %p\n", existential->metadata->name, (void*)in, (void*)existential->projectBuffer());
#endif
}

RUNTIME_COMPILER_INTERFACE
void vist_copyExistentialBuffer(ExistentialObject *_Nonnull existential,
                                ExistentialObject *_Nullable outExistential) {
    
    auto in = (void*)existential->projectBuffer();
    void *mem;
    // we must copy different objects differently
    //  - trivial types can be shallow copied
    //  - call its copy constructor if defined -- this is needed to move over
    //    children of the type
    //  - ref types don't need to copy the shared instance, simply retain it
    if (existential->metadata->isRefCounted) {
#ifdef RUNTIME_DEBUG
        printf("   ↳existential_retain↘︎\n");
#endif
        vist_retainObject((RefcountedObject*)existential->projectBuffer());
        mem = in;
    } else if (auto copyConstructor = existential->metadata->copyConstructor) {
        mem = malloc(existential->metadata->storageSize());
#ifdef RUNTIME_DEBUG
        printf("   ↳deep_copy %s:\t%p to: %p\n", existential->metadata->name, in, mem);
        printf("       ↳deep_copy_fn=%p\n", copyConstructor);
#endif
        copyConstructor((void*)existential->projectBuffer(), mem);
    } else {
        // if there is no copy constructor, we just have to do a shallow copy
        mem = malloc(existential->metadata->storageSize());
#ifdef RUNTIME_DEBUG
        printf("   ↳copy %s:\t%p to: %p\n", existential->metadata->name, in, mem);
#endif
        memcpy(mem, (void*)existential->projectBuffer(), existential->metadata->storageSize());
    }
    // construct the new existential
    *outExistential = ExistentialObject((uintptr_t)mem | true,
                                        existential->metadata,
                                        existential->numConformances,
                                        existential->conformances);
}


RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getWitnessMethod(ExistentialObject *_Nonnull existential,
                      int32_t conformanceIndex,
                      int32_t methodIndex) {
    return existential
        ->conformances[conformanceIndex]
        ->witnesses[methodIndex];
}

RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getPropertyProjection(ExistentialObject *_Nonnull existential,
                           int32_t conformanceIndex, int32_t propertyIndex) {
    auto offset = existential
        ->conformances[conformanceIndex]
        ->propWitnessOffsets[propertyIndex];
    return (void*)(existential->projectBuffer() + (long)offset);
}

RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getExistentialBufferProjection(ExistentialObject *_Nonnull existential) {
    return (void*)existential->projectBuffer();
}


