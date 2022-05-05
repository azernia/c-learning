#include <stdio.h>
#include <stdlib.h>
#include "../head/CircularQueue.h"
#include "../head/CircularQueueData.h"

int init(CircularQueue *queue)
{
    queue->front = 0;
    queue->rear = 0;
    return TRUE;
}

int isEmpty(CircularQueue *queqe)
{
    if(queqe->rear == queqe->front == 0)
    {
        return TRUE;
    }
    return FALSE;
}

int isFull(CircularQueue *queqe)
{
    if ((queqe->rear + 1) % MAX_SIZE == queqe->front)
    {
        return TRUE;
    }
    return FALSE;
}

void enqueue(CircularQueue *queue, ElementType element)
{

}