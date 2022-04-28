#include <stdio.h>
#include <stdlib.h>
#include "../head/LinkedStack.h"
#include "../head/LinkedStackData.h"

void initLinkedStack(LinkedStatck *stack)
{
    stack->top = NULL;
    stack->length = 0;
}

int push(LinkedStatck *stack, ElementType element)
{
    // 创建新结点
    LinkedStatckNode *node = (LinkedStatckNode *)malloc(sizeof(LinkedStatckNode));
    node->data = element;
    // 指向上一个元素
    node->next = stack->top;
    stack->top = node;
    stack->length++;
    return TRUE;
}