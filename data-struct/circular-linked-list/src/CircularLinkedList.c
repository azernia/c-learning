#include <stdio.h>
#include <stdlib.h>

#include "../head/CircularLinkedList.h"
#include "../head/CircularLinkedListData.h"

void initCircularLinkedList(CircularLinkedList *list, ElementType *dataArray, int length)
{
    for (int i = 0; i < length; i++)
    {
        insertCircularLinkedList(list, i+1, dataArray[i]);
    }
    
}

void insertCircularLinkedList(CircularLinkedList *list, int position, ElementType element)
{
    // 创建空节点
    CircularNode *node = (CircularNode *)malloc(sizeof(CircularNode));
    node->data = element;
    node->next = NULL;
    // 插入位置为第一个
    if(position == 1)
    {
        if(list->length == 0)
        {
            node->next = node;
        }
        else
        {
            // 长度不为0
            CircularNode *lastNode = list->next;
            for(int i = 1; i < list->length; i++)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = node;
        }
        list->next = node;
        list->length++;
        return;
    }
    // 插入位置不为第一个
    CircularNode *currNode = list->next;
    for(int i = 1; currNode && i < position - 1; i++)
    {
        currNode = currNode->next; 
    }
    if(currNode)
    {
        node->next = currNode->next;
        currNode->next = node;
        list->length++;
        if(position == list->length)
        {
            node->next = list->next;
        }
    }
}

ElementType deleteCircularLinkedListByPosition(CircularLinkedList *list, int position)
{
    // 获取第一个元素
    if(list->length == 0 || !list->next)
    {
        printf("This circular linked list is empty\n");
        return FALSE;
    }
    CircularNode *node = list->next;
    ElementType deleteElem = -1;
    // 删除第一个元素
    if(position == 1)
    {
        deleteElem = node->data;
        CircularNode *lastNode = list->next;
        for (int i = 1; i < list->length; i++)
        {
            lastNode = lastNode->next;
        }
        printf("last node data = %d\n", lastNode->data);
        list->next = node->next;
        lastNode->next = list->next;
        free(node);
        list->length--;
        return deleteElem;
    }
    // 非第一个元素
    // 找到该位置的前置元素
    CircularNode *preNode;
    for (int i = 1; node && i < position; i++)
    {
        preNode = node;
        node = node->next;
    }
    if(node)
    {
        deleteElem = node->data;
        preNode->next = node->next;
        free(node);
        list->length--;
    }
    return deleteElem;
}
CircularNode* getCircularNodeByElement(CircularLinkedList *list, ElementType element)
{
    CircularNode *node = list->next;
    do {
        if(element == node->data)
        {
            return node;
        }
        node = node->next;
    }while (node != list->next);
    return NULL;
}

void printCircularLinkedList(CircularLinkedList *list)
{
    if(list->length == 0 || !list->next)
    {
        printf("This circular linked list is empty\n");
        return;
    }
    // 获取第一个元素
    CircularNode *node = list->next;
    for(int i = 0; i < list->length; i++)
    {
        printf("===========>%d\n", node->data);
        node = node->next;
    }
}

void printCircularLinkedListByNode(CircularLinkedList *list ,CircularNode* node)
{
    if(!node)
    {
        return;
    }
    if(list->length == 0 || !list->next)
    {
        printf("This circular linked list is empty\n");
        return;
    }
    // 记录初始节点指针
    CircularNode *originalNode = node;
    do
    {
        printf("===========>%d\n", node->data);
        node = node->next;
    } while (node != originalNode);
    
}

