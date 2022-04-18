#ifndef _CIRCULARLINKEDLIST_H_
#define _CIRCULARLINKEDLIST_H_

#include "CircularLinkedListData.h"

/**
 * 初始化循环列表
 * @param list 需要初始化的列表
 * @param dataArray 初始化数据]
 * @param length 长度
 */
void initCircularLinkedList(CircularLinkedList *list, ElementType *dataArray, int length);

/**
 * 在循环链表的指定位置插入元素
 * @param list 操作的链表
 * @param position 位置
 * @param element 元素
 */
void insertCircularLinkedList(CircularLinkedList *list, int position, ElementType element);

/**
 * 通过位置删除循环链表的元素
 * @param list 需要操作的链表
 * @param position 位置
 * @return ElementType 删除的元素
 */
ElementType deleteCircularLinkedListByPosition(CircularLinkedList *list, int position);

/**
 * 根据元素内容返回节点指针
 * @param list 操作的节点
 * @param element 元素
 * @return CircularNode* 节点指针
 */
CircularNode * getCircularNodeByElement(CircularLinkedList *list, ElementType element);

/**
 * 打印循环链表
 * @param list 需要打印的链表
 */
void printCircularLinkedList(CircularLinkedList *list);

/**
 * 根据节点打印链表
 * @param node 传入的节点
 */
void printCircularLinkedListByNode(CircularLinkedList *list ,CircularNode* node);

#endif