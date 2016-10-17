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
void vist_constructExistential(ConceptConformance *_Nonnull conformance,
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
    
    *outExistential = ExistentialObject(ptr | isNonLocal, metadata, 1,
                                        (ConceptConformance **)conformance);
}

RUNTIME_COMPILER_INTERFACE
void vist_deallocExistentialBuffer(ExistentialObject *_Nonnull existential) {
#ifdef RUNTIME_DEBUG
    printf("→dealloc %s:\t%p\n", existential->metadata->name, (void*)existential->projectBuffer());
#endif
    auto buff = (void *)existential->projectBuffer()
    if (!buff)
        return;
    // If we have to specially handle releasing ownership of the memory:
    if (existential->metadata->isRefCounted) {
        // release a class instance
#ifdef RUNTIME_DEBUG
        printf("   ↳existential_release↘︎\n");
#endif
        vist_releaseObject((RefcountedObject*)buff);
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
    auto in = existential->projectBuffer();
    // if it is already on the heap, we are done
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
    auto mem = malloc(existential->metadata->storageSize());
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
    } else if (auto copyConstructor = existential->metadata->copyConstructor) {
#ifdef RUNTIME_DEBUG
        printf("   ↳deep_copy %s:\t%p to: %p\n", existential->metadata->name, in, mem);
        printf("       ↳deep_copy_fn=%p\n", copyConstructor);
#endif
        copyConstructor((void*)existential->projectBuffer(), mem);
    } else {
        // if there is no copy constructor, we just have to do a shallow copy
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

ConceptConformance *_Nonnull
ExistentialObject::getConformance(int32_t index) {
    return (ConceptConformance *)(conformances) + index;
}

void *_Nonnull
WitnessTable::getWitness(int32_t index) {
    auto witness = witnesses[index];
    return *(void**)witness->witness;
}

int32_t ConceptConformance::getOffset(int32_t index) {
    // the table, get as i32***
    auto offs = (int32_t ***)propWitnessOffsets;
    // move to the offset, then load twice
    return **offs[index];
}

RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getWitnessMethod(ExistentialObject *_Nonnull existential,
                      int32_t conformanceIndex,
                      int32_t methodIndex) {
    return existential
    ->getConformance(conformanceIndex)
    ->witnessTable
    ->getWitness(methodIndex);
}
/// EXAMPLE DATA SECTION FOR WITNESS LOOKUP:
//    @_gYconfXwitnessTablewitnessArr0 = constant { i8* } { i8* bitcast (void (%Y*)* @foo_mY to i8*) }
//    @_gYconfXwitnessTablewitnessArr03 = constant { i8* }* @_gYconfXwitnessTablewitnessArr0
//    @_gYconfXwitnessTablewitnessArr = constant [1 x { i8* }**] [{ i8* }** @_gYconfXwitnessTablewitnessArr03]
//    @_gYconfXwitnessTable = constant { { i8* }*, i32 } { { i8* }* bitcast ([1 x { i8* }**]* @_gYconfXwitnessTablewitnessArr to { i8* }*), i32 1 }

RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getPropertyProjection(ExistentialObject *_Nonnull existential,
                           int32_t conformanceIndex,
                           int32_t propertyIndex) {
    auto index = existential
    ->getConformance(conformanceIndex)
    ->getOffset(propertyIndex);
    return (void*)(existential->projectBuffer() + index);
}
/// EXAMPLE DATA SECTION FOR OFFSET LOOKUP:
//    @_gYconfXpropWitnessOffsetArr0 = constant i32 8
//    @_gYconfXpropWitnessOffsetArr01 = constant i32* @_gYconfXpropWitnessOffsetArr0
//    @_gYconfXpropWitnessOffsetArr1 = constant i32 0
//    @_gYconfXpropWitnessOffsetArr12 = constant i32* @_gYconfXpropWitnessOffsetArr1
//    @_gYconfXpropWitnessOffsetArr = constant [2 x i32**] [i32** @_gYconfXpropWitnessOffsetArr01, i32** @_gYconfXpropWitnessOffsetArr12]

RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getExistentialBufferProjection(ExistentialObject *_Nonnull existential) {
    return (void*)existential->projectBuffer();
}


