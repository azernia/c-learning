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
void initList(SeqList *seqList, int *elemArray, int length);

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

#endif