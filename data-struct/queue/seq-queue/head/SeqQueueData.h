#ifndef _SEQQUEUEDATA_H_
#define _SEQQUEUEDATA_H_

// 队列最大长度
#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

typedef int ElementType;

typedef struct SeqQueue
{
    ElementType data[MAX_SIZE];
    // 队头下标
    int top;
    // 队尾下标
    int rear;
} SeqQueue;


#endif