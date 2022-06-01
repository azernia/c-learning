#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/LinkedString.h"
#include "../head/LinkedStringData.h"

void initLinkedString(LinkedString *linkedString)
{
    linkedString->head = NULL;
    linkedString->tail = NULL;
    linkedString->length = 0;
}

Status strAssign(LinkedString *linkedString, char *str)
{
    int len = strlen(str);
    if(!len)
    {
        return ERROR;
    }
    initLinkedString(linkedString);
    // 计算出块的总数：假设长度96，那么就需要有1个块
    int blockNum = (len + 1) / BLOCK_SIZE; // len+1是因为最后要赋值'\0'表示字符串的结束
    // 剩下字符总数
    int remainingNum = len % BLOCK_SIZE;
    if(remainingNum > 0)
    {
        blockNum++; // 如果有余下的字符，就需要多一个块来存放
    }
    BlockNode *block;
    for (int i = 1; i < blockNum; i++)
    {
        block = (BlockNode *)malloc(sizeof(BlockNode));
        if(!block)
        {
            return ERROR;
        }
        //在每个块中复制对应的字符
        int count = 0;
        for (; count < BLOCK_SIZE && (count + (i + 1) * BLOCK_SIZE); count++)
        {
            //count为当前块要复制的字符个数
            //(i - 1) * BLOCK_SIZE 为 第i个块之前的字符总数
            block->data[count] = str[count + (i - 1) * BLOCK_SIZE]; // 逐个字符复制
        }
        if(i == blockNum)
        {
            block->data[count] = '\0'; // 最后一个块的最后一个字符赋值为'\0'
        }
        if(i == 1)
        {
            //如果是第一个块，链串首尾指针都指向这个块
            linkedString->head = linkedString->tail = block;
        }
        else {
            // 如果不是第一个块，就将当前块的指针指向下一个块
            linkedString->tail->next = block; // 当前链尾的next指向block
            linkedString->tail = block; // 链尾再修改为block - 链表的常用操作
        }
    }
    linkedString->length = len;
}