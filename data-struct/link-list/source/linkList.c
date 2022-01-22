#include <stdio.h>
#include <stdlib.h>

#include "../head/linkList.h"

void initLinkList(LinkList *linkList, ElementType *dataArray, int length)
{
    linkList->length = 0;
    for(int i = 0; i < length; i++)
    {
        insertLinkList(linkList, i + 1, dataArray[i]);
    }
}

void insertLinkList(LinkList *linkList, ElementType data, int position)
{
    // 创建空结点并给数据域赋值
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    // 找到要插入的结点位置
    if(position == 1 && linkList->length == 0)
    {
        // 插入的为第一个元素
        linkList->next = node;
        linkList->length++;
        return;
    }
    else {
        node->next = linkList->next;
        linkList->next = node;
        linkList->length++;
        return;
    }
    // 设当前结点为第一个结点
    Node *currNode = linkList->next;
    for(int i = 1; currNode != NULL && i < position - 1; i++)
    {
        currNode = currNode->next;
    }
    // 将结点插入并对接前面的结点
    if(currNode != NULL)
    {
        // 对接右侧
        node->next = currNode->next;
        // 对接左侧
        currNode->next = node;
        linkList->length++;
    }
    free(node);
}

void printLinkList(LinkList *linkList)
{
    // 指向第一个元素
    Node *node = linkList->next;
    if(!node)
    {
        printf("The link list is empty\n");
        linkList->length = 0;
        return;
    }
    for(int i = 0; i < linkList->length; i++)
    {
        printf("%d\n", node->data);
        node = node->next;
    }
}

ElementType getElement(LinkList *linkList, int position)
{
    Node *node = linkList->next;
    for(int i = 1; node && i < position; i++)
    {
        node = node->next;
    }
    return node->data; 
}

ElementType delElement(LinkList *linkList, int position)
{
    Node *node = NULL;
    ElementType delElement = -1;
    if(position == 1)
    {
        node = linkList->next;
        if(node)
        {
            delElement = node->data;
        }
        linkList->next = node->next;
        // 释放内存 容易遗漏
        free(node);
        return delElement;
    }
    Node *preNode;
    node = linkList->next;
    for(int i = 1; node && i < position; i++)
    {
        preNode = node;
        node = node->next;
    }
    if(node)
    {
        delElement = node->data;
        preNode->next = node->next;
        free(node);
    }
    return delElement;
}