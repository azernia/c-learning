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

int pop(LinkedStatck *stack, ElementType *element)
{
    if(stack->top == NULL)
    {
        printf("the linked stack is empty\n");
        return FALSE;
    }
    *element = stack->top->data;
    // 暂存栈顶指针
    LinkedStatckNode *tempNode = stack->top;
    // 指向下一个
    stack->top = stack->top->next;
    free(tempNode);
    stack->length--;
    return TRUE;
}

void clear(LinkedStatck *stack)
{
    LinkedStatckNode *tempNode = NULL;
    while (stack->top)
    {
        tempNode = stack->top;
        stack->top = stack->top->next;
        free(tempNode);
        stack->length--;
    }
    
}