#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

#include "SeqStackData.h"

/**
 * @brief 初始化栈
 * 
 * @param stack 操作的栈
 */
void initSeqStack(SeqStack *stack);

/**
 * 向栈中压入元素
 * 
 * @param stack 操作的栈
 * @param element 压入的元素
 * @return int 0-成功 1-失败
 */
int push(SeqStack *stack, ElementType element);

/**
 * 出栈
 * @param stack 操作的栈
 * @param element 元素
 * @return int 0-成功 1-失败
 */
int pop(SeqStack *stack, ElementType *element);

/**
 * 清空栈
 * @param stack 操作的栈
 */
void clearStack(SeqStack *stack);

/**
 * 栈是否为空
 * @param stack 操作的栈
 * @return int 0-true 1-false
 */
int isEmpty(SeqStack *stack);

/**
 * @brief 获取栈顶元素
 * 
 * @param stack 操作的栈
 * @param element 元素
 */
void getTopElement(SeqStack *stack, ElementType *element);

#endif