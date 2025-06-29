#include "Stack.h"

#include <assert.h>
#include <stdlib.h>

struct stack_node *make_stack(int data) {
    struct stack_node *root = (struct stack_node *)calloc(1, sizeof(struct stack_node));
    root->data = data;
    root->next = NULL;
    return root;
}

void stack_push(struct stack_node **root, int data) {
    assert(root != NULL);
    struct stack_node *new_node = (struct stack_node *)calloc(1, sizeof(struct stack_node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->next = *root;
    *root = new_node;
}

int stack_pop(struct stack_node **root) {
    assert(root != NULL);
    int data = (*root)->data;
    struct stack_node *new_root = (*root)->next;
    free(*root);
    (*root) = new_root;
    return data;
}

int stack_count(struct stack_node *root) {
    int stack_size = 0;
    struct stack_node *curr_node = root;
    while (curr_node) {
        stack_size++;
        curr_node = curr_node->next;
    }
    return stack_size;
}

int is_empty(struct stack_node const *root) { return root == NULL; }

void stack_free(struct stack_node *root) {
    assert(root != NULL);
    struct stack_node *curr_node = root;
    while (curr_node) {
        struct stack_node *next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
}