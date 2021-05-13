#include "linked_hash_map_get.h"

struct Entry *get(struct LinkedHashMap *map, int key) {
    int h = hash(key);
    int index = indexFor(map, h);

    struct Entry *bucket = map->table[index];
    while (bucket != NULL) {
        if (bucket->hash == h && bucket->key == key) {
            return bucket;
        }
        bucket = bucket->next;
    }

    return NULL;
}