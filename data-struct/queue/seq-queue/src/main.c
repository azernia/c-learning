#include <stdio.h>
#include <stdlib.h>
#include "../head/SeqQueueData.h"
#include "SeqQueue.c"

int main()
{
    SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
    init(queue);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        enqueue(queue, i+1);
    }
    enqueue(queue, 11);
    ElementType dequeueElem = -1;
    dequeue(queue, &dequeueElem);
    printf("dequeue element is %d\n", dequeueElem);
    free(queue);
    return 0;
}