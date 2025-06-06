#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// 栈类型枚举
typedef enum {
    STACK_TYPE_ARRAY,
    STACK_TYPE_LINKED
} StackType;

// 栈类型的不透明声明（仅声明，不定义）
typedef struct _stack stack__t;

// 工厂函数：创建栈实例
stack__t *stack_create(StackType const type);

// 全局封装操作函数
void stack_push(stack__t *stack, int const value);

int stack_pop(stack__t *stack);

bool stack_is_empty(stack__t const *stack);

void stack_destroy(stack__t *stack);

#endif // STACK_H
