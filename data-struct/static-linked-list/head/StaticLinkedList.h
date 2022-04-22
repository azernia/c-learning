#ifndef _STATICLINKEDLIST_H_
#define _STATICLINKEDLIST_H_

#include "StaticLinkedListData.h"

/**
 * 初始化静态链表
 * @param list 操作的链表
 */
void initStaticLinkedList(StaticLinkedList list);

/**
 * 
 */
void insertElementByPoistion(StaticLinkedList list, int position);

/**
 * 打印静态链表
 * @param list 操作的链表 
 */
void printStaticLinekdList(StaticLinkedList list);

#endif
