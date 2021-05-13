#include "linked_hash_map.h"

struct LinkedHashMap *createHashMap() {
    struct LinkedHashMap *map = (struct LinkedHashMap *) malloc(sizeof(*map));
    if (map == NULL) {
        printf("Error #1: Memory allocation failure while creating new hash map");
        exit(1);
    }
    map->head = NULL;
    map->tail = NULL;

    int buckets = sizeof(map->table) / sizeof(map->table[0]);
    for (int i = 0; i < buckets; ++i) {
        map->table[i] = NULL;
    }
    return map;
}

void deleteMap(struct LinkedHashMap *map) {
    struct Entry *elem = map->head;
    if (elem == NULL) {
        free(map);
        return;
    }
    struct Entry *next = map->head->after;
    while (next != NULL) {
        free(elem);
        elem = next;
        next = elem->next;
    }
    free(elem);
    free(map);
}