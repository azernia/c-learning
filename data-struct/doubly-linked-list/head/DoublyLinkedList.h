#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedListData.h"

/**
 * 初始化双向链表
 * @param list 操作的链表
 * @param dataArray 数据
 * @param length 数组长度
 */
void initDoublyLinkedList(DoublyLinkedList *list, ElementType *dataArray, int length);

/**
 * 插入结点
 * @param list 操作的链表
 * @param element 元素
 * @param position 位置
 */
void insertDoublyLinkedList(DoublyLinkedList *list, ElementType element, int position);

/**
 * 通过位置删除双向链表结点
 * @param list 操作的链表
 * @param position 位置
 * @return ElementType  返回删除的元素
 */
ElementType deleteDoublyNodeByPosition(DoublyLinkedList *list, int position);

/**
 * 打印双向链表
 * @param list 需要打印的链表
 */
void printDoublyLinkedList(DoublyLinkedList *list);

#endif