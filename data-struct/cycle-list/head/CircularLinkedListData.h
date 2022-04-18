#ifndef _CIRCULARLINKEDLISTDATA_H_
#define _CIRCULARLINKEDLISTDATA_H_

#define TRUE 1
#define FALSE 0

typedef int ElementType;

typedef struct CircularNode {
    // 数据域
    ElementType data;
    // 指针域
    struct CircularNode *next;
} CircularNode;

// 定义头结点
typedef struct CircularLinkedList {
    int length;
    // 指向第一个节点的指针
    CircularNode *next;

} CircularLinkedList;

#endif