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
} t_linked_stack;

// 链式存储实现的函数
static void linked_stack_push(stack__t *s, int const value) {
    t_linked_stack *ls = (t_linked_stack *) s;
    _node *newNode = (_node *) malloc(sizeof(_node));
    newNode->value = value;
    newNode->next = ls->head;
    ls->head = newNode;
}

static int linked_stack_pop(stack__t *s) {
    t_linked_stack *ls = (t_linked_stack *) s;
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

static bool linked_stack_is_empty(stack__t const *s) {
    t_linked_stack const *ls = (t_linked_stack *) s;
    return ls->head == NULL;
}

static void linked_stack_destroy(stack__t *s) {
    t_linked_stack const *ls = (t_linked_stack *) s;
    _node *current = ls->head;
    while (current) {
        _node *temp = current;
        current = current->next;
        free(temp);
    }
    free(s);
}

static stack_api_t const api = {
    .push = linked_stack_push,
    .pop = linked_stack_pop,
    .is_empty = linked_stack_is_empty,
    .destroy = linked_stack_destroy,
};

// 创建链式存储栈
stack__t *create_linked_stack() {
    t_linked_stack *ls = (t_linked_stack *) malloc(sizeof(t_linked_stack));
    ls->head = NULL;
    ls->_ = &api;
    return (stack__t *) ls;
}
