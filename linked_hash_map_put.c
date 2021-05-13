#include "linked_hash_map_put.h"

void put(struct LinkedHashMap *map, int key, int value) {
    struct Entry *elem = (struct Entry *) malloc(sizeof(*elem));
    if (elem == NULL) {
        printf("Error #1: Memory allocation failure while adding new list element");
        exit(1);
    }
    elem->key = key;
    elem->value = value;

    elem->before = NULL;
    elem->after = NULL;
    elem->next = NULL;

    int h = hash(key);
    elem->hash = h;
    int index = indexFor(map, h);

    struct Entry *bucket = map->table[index];
    if (bucket == NULL) {
        map->table[index] = elem;
    } else {
        while (bucket != NULL) {
            if (bucket->hash == h && bucket->key == key) {
                bucket->value = value;
                return;
            }
            if (bucket->next == NULL) {
                bucket->next = elem;
                break;
            } else {
                bucket = bucket->next;
            }
        }
    }

    if (map->head == NULL) {
        map->head = elem;
    } else {
        map->tail->after = elem;
        elem->before = map->tail;
    }

    map->tail = elem;
}