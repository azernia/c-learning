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
    ElementType element1 = 1;
    ElementType element2 = 2;
    ElementType element3 = 3;
    insertElementByPoistion(list, 1, element1);
    insertElementByPoistion(list, 2, element2);
    insertElementByPoistion(list, 3, element3);
    printStaticLinekdList(list);
    printf("=======================\n");
    deleteElementByPosition(list, 1);
    printStaticLinekdList(list);
    return 0;
}