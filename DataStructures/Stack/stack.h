#ifndef STACK_H
#define STACK_H

typedef struct stacknode {
    struct stacknode *next;
    void *data;
} stack_t;

void stack_push(stack_t **root, void *data);
void *stack_pop(stack_t **root);

int empty(stack_t const *root);

void stack_free(stack_t *stack);

#endif