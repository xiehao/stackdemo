#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// 栈类型枚举
typedef enum {
    STACK_TYPE_ARRAY,
    STACK_TYPE_LINKED
} StackType;

// 栈类型的不透明声明（仅声明，不定义）
typedef struct _stack my_stack_t;

// 工厂函数：创建栈实例
my_stack_t *stack_create(StackType const type);

// 全局封装操作函数
void stack_push(my_stack_t *stack, int const value);

int stack_pop(my_stack_t *stack);

bool stack_is_empty(my_stack_t const *stack);

void stack_destroy(my_stack_t *stack);

#endif // STACK_H
