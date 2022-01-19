#ifndef __SEQUENCELISTDATA_H_
#define __SEQUENCELISTDATA_H_

#define MAX_SZIE 10

typedef int ElementType;


typedef struct {
    ElementType data[MAX_SZIE];
    int length;
}SeqList;


#endif