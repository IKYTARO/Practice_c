#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t* next;
    int data;
};

int has_loop(struct node_t* root) {
    struct node_t* rabbit = root;
    struct node_t* turtle = root;
    while (rabbit != NULL) {
        rabbit = rabbit->next;
        if (rabbit == NULL) return 0;
        if (rabbit == turtle) return 1;
        rabbit = rabbit->next;
        turtle = turtle->next;
        if (rabbit == turtle) return 1;
    }
    return 0;
}

int main() {
    int i, nnodes, looppos, res, outcome, correct_outcome;
    struct node_t *top = NULL, *cur = NULL, *loopelem = NULL;

    res = scanf("%d%d%d", &nnodes, &looppos, &correct_outcome);
    assert(res == 3);
    assert(nnodes >= 0);
    assert(looppos > -2);
    assert(looppos < nnodes);
    assert(correct_outcome == 0 || correct_outcome == 1);

    if (nnodes > 0) {
        top = calloc(1, sizeof(struct node_t));
        cur = top;
        if (looppos == 0) loopelem = cur;
    }

    for (i = 1; i < nnodes; ++i) {
        cur->next = calloc(1, sizeof(struct node_t));
        if (looppos == i) loopelem = cur;
        cur = cur->next;
    }

    if (looppos != -1) cur->next = loopelem;

    outcome = has_loop(top);
    if (outcome == correct_outcome)
        printf("OK\n");
    else
        printf("Failed: answer {%d} != correct {%d}\n", outcome, correct_outcome);
    return 0;
}
