#include <stdio.h>
#include <stdlib.h>
#include "../head/DoublyLinkedList.h"
#include "../head/DoublyLinkedListData.h"

void initDoublyLinkedList(DoublyLinkedList *list, ElementType *dataArray, int length)
{
    list->length = 0;
    list->next = NULL;
    for (int i = 0; i < length; i++)
    {
        insertDoublyLinkedList(list, dataArray[i], i+1);
    }
    
}

void insertDoublyLinkedList(DoublyLinkedList *list, ElementType element, int position)
{
    DoublyNode *node = (DoublyNode *)malloc(sizeof(DoublyNode));
    node->data = element;
    node->pre = NULL;
    node->next = NULL;
    // 插入第一个结点时
    if(position == 1)
    {
        if(list->length == 0)
        {
            list->next = node;
            list->length++;
            return;
        }
        node->next = list->next;
        list->next = node;
        node->next->pre = node;
        list->length++;
        return;
    }
    // 非第一个结点
    DoublyNode *currNode = list->next; // 插入位置前一个结点
    for (int i = 1; currNode && i < position - 1; i++)
    {
        currNode = currNode->next;
    }
    if(currNode)
    {
        node->pre = currNode;
        // 当前节点有后继节点时
        if(currNode->next)
        {
            currNode->next->pre = node;
        }
        node->next = currNode->next;
        currNode->next = node;
        list->length++;
    }
    // free(node);
}

ElementType deleteDoublyNodeByPosition(DoublyLinkedList *list, int position)
{
    ElementType element;
    DoublyNode *node = list->next;
    if(!node || list->length == 0)
    {
        printf("the doubly linked list is empty\n");
        list->length = 0;
        return 0;
    }
    if(position == 1)
    {
        if(node->next)
        {
            element = node->data;
            node->next->pre = NULL;
            list->next = node->next;
            list->length--;
            free(node);
            return element;
        }
        element = node->data;
        list->next = NULL;
        list->length--;
        free(node);
        return element;
    }
    // 不是第一个元素
    for (int i = 1; node && i < position; i++)
    {
        node = node->next;
    }
    // 删除最后一个元素
    if(position == list->length)
    {
        element = node->data;
        node->pre->next = NULL;
        list->length--;
        free(node);
        return element;
    }
    // 非最后一个元素
    element = node->data;
    node->pre->next = node->next;
    node->next->pre = node->pre;
    free(node);
    return element;
}

void printDoublyLinkedList(DoublyLinkedList *list)
{
    DoublyNode *node = list->next;
    if(!node || list->length == 0)
    {
        printf("the doubly linked list is empty\n");
        list->length = 0;
        return;
    }
    for (int i = 0; i < list->length; i++)
    {
        printf("====================>%d\n", node->data);
        node = node->next;
    }
    
}