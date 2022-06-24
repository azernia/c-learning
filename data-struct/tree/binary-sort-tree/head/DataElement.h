/**
 * 定义数据元素
 * Created by Rui on 2022/6/23.
 */

#ifndef SEQUENTIAL_SEARCH_DATAELEMENT_H
#define SEQUENTIAL_SEARCH_DATAELEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 255
#define MAX_INFO_SIZE 50
#define TRUE 1
#define FALSE 0

/**
 * 数据类型
 */
typedef struct ElementType {
    int key;    // 查询关键字
    char *value;    // 数据域
} ElementType;

#endif //SEQUENTIAL_SEARCH_DATAELEMENT_H
