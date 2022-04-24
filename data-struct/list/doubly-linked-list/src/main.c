#include <stdio.h>
#include <stdlib.h>
#include "../head/DoublyLinkedList.h"
#include "DoublyLinkedList.c"

int main()
{
    int dataArray[] = {
        1, 2, 3
    };
    DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    initDoublyLinkedList(list, dataArray, 3);
    printDoublyLinkedList(list);
    printf("=========================\n");
    ElementType result =  deleteDoublyNodeByPosition(list, 1);
    printf("delete result = %d\n", result);
    printDoublyLinkedList(list);
    printf("=========================\n");
    DoublyNode * node = getDoublyNodeByPosition(list, 2);
    printf("get data is %d\n", node->data);
    printf("=========================\n");
    DoublyNode * preNode = getPreNodeByNode(node);
    printf("get pre node data is %d\n", preNode->data);
    free(list);
    return 0;
}