#include <stdio.h>
#include <stdlib.h>

/*
    Задача состоит в написании функции, которая принимает указатель на вершину дерева
    и печатает на stdout её preorder обход. Функция должна быть итеративной и использовать явный стек.
*/

struct tree_node {
    struct tree_node* parent;
    struct tree_node* left;
    struct tree_node* right;
    int data;
};

struct stack_node {
    struct stack_node* next;
    struct tree_node* data;
};

void stack_push(struct stack_node** stack, struct tree_node* data) {
    struct stack_node* new_node = 
        (struct stack_node*) calloc(1, sizeof(struct stack_node));
    new_node->data = data;
    new_node->next = (*stack);
    (*stack) = new_node;
}

struct tree_node* stack_pop(struct stack_node** stack) {
    if (*stack == NULL)
        return NULL;
    struct tree_node* data = (*stack)->data;
    struct stack_node* new_head = (*stack)->next;
    free(*stack);
    *stack = new_head;
    return data;
}

int empty(struct stack_node* stack) {
    if (stack == NULL)
        return 1;
    return 0;
}

void pre_order(struct tree_node* root) {
    struct stack_node* stack = NULL;
    struct tree_node* curr_node;
    stack_push(&stack, root);
    while (!empty(stack)) {
        curr_node = stack_pop(&stack);
        printf("%d ", curr_node->data);
        if (curr_node->right)
            stack_push(&stack, curr_node->right);
        if (curr_node->left)
            stack_push(&stack, curr_node->left);
    }
}
