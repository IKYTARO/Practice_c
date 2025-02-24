#include <stdio.h>
#include <stdlib.h>

/*
    Задача состоит в написании функции, которая принимает указатель на вершину дерева
    и печатает на stdout её preorder обход.
*/

struct tree_node {
    struct tree_node* parent;
    struct tree_node* left;
    struct tree_node* right;
    int data;
};

void pre_order(struct tree_node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}
