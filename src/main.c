#include <stdio.h>
#include "stack.h"

int main() {
    // 创建顺序存储栈
    my_stack_t *stack = stack_create(STACK_TYPE_ARRAY);
    stack_push(stack, 10);
    stack_push(stack, 20);
    printf("Pop: %d\n", stack_pop(stack));
    printf("Is Empty: %d\n", stack_is_empty(stack));

    // 切换到链式存储栈
    stack_destroy(stack); // 销毁旧栈
    stack = stack_create(STACK_TYPE_LINKED); // 创建链式存储栈
    stack_push(stack, 30);
    stack_push(stack, 40);
    printf("Pop: %d\n", stack_pop(stack));
    printf("Is Empty: %d\n", stack_is_empty(stack));

    stack_destroy(stack); // 销毁栈
    return 0;
}