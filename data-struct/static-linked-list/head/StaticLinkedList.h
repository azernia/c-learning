#ifndef _STATICLINKEDLIST_H_
#define _STATICLINKEDLIST_H_

#include "StaticLinkedListData.h"

/**
 * 初始化静态链表
 * @param list 操作的链表
 */
void initStaticLinkedList(StaticLinkedList list);

/**
 * 向静态链表指定位置插入元素
 * @param list 操作的链表
 * @param position 插入的位置
 * @param element 插入的元素
 * @return int 0-失败 1-成功
 */
int insertElementByPoistion(StaticLinkedList list, int position, ElementType element);

/**
 * 分配静态链表的内存空间
 * @param list 操作的链表
 * @return int 0-失败
 */
int mallocStaticLinedList(StaticLinkedList list);

/**
 * 打印静态链表
 * @param list 操作的链表 
 */
void printStaticLinekdList(StaticLinkedList list);

#endif
