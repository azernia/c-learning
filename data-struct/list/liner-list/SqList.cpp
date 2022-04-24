#include<stdio.h>
#include<stdlib.h>

// 最大长度
#define MAX_SIZE 10
// 初始长度
#define INIT_SIZE 10

typedef int ElemType;

// 固定内存 MAX_SIZE
typedef struct
{
    ElemType data[MAX_SIZE];
    int length;
}SqList;

// 动态分配内存
typedef struct
{
    ElemType *data;
    // 顺序表最大容量
    int maxSize;
    int length;
}SqList2;

/**
 * 初始化顺序表，固定长度
 * 
 * @param list 
 */
void initListByfixedLength(SqList &list)
{
    // 当没有给 Data 赋予初始值时会添加内存中的脏数据
    for(int i = 0; i < MAX_SIZE; i++)
    {
        list.data[i] = i;
    }
    list.length = 0;
}

/**
 * 动态分配内存大小
 * 
 * @param list2 
 */
void initListByDynamic(SqList2 &list)
{
    list.data = (ElemType *)malloc(sizeof(ElemType) * INIT_SIZE);
    list.length = 0;
    list.maxSize = INIT_SIZE;
}

/**
 * 动态增加顺序表的长度
 * 
 * @param list 
 * @param size 增加的大小
 */
void increaseSize(SqList2 &list, int size)
{
    int *p_data = list.data;
    list.data = (ElemType *)malloc(sizeof(ElemType) * (list.maxSize + size));
    // 时间开销大
    for(int i = 0; i < list.length; i++)
    {
        // 将旧数据移动到新的内存空间中
        list.data[i] = p_data[i];
    }
    list.maxSize = list.maxSize + size;
    free(p_data);
}

int main()
{
    SqList2 list;
    initListByDynamic(list);
    
    increaseSize(list, 2);

    


    // 初始化顺序表
    // SqList list;
    // initListByfixedLength(list);

    // 违规的
    // for(int i = 0; i < MAX_SIZE; i++)
    // {
    //     printf("list.data[%d] = %d\n", i, list.data[i]);
    // }
    return 0;
}