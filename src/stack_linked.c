#include <stdio.h>
#include <stdlib.h>

#include "traits_internal.h"
#include "stack.h"

typedef struct _node {
    int value;
    struct _node *next;
} _node;

typedef struct {
    base_trait_t const *_;
    _node *head;
} stack;

// 链式存储实现的函数
static void push(container_pt s, int const value) {
    stack *ls = (stack *) s;
    _node *newNode = (_node *) malloc(sizeof(_node));
    newNode->value = value;
    newNode->next = ls->head;
    ls->head = newNode;
}

static int pop(container_pt s) {
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

static bool is_empty(const_container_pt s) {
    stack const *ls = (stack *) s;
    return ls->head == NULL;
}

static void destroy(container_pt s) {
    stack const *ls = (stack *) s;
    _node *current = ls->head;
    while (current) {
        _node *temp = current;
        current = current->next;
        free(temp);
    }
    free(s);
}

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

// 创建链式存储栈
my_stack_t *create_linked_stack() {
    stack *ls = (stack *) malloc(sizeof(stack));
    ls->head = NULL;
    ls->_ = &base_trait;
    return (my_stack_t *) ls;
}
