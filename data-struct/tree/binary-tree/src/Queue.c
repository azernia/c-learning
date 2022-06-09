/**
 * Created by Rui on 2022/6/9.
 */

#include "../head/Queue/Queue.h"

void initLinkedQueue(LinkedQueue *queue) {
    queue->front = (LinkedQueueNode *)malloc(sizeof (LinkedQueueNode));
    queue->front->next = NULL;
    queue->rear = queue->front;
}

void enqueue(LinkedQueue *queue, BiNode *treeNode) {
    LinkedQueueNode *tempNode = (LinkedQueueNode *) malloc(sizeof (LinkedQueueNode));
    tempNode->data = treeNode;
    tempNode->next = NULL;
    queue->rear->next = tempNode;
    queue->rear = tempNode;
}

BiNode *dequeue(LinkedQueue *queue) {
    BiNode *returnData = NULL;
    if (queue->front == queue->rear) {
        return returnData;
    }
    LinkedQueueNode *queueNode = queue->front->next;
    returnData = queueNode->data;
    queue->front->next = queueNode->next;
    if (queue->rear == queueNode) {
        queue->rear = queue->front;
    }
    free(queueNode);
    return returnData;
}

int isLinkedQueueEmpty(LinkedQueue *queue) {
    if (queue->front == queue->rear) {
        return 1;
    }
    return 0;
}


