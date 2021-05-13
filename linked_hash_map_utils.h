#ifndef LINKED_HASH_MAP_LINKED_HASH_MAP_UTILS_H
#define LINKED_HASH_MAP_LINKED_HASH_MAP_UTILS_H

#include "linked_hash_map_struct.h"
#include <stdbool.h>
#include <stdio.h>

int hash(int key);

int indexFor(struct LinkedHashMap *map, int hash);

bool isEmpty(struct LinkedHashMap *map);

int getLength(struct LinkedHashMap *map);

void print(struct LinkedHashMap *map);

#endif //LINKED_HASH_MAP_LINKED_HASH_MAP_UTILS_H
