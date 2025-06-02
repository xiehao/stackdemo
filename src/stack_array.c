#include <stdio.h>
#include <stdlib.h>

#include "stack_internal.h"

#define MAX_SIZE 100

typedef struct {
    stack__t base;
    int data[MAX_SIZE];
    int top;
} t_array_stack;

// 顺序存储实现的函数
void array_stack_push(stack__t *s, int value) {
    t_array_stack *as = (t_array_stack *)s;
    if (as->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    as->data[++(as->top)] = value;
}

int array_stack_pop(stack__t *s) {
    t_array_stack *as = (t_array_stack *)s;
    if (as->top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return as->data[(as->top)--];
}

bool array_stack_is_empty(stack__t *s) {
    t_array_stack *as = (t_array_stack *)s;
    return as->top == -1;
}

void array_destroy(stack__t *s) { free(s); }

// 创建顺序存储栈
stack__t *create_array_stack() {
    t_array_stack *as = (t_array_stack *)malloc(sizeof(t_array_stack));
    as->top = -1;
    as->base.push = array_stack_push;
    as->base.pop = array_stack_pop;
    as->base.is_empty = array_stack_is_empty;
    as->base.destroy = array_destroy;
    return (stack__t *)as;
}
