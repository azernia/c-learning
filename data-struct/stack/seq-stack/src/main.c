#include <stdio.h>
#include <stdlib.h>
#include "../head/SeqStack.h"
#include "../head/SeqStackData.h"
#include "SeqStack.c"

int main()
{
    ElementType dataArray[] = {
        1, 2, 3, 4
    };
    SeqStack *stack = (SeqStack *)malloc(sizeof(SeqStack));
    ElementType *element = (ElementType *)malloc(sizeof(ElementType));
    for (int i = 0; i < 4; i++)
    {
        printf("push element = %d\n", dataArray[i]);
        push(stack, dataArray[i]);
    }
    printf("finished\n");
    for (int i = 0; i < 4; i++)
    {
        pop(stack, element);
        printf("pop element = %d\n", *element);
    }
    printf("finished\n");
    free(stack);
    return 0;
}