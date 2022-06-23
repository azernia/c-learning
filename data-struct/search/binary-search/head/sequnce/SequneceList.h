/**
 * Created by Rui on 2022/6/23.
 */

#ifndef SEQUENTIAL_SEARCH_SEQUNECELIST_H
#define SEQUENTIAL_SEARCH_SEQUNECELIST_H

#include "../common/DataElement.h"

/**
 * 定义顺序表
 */
 typedef struct SequenceList {
     ElementType *data; // 数据表中数据元素集合
     int length;    // 顺序表中的元素个数
 } SequenceList;

/**
 * 初始化顺序表
 * @param list
 */
void init(SequenceList *list);

/**
 * 打印
 * @param list
 */
void printSeqList(SequenceList list);

/**
 * 顺序表二分查找
 * @param list
 * @param searchKey
 * @return
 */
int sequenceBinarySearch(SequenceList list, int searchKey);

/**
 * 测试
 */
void test();

#endif //SEQUENTIAL_SEARCH_SEQUNECELIST_H
