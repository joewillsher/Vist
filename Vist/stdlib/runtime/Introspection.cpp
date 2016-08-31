//
//  Introspection.cpp
//  Vist
//
//  Created by Josef Willsher on 31/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


RUNTIME_STDLIB_INTERFACE
void *_Nonnull vist_runtime_getMetadata(ExistentialObject *_Nonnull ex) {
    return ex->metadata;
}
RUNTIME_STDLIB_INTERFACE
int64_t vist_runtime_metadataGetSize(void *_Nonnull md) {
    auto metadata = (TypeMetadata*)md;
    return metadata->size;
}
RUNTIME_STDLIB_INTERFACE
void *_Nonnull vist_runtime_metadataGetName(void *_Nonnull md) {
    auto metadata = (TypeMetadata*)md;
    return (void *)vist_demangle(metadata->name);
}

