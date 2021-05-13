#ifndef LINKED_HASH_MAP_LINKED_HASH_MAP_H
#define LINKED_HASH_MAP_LINKED_HASH_MAP_H

#include "linked_hash_map_put.h"
#include "linked_hash_map_get.h"
#include "linked_hash_map_remove.h"

struct LinkedHashMap *createHashMap();

void deleteMap(struct LinkedHashMap *map);

#endif
