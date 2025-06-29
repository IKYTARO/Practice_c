#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
    int data;
};

struct tree_file {
    int n;
    int *topology;  // 2 * n
    int *values;    // n
};

struct tree_file read_file(FILE *f) {
    struct tree_file ret;
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

void free_temp(struct tree_file data) {
    free(data.topology);
    free(data.values);
}

void free_tree(struct tree_node *top) {
    if (top == NULL) return;
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

struct tree_node *do_recover(struct tree_file data, int *cursor, int *curval) {
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

struct tree_node *recover(struct tree_file data) {
    int cursor = 0;
    int curval = 0;
    return do_recover(data, &cursor, &curval);
}

int main() {
    int is_search;
    struct tree_node *top;
    struct tree_file filetree;

    // read tree from file
    filetree = read_file(stdin);

    // recover tree
    top = recover(filetree);

    // free everything
    free_tree(top);
    free_temp(filetree);
}
