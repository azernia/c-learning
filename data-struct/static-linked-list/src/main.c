#include <stdio.h>
#include <stdlib.h>

#include "../head/StaticLinkedList.h"
#include "../head/StaticLinkedListData.h"
#include "StaticLinkedList.c"

int main()
{
    StaticLinkedList list;
    initStaticLinkedList(list);
    printStaticLinekdList(list);
    printf("=======================\n");
    ElementType element = 1;
    insertElementByPoistion(list, 1, element);
    printStaticLinekdList(list);
    return 0;
}