#include "linked_hash_map_utils.h"

int hash(int key) {
    key ^= (key >> 20) ^ (key >> 12);
    return key ^ (key >> 7) ^ (key >> 4);
}

int indexFor(int hash, int buckets) {
    return hash & (buckets - 1);
}