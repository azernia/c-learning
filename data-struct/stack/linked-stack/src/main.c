#include <stdio.h>
#include <stdlib.h>
#include "../head/LinkedStack.h"
#include "../head/LinkedStackData.h"
#include "LinkedStack.c"

int main()
{
    LinkedStatck *stack = (LinkedStatck *)malloc(sizeof(LinkedStatck));
    initLinkedStack(stack);
    push(stack, 1);
    ElementType element;
    pop(stack, &element);
    printf("pop result = %d\n", element);
    free(stack);
    return 0;
}