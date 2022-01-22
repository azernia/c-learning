#ifndef _LINKLISTDATA_H_
#define _LINKLISTDATA_H_

/**
 * 单链表
 * 每个结点都有后继结点
 * 链表的优点
 *  存储空间利用率搞笑
*/

typedef int ElementType;

// 结点
typedef struct Node
{
    // 数据域
    ElementType data;
    // 指针域 指向下个结点
    struct Node *next;
} Node;

// 链表的定义
typedef struct LinkList
{
    // 头指针 如果有头结点就指向头结点否则指向第一个结点
    Node *next;
    // 链表的长度 初始值为 0
    int length;
} LinkList;

#endif