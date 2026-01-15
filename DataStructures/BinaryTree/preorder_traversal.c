#include "binary_tree.h"

void preorder_traversal(binary_tree_t *root, data_handler handler) {
    if (!root) return;

    handler(root->data);
    preorder_traversal(root->left, handler);
    preorder_traversal(root->right, handler);
}