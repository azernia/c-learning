/**
 * Created by Rui on 2022/6/23.
 */
#include "../../head/sequnce/SequneceList.h"

void init(SequenceList *list) {
    list->length = 0;
    list->data = (ElementType *) malloc(sizeof(ElementType) * MAX_SIZE);
}

void printSeqList(SequenceList list) {
    for (int i = 1; i <= list.length; ++i) {
        printf("%d\t%s\n", list.data[i].key, list.data[i].value);
    }
}

int searchSeqList(SequenceList list, int key) {
    for (int i = 1; i <= list.length; ++i) {
        if (list.data[i].key == key) {
            return i;
        }
    }
    return 0;
}

int searchSeqListOptimize(SequenceList list, int key) {
    // 第一个位置的元素设置为哨兵
    list.data[0].key = key;
    int i;
    for(i = list.length; list.data[i].key != key; i--);
    return i;
}

void test() {
    SequenceList list;
    init(&list);
    int keys[] = {
            10, 39, 22, 78, 3, 7, 48
    };
    char *values[] = {
            "刀锋女王","盖伦","阿尔萨斯","吉姆雷诺","劳拉克劳馥","大黄蜂","擎天柱"
    };
    int length = sizeof keys / sizeof keys[0];
    for (int i = 1; i <= length; ++i) {
        list.data[i].key = keys[i - 1];
        list.data[i].value = (char *) malloc(sizeof(char ) * MAX_INFO_SIZE);
        strcpy(list.data[i].value, values[i - 1]);
        list.length++;
    }
    printf("初始化顺序表\n");
    printSeqList(list);
    int searchKey = 39;
    int index = searchSeqList(list, searchKey);
    printf("普通顺序查找：searchKey = %d, index = %d\n", searchKey, index);
    index = searchSeqListOptimize(list, searchKey);
    printf("改进顺序查找：searchKey = %d, index = %d\n", searchKey, index);
}