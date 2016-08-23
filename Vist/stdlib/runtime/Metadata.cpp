//
//  Metadata.cpp
//  Vist
//
//  Created by Josef Willsher on 10/5/2016.
//  Copyright © 2015 vistlang. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cstring>

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
void vist_constructExistential(ConceptConformance *_Nonnull conformance,
                               void *_Nonnull instance,
                               TypeMetadata *_Nonnull metadata,
                               bool isNonLocal,
                               ExistentialObject *_Nullable outExistential) {
    uintptr_t ptr;
    if (isNonLocal) {
        auto mem = malloc(metadata->size);
        // copy stack into new buffer
        memcpy(mem, instance, metadata->size);
        // set stack source to 0
        memset(instance, 0, metadata->size);
        ptr = (uintptr_t)mem;
        printf("alloc: %p\n", mem);
    } else {
        printf("alloc_stack: %p\n", instance);
        ptr = (uintptr_t)instance;
    }
    
    // mask tagged pointer
    ptr |= isNonLocal;
    *outExistential = ExistentialObject(ptr, metadata, 1, (ConceptConformance **)conformance);
}

RUNTIME_COMPILER_INTERFACE
void vist_deallocExistentialBuffer(ExistentialObject *_Nonnull existential) {
    printf("dealloc: %p\n", existential->projectBuffer());
    if (auto buff = (void *)existential->projectBuffer()) {
        // call the destructor
        if (auto destructor = existential->metadata->destructor) {
            printf("destructor: %p\n", existential->metadata->destructor);
            destructor(buff);
        }
        // if stored on the heap, dealloc it
        if (existential->isNonLocal())
            free(buff);
        else // for debugging we also memset stack to 0
            memset(buff, 0, existential->metadata->size);
    }
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

RUNTIME_COMPILER_INTERFACE
void vist_exportExistentialBuffer(ExistentialObject *_Nonnull existential) {
    auto in = existential->projectBuffer();
    if (existential->isNonLocal()) {
        printf("dupe_export: %p\n", in);
        return;
    }
    auto mem = malloc(existential->metadata->size);
    // copy stack into new buffer
    memcpy(mem, (void*)existential->projectBuffer(), existential->metadata->size);
    existential->instanceTaggedPtr = (uintptr_t)mem | true;
    printf("export: %p to: %p\n", in, existential->projectBuffer());
}

RUNTIME_COMPILER_INTERFACE
void vist_copyExistentialBuffer(ExistentialObject *_Nonnull existential,
                                ExistentialObject *_Nullable outExistential) {
    auto in = existential->projectBuffer();
    auto mem = malloc(existential->metadata->size);
    // copy stack into new buffer
    memcpy(mem, (void*)existential->projectBuffer(), existential->metadata->size);
    *outExistential = ExistentialObject((uintptr_t)mem | true,
                                        existential->metadata, 
                                        existential->numConformances,
                                        existential->conformances);
    printf("copy: %p to: %p\n", in, outExistential->projectBuffer());
}




#ifdef TESTING

int main() {
    return 0;
}

#endif



