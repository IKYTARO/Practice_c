#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

int loop_length(struct node_t *root) {
    int has_loop = 0;
    struct node_t *rabbit = root;
    struct node_t *turtle = root;

    while (rabbit != NULL) {
        rabbit = rabbit->next;
        if (rabbit == NULL) return 0;
        if (rabbit == turtle) {
            has_loop = 1;
            break;
        }
        rabbit = rabbit->next;
        turtle = turtle->next;
        if (rabbit == turtle) {
            has_loop = 1;
            break;
        }
    }

    if (!has_loop) return 0;

    int length = 1;
    rabbit = rabbit->next;
    while (rabbit != turtle) {
        rabbit = rabbit->next;
        length++;
    }

    return length;
}
