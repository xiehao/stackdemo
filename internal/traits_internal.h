/**
 * @file traits_internal.h
 * @brief 定义容器的Trait（特性/接口）系统内部使用的类型和结构。
 *
 * 该文件包含用于实现泛型容器接口的类型定义，
 * 包括通用容器指针、Trait ID枚举以及各种Trait结构体。
 */
#ifndef TRAITS_INTERNAL_H
#define TRAITS_INTERNAL_H

#include <stdbool.h>

/**
 * @brief 定义一个通用的容器指针类型。
 *
 * 这是一个不透明指针，用于指向具体容器实现的实例，隐藏了容器的具体实现细节。
 */
typedef void *container_pt;

/**
 * @brief 定义一个通用的常量容器指针类型。
 *
 * 用于指向具体容器实现的常量实例，确保了通过此指针访问的容器内容不会被修改。
 */
typedef void const *const_container_pt;

/**
 * @brief 定义一个枚举类型，用于标识不同的Trait（特性/接口）。
 *
 * 每个枚举值代表一个特定的Trait ID。
 */
typedef enum {
  TRAIT_ID_COMMON, /**< 通用Trait的ID，例如检查容器是否为空、销毁容器等。 */
  TRAIT_ID_STACK,  /**< 栈Trait的ID，定义了栈特有的操作，如push和pop。 */
} trait_id_t;

/**
 * @brief 定义基础Trait结构体。
 *
 * 所有具体的容器实现都应该能够提供这个基础Trait。
 */
typedef struct {
  /**
   * @brief 函数指针，用于获取容器实现的具体类型名称。
   * @return 返回一个C风格字符串，表示类型的名称。
   */
  const char *(*get_type_name)(void);

  /**
   * @brief 函数指针，用于查询指定ID的Trait。
   *
   * 这是实现Trait系统的核心函数，允许动态查询容器支持的接口。
   * @param id 要查询的Trait的ID。
   * @return 返回一个指向具体Trait结构体的void指针，如果容器不支持该Trait，则返回NULL。
   */
  const void *(*query_trait)(trait_id_t id);
} base_trait_t;

/**
 * @brief 定义通用Trait结构体。
 *
 * 包含所有容器都应该支持的基本操作。
 */
typedef struct {
  /**
   * @brief 函数指针，用于检查容器是否为空。
   * @param container 指向容器实现的常量指针。
   * @return 如果容器为空，返回 `true`；否则返回 `false`。
   */
  bool (*is_empty)(const_container_pt container);

  /**
   * @brief 函数指针，用于销毁容器实例并释放相关资源。
   * @param container 指向容器实现的指针。
   */
  void (*destroy)(container_pt container);
} common_trait_t;

/**
 * @brief 栈接口结构体定义（实现使用）。
 *
 * 定义了栈数据结构应支持的操作。
 */
typedef struct {
  /**
   * @brief 函数指针，用于将一个整数值压入栈顶。
   * @param container 指向容器实现的指针。
   * @param value 要压入栈的整数值。
   */
  void (*push)(container_pt container, int const value);

  /**
   * @brief 函数指针，用于从栈顶弹出一个整数值。
   * @param container 指向容器实现的指针。
   * @return 返回从栈顶弹出的整数值。如果栈为空，行为未定义（具体实现应处理此情况）。
   */
  int (*pop)(container_pt container);
} stack_trait_t;

#endif // TRAITS_INTERNAL_H
