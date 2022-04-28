#include <stdio.h>
#include <stdlib.h>
#include "../head/LinkedStack.h"
#include "../head/LinkedStackData.h"

void initLinkedStack(LinkedStatck *stack)
{
    stack->top = NULL;
    stack->length = 0;
}