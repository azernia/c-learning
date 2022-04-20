#ifndef _DOUBLYLINKEDLISTDATA_H_
#define _DOUBLYLINKEDLISTDATA_H_

typedef int ElementType;

// 双向链表结点
typedef struct DoublyNode
{
  struct DoublyNode *pre;
  ElementType data;
  struct DoublyNode *next;      
} DoublyNode;

// 双向链表
typedef struct DoublyLinkedList
{
    int length;
    DoublyNode *next;
} DoublyLinkedList;



#endif