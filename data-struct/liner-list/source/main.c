#include <stdio.h>
#include <stdlib.h>
#include "../head/SequenceList.h"
#include "../head/SequenceListData.h"
#include "SequenceList.c"

ElementType array[] = {
        0,1,2,3,4,5,6,7,8,9
};

int main()
{
    SeqList seqList;
    ElementType *element = NULL;
    int index;
    initList(&seqList, array, sizeof(array)/sizeof(array[0]));
    printList(&seqList);
    // element = deleteElement(&seqList, 1);
    // printList(&seqList);
    // printf("删除的元素为:%d\n", *element);
    index = existElement(&seqList, 12);
    printf("返回结果为：%d\n", index);
    free(element);
    return 0;
}