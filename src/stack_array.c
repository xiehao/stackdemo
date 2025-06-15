#include <stdio.h>
#include <stdlib.h>

#include "traits_internal.h"
#include "stack.h"

#define MAX_SIZE 100

typedef struct {
  base_trait_t const *_;
  int data[MAX_SIZE];
  int top;
} stack;

// 顺序存储实现的函数
static void push(container_pt s, int const value) {
  stack *as = (stack *)s;
  if (as->top >= MAX_SIZE - 1) {
    printf("Stack overflow\n");
    return;
  }
  as->data[++(as->top)] = value;
}

static int pop(container_pt s) {
  stack *as = (stack *)s;
  if (as->top < 0) {
    printf("Stack underflow\n");
    return -1;
  }
  return as->data[(as->top)--];
}

static bool is_empty(const_container_pt s) {
  stack const *as = (stack *)s;
  return as->top == -1;
}

static void destroy(container_pt s) { free(s); }

static common_trait_t const common_trait = {
    .is_empty = is_empty,
    .destroy = destroy,
};

static stack_trait_t const stack_trait = {
    .push = push,
    .pop = pop,
};

static char const *get_name() { return "stack"; }
static void const *query_trait(trait_id_t id) {
  switch (id) {
  case TRAIT_ID_COMMON:
    return &common_trait;
  case TRAIT_ID_STACK:
    return &stack_trait;
  default:
    return NULL;
  }
}

static base_trait_t const base_trait = {
    .get_type_name = get_name,
    .query_trait = query_trait,
};

// 创建顺序存储栈
my_stack_t *create_array_stack() {
  stack *as = (stack *)malloc(sizeof(stack));
  as->top = -1;
  as->_ = &base_trait;
  return (my_stack_t *)as;
}
