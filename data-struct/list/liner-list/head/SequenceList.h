#ifndef _SEQUENCELIST_H_
#define _SEQUENCELIST_H_

#include "SequenceListData.h"

/**
 * 初始化顺序表
 * 
 * @param seqList 需要初始化的顺序表
 * @param elemArray 初始化值
 * @param length 初始化长度
 */
extern void initList(SeqList *seqList, int *elemArray, int length);

/**
 * 根据下标向顺序表中添加数据
 * 
 * @param seqList 需要添加的顺序表
 * @param index 下标
 * @param element 添加的元素
 */
void insertElement(SeqList *seqList, int index, ElementType element);

/**
 * 输出顺序表
 * 
 * @param seqList 
 */
void printList(SeqList *seqList);

/**
 * 根据下标删除元素
 * 
 * @param seqList 删除的顺序表
 * @param index 删除元素的下标
 * @return 返回删除的元素 失败返回 NULL
 */
ElementType* deleteElement(SeqList *seqList, int index);

/**
 * 根据下标获取顺序表中的元素
 * 
 * @param seqList 
 * @param index 
 * @return ElementType* 
 */
ElementType* getElement(SeqList *seqList, int index);

/**
 * 判断元素是否存在
 * 
 * @param seqList 
 * @param element 
 * @return int 存在返回下标 不存在返回 -1
 */
int existElement(SeqList *seqList, ElementType element);

/**
 * 获取顺序表的长度
 * 
 * @param seqList 
 * @return int 返回顺序表单的长度
 */
int getLength(SeqList *seqList);

/**
 * 判断顺序表是否为空
 * 
 * @param seqList 
 * @return int 空返回 TRUE 否则返回 FALSE
 */
int isEmpty(SeqList *seqList);

/**
 * 清空顺序表
 * 
 * @param seqList 
 * @return int 成功返回 TRUE 否则返回 FALSE
 */
int clearList(SeqList *seqList);

#endif