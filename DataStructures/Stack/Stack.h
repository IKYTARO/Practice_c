#ifndef STACK_H
#define STACK_H

struct stack_node {
    struct stack_node *next;
    int data;
};

struct stack_node *make_stack(int data);
void stack_push(struct stack_node **root, int data);
int stack_pop(struct stack_node **root);
int stack_count(struct stack_node *root);
int is_empty(struct stack_node const *root);
void stack_free(struct stack_node *root);

#endif