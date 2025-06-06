#include <stdio.h>
#include <stdlib.h>

#include "stack_internal.h"

#define MAX_SIZE 100

typedef struct {
    stack_api_t const *_;
    int data[MAX_SIZE];
    int top;
} t_array_stack;

// 顺序存储实现的函数
static void array_stack_push(stack__t *s, int const value) {
    t_array_stack *as = (t_array_stack *) s;
    if (as->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    as->data[++(as->top)] = value;
}

static int array_stack_pop(stack__t *s) {
    t_array_stack *as = (t_array_stack *) s;
    if (as->top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return as->data[(as->top)--];
}

static bool array_stack_is_empty(stack__t const *s) {
    t_array_stack const *as = (t_array_stack *) s;
    return as->top == -1;
}

static void array_destroy(stack__t *s) { free(s); }

static stack_api_t const api = {
    .push = array_stack_push,
    .pop = array_stack_pop,
    .is_empty = array_stack_is_empty,
    .destroy = array_destroy,
};

// 创建顺序存储栈
stack__t *create_array_stack() {
    t_array_stack *as = (t_array_stack *) malloc(sizeof(t_array_stack));
    as->top = -1;
    as->_ = &api;
    return (stack__t *) as;
}
