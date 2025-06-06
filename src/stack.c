#include <stdlib.h>

#include "stack_internal.h"
#include "stack_array.h"   // 包含顺序存储栈的实现
#include "stack_linked.h"  // 包含链式存储栈的实现

struct _stack {
    stack_api_t const *_;
};

// 工厂函数：根据栈类型创建栈
my_stack_t *stack_create(StackType const type) {
    if (type == STACK_TYPE_ARRAY) {
        return create_array_stack(); // 创建顺序存储栈
    } else if (type == STACK_TYPE_LINKED) {
        return create_linked_stack(); // 创建链式存储栈
    }
    return NULL; // 错误的类型
}

// 全局封装函数
void stack_push(my_stack_t *stack, int const value) {
    stack->_->push(stack, value);
}

int stack_pop(my_stack_t *stack) {
    return stack->_->pop(stack);
}

bool stack_is_empty(my_stack_t const *stack) {
    return stack->_->is_empty(stack);
}

void stack_destroy(my_stack_t *stack) {
    stack->_->destroy(stack);
}
