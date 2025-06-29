#include <assert.h>
#include <stdio.h>

#include "Stack.h"

#define SUCCESS 1
#define FAIL 0

int test_empty();
int test_count();
int test_one_element();
int test_two_elements();

int main() {
    char *test_result;

    test_result = (test_empty() == SUCCESS) ? "SUCCESS" : "FAIL";
    printf("TEST EMPTY:        %s\n", test_result);

    test_result = (test_count() == SUCCESS) ? "SUCCESS" : "FAIL";
    printf("TEST COUNT:        %s\n", test_result);

    test_result = (test_one_element() == SUCCESS) ? "SUCCESS" : "FAIL";
    printf("TEST ONE ELEMENT:  %s\n", test_result);

    test_result = (test_two_elements() == SUCCESS) ? "SUCCESS" : "FAIL";
    printf("TEST TWO ELEMENTS: %s\n", test_result);

    return 0;
}

int test_empty() {
    int test_status = 1;
    struct stack_node *stack = make_stack(13);
    test_status *= !is_empty(stack);
    stack_pop(&stack);
    test_status *= is_empty(stack);
    return test_status;
}

int test_count() {
    int test_status = 1;
    struct stack_node *stack = make_stack(13);
    test_status *= (stack_count(stack) == 1);
    stack_push(&stack, 11);
    test_status *= (stack_count(stack) == 2);
    stack_push(&stack, 10);
    test_status *= (stack_count(stack) == 3);
    stack_pop(&stack);
    test_status *= (stack_count(stack) == 2);
    stack_pop(&stack);
    test_status *= (stack_count(stack) == 1);
    stack_pop(&stack);
    test_status *= (stack_count(stack) == 0);
    return test_status;
}

int test_one_element() {
    struct stack_node *stack = make_stack(13);
    return (stack_pop(&stack) == 13);
}

int test_two_elements() {
    int test_status = 1;
    struct stack_node *stack = make_stack(13);
    stack_push(&stack, 7);
    test_status = (stack_pop(&stack) == 7);
    test_status = (stack_pop(&stack) == 13);
    return test_status;
}