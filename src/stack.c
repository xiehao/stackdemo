#include <stdlib.h>

#include "stack_internal.h"
#include "stack_array.h"   // 包含顺序存储栈的实现
#include "stack_linked.h"  // 包含链式存储栈的实现

// 工厂函数：根据栈类型创建栈
stack__t *stack_create(StackType type) {
    if (type == STACK_TYPE_ARRAY) {
        return create_array_stack();  // 创建顺序存储栈
    } else if (type == STACK_TYPE_LINKED) {
        return create_linked_stack(); // 创建链式存储栈
    }
    return NULL; // 错误的类型
}

// 全局封装函数
void stack_push(stack__t *stack, int value) {
    stack->push(stack, value);
}

int stack_pop(stack__t *stack) {
    return stack->pop(stack);
}

bool stack_is_empty(stack__t *stack) {
    return stack->is_empty(stack);
}

void stack_destroy(stack__t *stack) {
    stack->destroy(stack);
}