#include <stdio.h>
#include <stdlib.h>
#include "../head/StaticLinkedList.h"
#include "../head/StaticLinkedListData.h"

void initStaticLinkedList(StaticLinkedList list)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list[i].next = i + 1;
    }
    // 将最后一个结点置空
    list[MAX_SIZE - 1].next = 0;
    // 将备用链表的尾结点置空
    list[MAX_SIZE - 2].next = 0;
    
}

void printStaticLinekdList(StaticLinkedList list)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("i=%d\tnext=%d\n", i, list[i].next);
    }
    
}