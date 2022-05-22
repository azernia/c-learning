#include <stdio.h>
#include <stdlib.h>
#include "../head/CircularQueue.h"
#include "../head/CircularQueueData.h"

int init(CircularQueue *queue)
{
    // 分配空间
    if(queue == NULL)
    {
        queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    }
    queue->front = 0;
    queue->rear = 0;
    queue->length = 0;
    return TRUE;
}

int isEmpty(CircularQueue *queqe)
{
    // 队尾指针与队头指针相同
    return queqe->rear == queqe->front ? TRUE : FALSE;
}

int isFull(CircularQueue *queqe)
{
    // 确保下标取值范围 [0, MAX_SIZE]
    if ((queqe->rear + 1) % MAX_SIZE == queqe->front)
    {
        return TRUE;
    }
    return FALSE;
}

State enqueue(CircularQueue *queue, ElementType element)
{
    if(isFull(queue))
    {
        return STATE_FAIL;
    }
    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->length++;
    return STATE_OK;
}

State dequeue(CircularQueue *queue, ElementType *element)
{
    if(isFull(queue))
    {
        return STATE_FAIL;
    }
    *element = queue->data[queue->front];
    // 队头队尾都可循环
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->length--;
    return STATE_OK;
}