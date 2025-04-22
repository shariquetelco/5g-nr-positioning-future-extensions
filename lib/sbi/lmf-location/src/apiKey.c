#include <stdlib.h>
#include <string.h>
#include "../include/keyValuePair.h"

map_t *map_create(char *key, void *value)
{
    map_t *map = NULL;

    map = malloc(sizeof(map_t));
    map->key = key;
    map->value = value;

    return map;
}

map_t *map_create_allocate(char *key, double value)
{
    double* boolpointer = malloc(sizeof(value));
    memcpy(boolpointer, &value, sizeof(value));
    return map_create(key, boolpointer);
}

void map_free(map_t *map)
{
    free(map);
}
