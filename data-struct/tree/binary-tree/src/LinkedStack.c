/**
 * Created by Rui on 2022/6/9.
 */
#include "../head/Stack/LinkedStack.h"

void initLinkedStack(LinkedStack *stack) {
    stack->top = NULL;
    stack->length = 0;
}

int push(LinkedStack *stack, BiNode *treeNode) {
    LinkedStackNode *tempNode = (LinkedStackNode *) malloc(sizeof(LinkedStackNode));
    tempNode->data = treeNode;
    tempNode->next = stack->top;
    stack->top = tempNode;
    stack->length++;
    return 1;
}

int pop(LinkedStack *stack, BiNode **pBiNode) {
    LinkedStackNode *tempNode;
    if (stack->top == NULL || stack->length == 0) {
        return 0;
    }
    // 返回数据域
    *pBiNode = stack->top->data;
    tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);
    tempNode = NULL;
    stack->length--;
    return 1;
}

void clear(LinkedStack *stack) {
    LinkedStackNode *tempNode;
    while (stack->top) {
        tempNode = stack->top;
        stack->top = stack->top->next;
        free(tempNode);
        stack->length--;
    }
}

void destroy(LinkedStack *stack) {
    clear(stack);
    free(stack);
    stack = NULL;
}

int isEmpty(LinkedStack *stack) {
    if (stack->top == NULL || stack->length == 0) {
        return 1;
    }
    return 0;
}
