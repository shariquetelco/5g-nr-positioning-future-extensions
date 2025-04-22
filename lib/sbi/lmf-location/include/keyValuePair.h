#ifndef SBI_MAP_H
#define SBI_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct map_s {
    char *key;
    void *value;
} map_t;

typedef map_t keyValuePair_t;

#define keyValuePair_create map_create

map_t *map_create(char *key, void *value);

map_t *map_create_allocate(char *key, double value);

void map_free(map_t *map);

#ifdef __cplusplus
}
#endif

#endif /* SBI_MAP_H */
