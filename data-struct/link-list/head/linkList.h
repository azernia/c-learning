#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "linkListData.h"

/**
 * 初List
 * @param linkList 需要初始化的链表
 * @param dataArray 初始化的值
 * @param length 初始化的长度
*/
void initLinkList(LinkList *linkList, ElementType *dataArray, int length);

/**
 * 向链表中插值
 * @param linkList 需要插入的链表
 * @param data 插入的值
 * @param position 插入的位置 从 1 开始 第 0 个位置为头结点(在有头结点的情况下)
*/
void insertLinkList(LinkList *linkList, ElementType data, int position);

/**
 * 输出链表
*/
void printLinkList(LinkList *linkList);

/**
 * 获取链表中的元素
 * @param linkList 需要获取元素的链表
 * @param position 获取第几个元素
 * @return ElementType
*/
ElementType getElement(LinkList *linkList, int position);

/**
 * 删除链表中的元素
 * @param linkList 需要删除元素的链表
 * @param position 删除第几个元素
 * @return ElementType
*/
ElementType delElement(LinkList *linkList, int position);

/**
 * 清空链表
 * @param linkList 需要清空的链表
*/
void clearLinkList(LinkList *linkList);

#endif