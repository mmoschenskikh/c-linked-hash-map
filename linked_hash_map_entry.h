#ifndef LINKED_HASH_MAP_LINKED_HASH_MAP_ENTRY_H
#define LINKED_HASH_MAP_LINKED_HASH_MAP_ENTRY_H

struct Entry {
    int key;
    int value;

    struct Entry *next; // Next Entry in the bucket
    struct Entry *after; // Next Entry in the list
    struct Entry *before;
};

#endif
