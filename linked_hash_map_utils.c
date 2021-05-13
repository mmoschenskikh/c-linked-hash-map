#include "linked_hash_map_utils.h"

int hash(int key) {
    key ^= (key >> 20) ^ (key >> 12);
    return key ^ (key >> 7) ^ (key >> 4);
}

int indexFor(int hash, int buckets) {
    return hash & (buckets - 1);
}

bool isEmpty(struct LinkedHashMap *map) {
    return map->head == NULL;
}

int getLength(struct LinkedHashMap *map) {
    int length = 0;
    struct Entry *current = map->head;

    while (current != NULL) {
        length++;
        current = current->after;
    }
    return length;
}

void print(struct LinkedHashMap *map) {
    struct Entry *current = map->head;

    printf("{");
    while (current != NULL) {
        printf("(%d, %d)", current->key, current->value);
        current = current->after;
        if (current != NULL) {
            printf(", ");
        }
    }
    printf("}\n");
}