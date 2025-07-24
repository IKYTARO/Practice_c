#include "HashMap.h"

struct hashpair_t {
    unsigned key;
    char *value;
    struct hashpair_t *next;
};

struct hashmap_t {
    unsigned capacity;           
    unsigned size;               
    struct hashpair_t **buckets; 
};

struct hashmap_t *hashmap_create(unsigned m) {

}

int hashmap_add(struct hashmap_t *map, unsigned key,
                char const *value) {

}

char const *hashmap_find(struct hashmap_t *map, unsigned key) {

}

void hashmap_destroy(struct hashmap_t *map) {

}