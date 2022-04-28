#ifndef _LINKEDSTACKDATA_H_
#define _LINKEDSTACKDATA_H_

#define TRUE 1
#define FALSE 0

typedef int ElementType;

typedef struct LinkedStatckNode
{
    ElementType data;
    struct LinkedStatckNode *next;
} LinkedStatckNode;

typedef struct LinkedStatck
{
    // 栈顶指针
    LinkedStatckNode *top;
    // 栈中元素个数
    int length;
} LinkedStatck;



#endif