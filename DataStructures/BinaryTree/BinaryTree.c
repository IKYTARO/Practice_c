#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    struct tree_node *left;
    struct tree_node *right;
    int data;
};

struct tree_file_t {
    int n;
    int* topology; // 2 * n
    int* values;   // n
};

struct stack_node {
    struct stack_node* next;
    struct tree_node* data;
};

void stack_push(struct stack_node** stack, struct tree_node* data) {
    struct stack_node* new_node = (struct stack_node*) calloc(1, sizeof(struct stack_node));
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

struct tree_file_t read_file(FILE *f) {
    struct tree_file_t ret;
    int res, i;

    res = fscanf(f, "%d", &ret.n);
    assert(res == 1);

    ret.topology = calloc(2 * ret.n, sizeof(int));
    ret.values = calloc(ret.n, sizeof(int));

    for (i = 0; i < 2 * ret.n; ++i) {
        res = fscanf(f, "%d", ret.topology + i);
        assert(res == 1);
    }

    for (i = 0; i < ret.n; ++i) {
        res = fscanf(f, "%d", ret.values + i);
        assert(res == 1);
    }

    return ret;
}

void free_temp(struct tree_file_t data) {
    free(data.topology);
    free(data.values);
}

void free_tree(struct tree_node *top) {
    if (top == NULL)
        return;
    free_tree(top->left);
    free_tree(top->right);
    free(top);
}

struct tree_node *create_node(int data, struct tree_node *l, struct tree_node *r) {
    struct tree_node *ret = malloc(sizeof(struct tree_node));
    assert(ret);

    ret->left = l;
    ret->right = r;
    ret->data = data;
    return ret;
}

struct tree_node *do_recover(struct tree_file_t data, int *cursor, int *curval) {
    struct tree_node *n = NULL;
    int cur = *cursor;
    int curv = *curval;
    *cursor += 1;
    if (cur < (data.n * 2) && data.topology[cur] == 1) {
        struct tree_node *l, *r;
        *curval += 1;
        l = do_recover(data, cursor, curval);
        r = do_recover(data, cursor, curval);
        assert(curv < data.n);
        n = create_node(data.values[curv], l, r);
    }
    return n;
}

struct tree_node *recover(struct tree_file_t data) {
    int cursor = 0;
    int curval = 0;
    return do_recover(data, &cursor, &curval);
}

void print_pre(struct tree_node* root) {
    struct stack_node* stack = (struct stack_node*) calloc(1, sizeof(struct stack_node));
    struct tree_node* curr_node;
    stack_push(&stack, root);
    while (&stack != NULL) {
        curr_node = stack_pop(&stack);
        if (curr_node != NULL) {
            printf("%d ", curr_node->data);
            stack_push(&stack, curr_node->left);
            stack_push(&stack, curr_node->right);
        }
    }
}

int main() {
    int is_search;
    struct tree_node *top;
    struct tree_file_t filetree;

    // read tree from file
    filetree = read_file(stdin);

    // recover tree
    top = recover(filetree);

    // print preorder
    print_pre(top);
    printf("\n");

    // free everything
    free_tree(top);
    free_temp(filetree);
}
