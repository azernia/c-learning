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
    if(queue->rear == MAX_SIZE)
    {
        printf("the sequence queue is full\n");
        return FALSE;
    }
    queue->data[queue->rear] = element;
    queue->rear++;
    return TRUE;
}

int dequeue(SeqQueue *queue, ElementType *element)
{
    if(queue->top == 0 && queue->top == queue->rear)
    {
        printf("the sequence queue is empty\n");
        return FALSE;
    }
    *element = queue->data[queue->top];
    queue->top++;
    return TRUE;
}

void clear(SeqQueue *queue)
{
    while (queue->top < MAX_SIZE)
    {
        queue->top++;
    }
    init(queue);
}