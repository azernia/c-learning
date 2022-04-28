#ifndef _LINKEDSTACK_H_
#define _LINKEDSTACK_H_

#include "LinkedStackData.h"

/**
 * 初始化栈
 * @param stack 操作的栈
 */
void initLinkedStack(LinkedStatck *stack);

/**
 * 压栈（入栈）
 * @param stack 操作的栈
 * @param element 入栈元素
 * @return int 0-成功 1-失败
 */
int push(LinkedStatck *stack, ElementType element);

/**
 * 出栈
 * @param stack 操作的栈
 * @param element 出栈的元素
 * @return int 0-成功 1-失败
 */
int pop(LinkedStatck *stack, ElementType *element);

/**
 * 清空栈
 * @param stack 操作的栈
 */
void clear(LinkedStatck *stack);

/**
 * 销毁栈
 * @param stack 操作的栈
 */
void destory(LinkedStatck *stack);

#endif
