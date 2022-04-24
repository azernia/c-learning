#include <stdio.h>
#include <stdlib.h>
#include "../head/SequenceList.h"
#include "../head/SequenceListData.h"

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

ElementType* deleteElement(SeqList *seqList, int index)
{
    // 后一个赋给前一个
    if(index < 0 || index > MAX_SZIE - 1)
    {
        printf("下标越界，无法删除指定下标的元素");
        return NULL;
    }
    // 找到要删除的元素，并保存以返回，保存的是元素的值而不是元素的指针
    ElementType *p_delelteElem = (ElementType *)malloc(sizeof(ElementType));
    // 单独定义并调用查找函数，返回要删除元素的指针所指向元素的值
    *p_delelteElem = *getElement(seqList, index);
    // 从指定位置删除
    for(int i = index; i < seqList->length - 1; i++)
    {
        seqList->data[i] = seqList->data[i + 1];
    }
    seqList->length--;
    printf("删除成功\n");
    return p_delelteElem;   // 记得释放内存
}

ElementType* getElement(SeqList *seqList, int index)
{
    if(index < 0 || index > MAX_SZIE - 1)
    {
        printf("下标越界，无法找到指定下标的元素");
        return NULL;
    }
    ElementType *element = NULL;
    element = &seqList->data[index];
    return element;
}

int existElement(SeqList *seqList, ElementType element)
{
    ElementType *findElem = NULL;
    for(int i = 0; i < seqList->length; i++)
    {
        findElem = getElement(seqList, i);
        if(*findElem == element)
        {
            return i;
        }
    }
    return -1;
}

int getLength(SeqList *seqList)
{
    if(seqList == NULL)
    {
        return 0;
    }
    return seqList->length;
}

int isEmpty(SeqList *seqList)
{
    return getLength(seqList) == 0 ? TRUE : FALSE;
}

int clearList(SeqList *seqList)
{
    if(seqList == NULL)
    {
        return;
    }
    seqList->length = 0;
}
