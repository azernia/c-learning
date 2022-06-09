/**
 * Created by Rui on 2022/6/9.
 */

#ifndef BINARY_TREE_QUEUE_H
#define BINARY_TREE_QUEUE_H

#include "../LinkedBinaryTree/LinkedBinaryTree.h"

typedef struct LinkedQueueNode {
    BiNode *data;
    struct LinkedQueueNode *next;
} LinkedQueueNode;

// 有头结点
typedef struct LinkedQueue {
    LinkedQueueNode *front; // 队头指针
    LinkedQueueNode *rear;  // 队尾指针
} LinkedQueue;

void initLinkedQueue(LinkedQueue *queue);

void enqueue(LinkedQueue *queue, BiNode *treeNode);

BiNode * dequeue(LinkedQueue *queue);

int isLinkedQueueEmpty(LinkedQueue *queue);

#endif //BINARY_TREE_QUEUE_H
