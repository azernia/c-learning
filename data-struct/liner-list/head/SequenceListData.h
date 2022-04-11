#ifndef __SEQUENCELISTDATA_H_
#define __SEQUENCELISTDATA_H_

#define MAX_SZIE 10
#define TRUE 1
#define FALSE 0

typedef int ElementType;

/**
 * 顺序表元素结构
 * 
 */
typedef struct {
    ElementType data[MAX_SZIE];
    int length;
}SeqList;


#endif