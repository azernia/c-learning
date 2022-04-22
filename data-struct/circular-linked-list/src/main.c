#include <stdio.h>
#include <stdlib.h>
#include "../head/CircularLinkedList.h"
#include "../head/CircularLinkedListData.h"
#include "CircularLinkedList.c"

int main ()
{
    int dataArray[] = {
        1, 2, 3, 4, 5
    };
    CircularLinkedList *list = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
    list->length = 0;
    list->next = NULL;
    initCircularLinkedList(list, dataArray, 5);
    printCircularLinkedList(list);
    printf("====================\n");
    ElementType delElem1 = deleteCircularLinkedListByPosition(list, 1);
    printf("delete element = %d\n", delElem1);
    printCircularLinkedList(list);
    printf("====================\n");
    ElementType delElem2 = deleteCircularLinkedListByPosition(list, 2);
    printf("delete element = %d\n", delElem2);
    printCircularLinkedList(list);
    printf("====================\n");
    CircularNode *node = getCircularNodeByElement(list, 4);
    printCircularLinkedListByNode(list, node);
    return 0;
}