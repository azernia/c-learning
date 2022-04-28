#include <stdio.h>
#include <stdlib.h>
#include "../head/SeqQueue.h"
#include "../head/SeqQueueData.h"

void init(SeqQueue *queue)
{
    queue->top = 0;
    queue->rear = queue->top;
}

int enqueue(SeqQueue *queue, ElementType element)
{
    queue->data[queue->rear] = element;
    queue->rear++;
    return TRUE;
}