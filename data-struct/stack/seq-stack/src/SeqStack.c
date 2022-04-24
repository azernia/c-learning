#include <stdio.h>
#include <stdlib.h>
#include "../head/SeqStack.h"
#include "../head/SeqStackData.h"

void initSeqStack(SeqStack *stack)
{
    // 栈顶指向-1
    stack->top = -1;
    stack->length = 0;
}

int push(SeqStack *stack, ElementType element)
{
    if(stack->top == MAX_SIZE - 1)
    {
        printf("The stack is full!\n");
        return FALSE;
    }
    // 栈顶指正加一
    stack->top++;
    // 压入元素
    stack->elements[stack->top] = element;
    stack->length++;
    return TRUE;
}

int pop(SeqStack *stack, ElementType *element)
{
    if(stack->top == -1)
    {
        printf("empty stack\n");
        return FALSE;
    }
    *element = stack->elements[stack->top];
    stack->top--;
    stack->length--;
    return TRUE;
}

void getTopElement(SeqStack *stack, ElementType *element)
{
    if(stack->top == -1)
    {
        printf("empty stack\n");
        element = NULL;
    }
    *element = stack->elements[stack->top];
}

void clearStack(SeqStack *stack)
{
    stack->top = -1;
    stack->length = 0;
}

int isEmpty(SeqStack *stack)
{
    if(stack->top == -1)
    {
        return TRUE;
    }
    return FALSE;
}