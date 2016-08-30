//
//  Casting.cpp
//  Vist
//
//  Created by Josef Willsher on 10/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



// introspection

RUNTIME_STDLIB_INTERFACE
void *vist_runtime_getMetadata(ExistentialObject *ex) {
    return ex->metadata;
}
RUNTIME_STDLIB_INTERFACE
int64_t vist_runtime_metadataGetSize(void *md) {
    auto metadata = (TypeMetadata*)md;
    return metadata->size;
}
RUNTIME_STDLIB_INTERFACE
void *vist_runtime_metadataGetName(void *md) {
    auto metadata = (TypeMetadata*)md;
    return (void *)vist_demangle(metadata->name);
}

