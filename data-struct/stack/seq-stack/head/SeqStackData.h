#ifndef _SEQSTACKDATA_H_
#define _SEQSTACKDATA_H_

/**
 * 顺序栈
 */
#define MAX_SIZE 255
#define TRUE 1
#define FALSE 0

typedef int ElementType;

typedef struct SeqStack
{
    ElementType elements[MAX_SIZE];
    // 栈顶(元素下标) -1 标识栈为空
    int top;
    // 当前栈的元素个数
    int length;
} SeqStack;



#endif