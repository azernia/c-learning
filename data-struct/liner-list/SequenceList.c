#include<stdio.h>
#include<stdlib.h>

#define MAX_SZIE 10

typedef int ElementType;

typedef struct {
    ElementType data[MAX_SZIE];
    int length;
}SeqList;

/**
 * 初始化顺序表
 * 
 * @param seqList 需要初始化的顺序表
 * @param elemArray 初始化值
 * @param length 初始化长度
 */
void initList(SeqList *seqList, int *elemArray, int length);

/**
 * 根据下标向顺序表中添加数据
 * 
 * @param seqList 需要添加的顺序表
 * @param index 下标
 * @param element 添加的元素
 */
void insertElement(SeqList *seqList, int index, ElementType element);

/**
 * 输出顺序表
 * 
 * @param seqList 
 */
void printList(SeqList *seqList);

void printList(SeqList *seqList)
{
    for(int i = 0; i < seqList->length; i++)
    {
        printf("seqList[%d] = %d\n", i, seqList->data[i]);
    }
}

void insertElement(SeqList *seqList, int index, ElementType element)
{
    if(seqList->length + 1 >= MAX_SZIE)
    {
        printf("数组已满，插入元素失败\n");
        return;
    }
    if(index < 0 || index > MAX_SZIE - 1)
    {
        printf("只能在允许的范围内插入元素，[0, %d]\n", MAX_SZIE - 1);
    }
    if(index > seqList->length)
    {
        printf("下标越界");
    }
    // 无论在顺序表的什么位置插入数据元素，解决办法都是：找到要插入的位置，将后续数据元素整体向后移动一个位置，最后直接在腾出来的位置上插入数据元素。
    for(int i = seqList->length - 1; i >= index; i--)
    {
        seqList->data[i + 1] = seqList->data[i];
    }
    seqList->data[index] = element;
    seqList->length++;
}

void initList(SeqList *seqList, int *elemArray, int length)
{
    seqList->length = 0;
    if(length > MAX_SZIE)
    {
        printf("超出数组最大边界\n");
        return;
    }
    for(int i = 0; i < length - 1; i++)
    {
        insertElement(seqList, i, elemArray[i]);
    }
    printf("初始化成功\n");
}

int main()
{
    int array[] = {
        0,1,2,3,4,5,6,7,8,9
    };
    SeqList seqList;
    initList(&seqList, array, sizeof(array)/sizeof(array[0]));
    printList(&seqList);
    return 0;
}