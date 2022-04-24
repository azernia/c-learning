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

/**
 * 获取静态链表的长度
 * @param list 操作的链表
 */
int getStaticLinedListLength(StaticLinkedList list);

/**
 * 删除指定位置的元素
 * @param list 操作的链表
 * @param position 指定的位置
 * @return int 0-失败 1-成功
 */
int deleteElementByPosition(StaticLinkedList list, int position);

/**
 *  释放原始数组中指定下标的空间
 * @param list 操作的链表
 * @param index 下标
 */
void freeStaticLinedList(StaticLinkedList list, int index);

#endif
