#ifndef _STATICLINKEDLISTDATA_H_
#define _STATICLINKEDLISTDATA_H_

#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

typedef int ElementType;

typedef struct
{
    ElementType data;
    int next;   // 为0无指向
} StaticLinkedList[MAX_SIZE];


#endif