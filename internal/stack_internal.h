#ifndef STACK_INTERNAL_H
#define STACK_INTERNAL_H

#include "stack.h"

// 栈接口结构体定义（实现使用）
struct _stack {
    void (*push)(struct _stack *impl, int value);
    int (*pop)(struct _stack *impl);
    bool (*is_empty)(struct _stack *impl);
    void (*destroy)(struct _stack *impl);
};

#endif // STACK_INTERNAL_H
