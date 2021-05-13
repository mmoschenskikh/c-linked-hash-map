#ifndef LINKED_HASH_MAP_LINKED_HASH_MAP_STRUCT_H
#define LINKED_HASH_MAP_LINKED_HASH_MAP_STRUCT_H

#include "linked_hash_map_entry.h"
#include "stdio.h"

struct LinkedHashMap {
    size_t size;

    struct Entry *table[16];
    struct Entry *head;
    struct Entry *tail;
};

#endif
