#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_

#include "SeqQueueData.h"

/**
 * 初始化队列
 * @param queue 操作的队列
 */
void init(SeqQueue *queue);

/**
 * 入队
 * @param queue 操作的队列
 * @param element 入队的元素
 * @return int 0-失败 1-成功
 */
int enqueue(SeqQueue *queue, ElementType element);

/**
 * 出队 先进先出
 * @param queue 操作的队列
 * @param element 出队的元素
 * @return int 0-失败 1-成功
 */
int dequeue(SeqQueue *queue, ElementType *element);

/**
 * 清空队列
 * @param queue 操作的队列
 */
void clear(SeqQueue *queue);

#endif