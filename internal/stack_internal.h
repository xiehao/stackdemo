#ifndef STACK_INTERNAL_H
#define STACK_INTERNAL_H

#include "stack.h"

// 栈接口结构体定义（实现使用）
typedef struct {
    void (*push)(struct _stack *impl, int const value);

    int (*pop)(struct _stack *impl);

    bool (*is_empty)(struct _stack const *impl);

    void (*destroy)(struct _stack *impl);
} stack_api_t;

#endif // STACK_INTERNAL_H
