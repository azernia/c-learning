#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.c"
#include "../head/CircularQueueData.h"

int main()
{
    CircularQueue queue;
    init(&queue);
    enqueue(&queue, 3);
    enqueue(&queue, 2);
    enqueue(&queue, 1);
    for (int i = 0; i < queue.length; i++)
    {
        printf("%d\n", queue.data[i]);
    }
    ElementType *element;
    dequeue(&queue, element);
    printf("%d\n", *element);
    return 0;
}