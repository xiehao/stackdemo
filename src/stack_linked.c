#include <stdio.h>
#include <stdlib.h>

#include "stack_internal.h"

typedef struct _node {
    int value;
    struct _node *next;
} _node;

typedef struct {
    stack__t base;
    _node *head;
} t_linked_stack;

// 链式存储实现的函数
void linked_stack_push(stack__t *s, int value) {
    t_linked_stack *ls = (t_linked_stack *)s;
    _node *newNode = (_node *)malloc(sizeof(_node));
    newNode->value = value;
    newNode->next = ls->head;
    ls->head = newNode;
}

int linked_stack_pop(stack__t *s) {
    t_linked_stack *ls = (t_linked_stack *)s;
    if (!ls->head) {
        printf("Stack underflow\n");
        return -1;
    }
    _node *temp = ls->head;
    int value = temp->value;
    ls->head = temp->next;
    free(temp);
    return value;
}

bool linked_stack_is_empty(stack__t *s) {
    t_linked_stack *ls = (t_linked_stack *)s;
    return ls->head == NULL;
}

void linked_stack_destroy(stack__t *s) {
    t_linked_stack *ls = (t_linked_stack *)s;
    _node *current = ls->head;
    while (current) {
        _node *temp = current;
        current = current->next;
        free(temp);
    }
    free(s);
}

// 创建链式存储栈
stack__t *create_linked_stack() {
    t_linked_stack *ls = (t_linked_stack *)malloc(sizeof(t_linked_stack));
    ls->head = NULL;
    ls->base.push = linked_stack_push;
    ls->base.pop = linked_stack_pop;
    ls->base.is_empty = linked_stack_is_empty;
    ls->base.destroy = linked_stack_destroy;
    return (stack__t *)ls;
}
