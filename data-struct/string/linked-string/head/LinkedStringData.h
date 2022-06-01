#ifndef _LINKEDSTRINGDATA_H_
#define _LINKEDSTRINGDATA_H_

#define BLOCK_SIZE 100

typedef struct BlockNode
{
    char data[BLOCK_SIZE];  // 存储数据的数组
    struct BlockNode *next; // 指向下一个块的指针
} BlockNode;

typedef struct LinkedString
{
    BlockNode *head; // 指向头结点的指针
    BlockNode *tail; // 指向尾结点的指针
    int length;      // 字符串的长度
} LinkedString;


#endif