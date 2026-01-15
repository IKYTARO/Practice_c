#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_node {
    struct list_node *next;
    void *data;
} list_t;

#endif // LINKED_LIST_H