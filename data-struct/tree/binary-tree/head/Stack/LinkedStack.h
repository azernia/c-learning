/**
 * Created by Rui on 2022/6/9.
 */

#ifndef BINARY_TREE_LINKEDSTACK_H
#define BINARY_TREE_LINKEDSTACK_H

#include <stdio.h>
#include "../LinkedBinaryTree/LinkedBinaryTree.h"

typedef struct LinkedStackNode {
    BiNode *data;
    struct LinkedStackNode *next;   // 上一个结点的指针
} LinkedStackNode;

typedef struct LinkedStack {
    LinkedStackNode *top;
    int length
} LinkedStack;

void initLinkedStack(LinkedStack *stack);

int push(LinkedStack *stack, BiNode *treeNode);

int pop(LinkedStack *stack, BiNode **pBiNode);

void clear(LinkedStack *stack);

void destroy(LinkedStack *stack);

int isEmpty(LinkedStack *stack);

#endif //BINARY_TREE_LINKEDSTACK_H
