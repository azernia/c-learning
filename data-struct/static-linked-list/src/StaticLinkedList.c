#include <stdio.h>
#include <stdlib.h>
#include "../head/StaticLinkedList.h"
#include "../head/StaticLinkedListData.h"

void initStaticLinkedList(StaticLinkedList list)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list[i].data = 0;
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
        printf("i=%d\tdata=%d\tnext=%d\n", i, list[i].data, list[i].next);
    }
}

int insertElementByPoistion(StaticLinkedList list, int position, ElementType element)
{
    // 最后一个元素的 next 即第一个元素的下标
    int cursor = MAX_SIZE - 1;
    // 判断 cursor 的范围是否合法
    // 分配内存
    int newIndex = mallocStaticLinedList(list);
    if(newIndex)
    {
        list[newIndex].data = element;
        // 找到 newIndex 的前缀结点
        for (int i = 0; i < position - 1; i++)
        {
            cursor = list[cursor].next;
        }
        list[newIndex].next = list[cursor].next;
        list[cursor].next = newIndex;
        return TRUE;
    }
    return FALSE;
}

int mallocStaticLinedList(StaticLinkedList list)
{
    // 第一个空闲结点的下标（备用链表下标）
    int cursor = list[0].next;
    if(cursor)
    {
        list[0].next = list[cursor].next;
    }
    return cursor;
}