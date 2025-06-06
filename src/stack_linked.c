#include <stdio.h>
#include <stdlib.h>

#include "stack_internal.h"

typedef struct _node {
    int value;
    struct _node *next;
} _node;

typedef struct {
    stack_api_t const *_;
    _node *head;
} stack;

// 链式存储实现的函数
static void push(my_stack_t *s, int const value) {
    stack *ls = (stack *) s;
    _node *newNode = (_node *) malloc(sizeof(_node));
    newNode->value = value;
    newNode->next = ls->head;
    ls->head = newNode;
}

static int pop(my_stack_t *s) {
    stack *ls = (stack *) s;
    if (!ls->head) {
        printf("Stack underflow\n");
        return -1;
    }
    _node *temp = ls->head;
    int const value = temp->value;
    ls->head = temp->next;
    free(temp);
    return value;
}

static bool is_empty(my_stack_t const *s) {
    stack const *ls = (stack *) s;
    return ls->head == NULL;
}

static void destroy(my_stack_t *s) {
    stack const *ls = (stack *) s;
    _node *current = ls->head;
    while (current) {
        _node *temp = current;
        current = current->next;
        free(temp);
    }
    free(s);
}

static stack_api_t const api = {
    .push = push,
    .pop = pop,
    .is_empty = is_empty,
    .destroy = destroy,
};

// 创建链式存储栈
my_stack_t *create_linked_stack() {
    stack *ls = (stack *) malloc(sizeof(stack));
    ls->head = NULL;
    ls->_ = &api;
    return (my_stack_t *) ls;
}
