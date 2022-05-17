#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_

#include "CircularQueueData.h"

/**
 * 初始化循环队列
 * @param queue 
 */
int init(CircularQueue *queue);

/**
 * 队列是否为空
 * @param queqe 
 * @return int 0-否 1-是
 */
State isEmpty(CircularQueue *queqe);

/**
 * 队列是否已满
 * @param queqe 
 * @return int 0-否 1-是
 */
State isFull(CircularQueue *queqe);

/**
 * 入队
 * @param queue 
 * @param element 
 */
State enqueue(CircularQueue *queue, ElementType element);

#endif