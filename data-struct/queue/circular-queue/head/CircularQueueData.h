#ifndef _CIRCULARQUEUEDATA_H_
#define _CIRCULARQUEUEDATA_H_

// 队列最大长度
#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0
// 队列状态
#define STATE_OK 1
#define STATE_FAIL -1

typedef int ElementType;
// 表示状态
typedef int State;

typedef struct CircularQueue
{
    ElementType data[MAX_SIZE];
    // 队头下标
    int front;
    // 队尾下标
    int rear;
    // 队列长度
    int length;
} CircularQueue;

#endif