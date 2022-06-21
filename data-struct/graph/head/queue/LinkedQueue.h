#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function:链队列的实现-尾进头出
 *  Description:
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/

#include <stdlib.h>
#include "../common/GraphModel.h"

/** 链队列的结点 */
typedef struct QueueNode{
    VerTex data;           //结点数据
    struct QueueNode * next;    //指向下个结点的指针
}QueueNode;

typedef struct{
    QueueNode * front;          //队头指针
    QueueNode * rear;           //队尾指针
    int length;                 //队列长度
}LinkedQueue;

/** 初始化链队列 */
void initLinkedQueue(LinkedQueue * linkedQueue);

/** 入队 */
void enqueue(LinkedQueue * linkedQueue, VerTex verTex);

/** 出队 */
void dequeue(LinkedQueue * linkedQueue, VerTex *verTex);

int isLinkedQueueEmpty(LinkedQueue * linkedQueue);






#endif // LINKEDQUEUE_H_INCLUDED
