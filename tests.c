#include "tests.h"

void test() {
    struct LinkedHashMap *map = createHashMap();

    testAdd(map);
    testGet(map);
    testRemove(map);

    deleteMap(map);
}

void testAdd(struct LinkedHashMap *map) {
    printf("\nRunning put test on the following map:\n");
    print(map);

    for (int i = 0; i < 10; ++i) {
        printf("Adding pair (%d, %d) to the map\n", i, 10 - i);
        put(map, i, 10 - i);
        print(map);
    }
    int present = map->head->after->after->after->key;
    int value = 25;
    printf("Adding pair with existing key (%d, %d) to the map\n", present, value);
    put(map, present, value);
    print(map);
}

void testGet(struct LinkedHashMap *map) {
    printf("\nRunning get test on the following map:\n");
    print(map);

    int key = 8;
    printf("Requested key: %d; value for the key: %d\n", key, get(map, key)->value);
    key = 2;
    printf("Requested key: %d; value for the key: %d\n", key, get(map, key)->value);
    key = 9;
    printf("Requested key: %d; value for the key: %d\n", key, get(map, key)->value);
    key = 99;
    struct Entry *pair = get(map, key);
    printf("Requested key: %d; value for the key: %s\n", key, pair == NULL ? "NULL" : "");
}

void testRemove(struct LinkedHashMap *map) {
    printf("\nRunning remove test on the following map:\n");
    print(map);

    int key = 4;
    char *result = removeEntry(map, key) ? "true" : "false";
    printf("Removing entry with key %d: %s\n", key, result);
    print(map);

    key = 0;
    result = removeEntry(map, key) ? "true" : "false";
    printf("Removing entry with key %d: %s\n", key, result);
    print(map);

    key = 9;
    result = removeEntry(map, key) ? "true" : "false";
    printf("Removing entry with key %d: %s\n", key, result);
    print(map);

    key = 99;
    result = removeEntry(map, key) ? "true" : "false";
    printf("Removing entry with key %d: %s\n", key, result);
    print(map);

    printf("Removing all entries:\n");
    while (!isEmpty(map)) {
        removeEntry(map, map->head->key);
    }

    print(map);
}