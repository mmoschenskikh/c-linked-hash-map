#include <stdlib.h>
#include "linked_hash_map_remove.h"

bool removeEntry(struct LinkedHashMap *map, int key) {
    int h = hash(key);
    int index = indexFor(map, h);

    struct Entry *bucket = map->table[index];
    struct Entry *prev = map->table[index];
    while (bucket != NULL) {
        if (bucket->hash == h && bucket->key == key) {
            if (prev == bucket) {
                map->table[index] = bucket->next;
            }
            prev->next = bucket->next;
            if (bucket == map->head) {
                bucket->after->before = NULL;
                map->head = bucket->after;
            } else if (bucket == map->tail) {
                bucket->before->after = NULL;
                map->tail = bucket->before;
            } else {
                bucket->before->after = bucket->after;
                bucket->after->before = bucket->before;
            }
            free(bucket);
            return true;
        }
        if (bucket->next != NULL) {
            prev = bucket;
            bucket = bucket->next;
        }
    }

    return false;
}