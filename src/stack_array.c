#include <stdio.h>
#include <stdlib.h>

#include "stack_internal.h"

#define MAX_SIZE 100

typedef struct {
    stack_api_t const *_;
    int data[MAX_SIZE];
    int top;
} stack;

// 顺序存储实现的函数
static void push(my_stack_t *s, int const value) {
    stack *as = (stack *) s;
    if (as->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    as->data[++(as->top)] = value;
}

static int pop(my_stack_t *s) {
    stack *as = (stack *) s;
    if (as->top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return as->data[(as->top)--];
}

static bool is_empty(my_stack_t const *s) {
    stack const *as = (stack *) s;
    return as->top == -1;
}

static void destroy(my_stack_t *s) { free(s); }

static stack_api_t const api = {
    .push = push,
    .pop = pop,
    .is_empty = is_empty,
    .destroy = destroy,
};

// 创建顺序存储栈
my_stack_t *create_array_stack() {
    stack *as = (stack *) malloc(sizeof(stack));
    as->top = -1;
    as->_ = &api;
    return (my_stack_t *) as;
}
