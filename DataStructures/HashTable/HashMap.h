#ifndef HASHTABLE_H
#define HASHTABLE_H

struct hashmap_t;

struct hashmap_t *hashmap_create(unsigned m);
int hashmap_add(struct hashmap_t *map, unsigned key,
                char const *value);

char const *hashmap_find(struct hashmap_t *map, unsigned key);
void hashmap_destroy(struct hashmap_t *map);

#endif