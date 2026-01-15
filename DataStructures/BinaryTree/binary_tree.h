#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree_node {
    struct binary_tree_node *parent;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
    void *data;
} binary_tree_t;

/**
 * @brief Функция для обработки данных, лежащих в узле дерева
 */
typedef void (*data_handler)(void *);

/**
 * @brief Рекурсивная функция preorder обхода
 *
 * @param root Указатель на вершину дерева
 * @param handler Функция для обработки данных
 */
void preorder_traversal(binary_tree_t *root, data_handler handler);

/**
 * @brief Итеративная функция preorder обхода
 *
 * @param root Указатель на вершину дерева
 * @param handler Функция для обработки данных
 */
void preorder_iterative(binary_tree_t *root, data_handler handler);

#endif  // BINARY_TREE_H