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