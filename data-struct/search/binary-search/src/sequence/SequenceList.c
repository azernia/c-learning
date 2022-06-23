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

int sequenceBinarySearch(SequenceList list, int searchKey) {
    int low = 1;
    int high = list.length;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (searchKey == list.data[mid].key) {
            return mid;
        } else if (searchKey < list.data[mid].key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
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
    int index = sequenceBinarySearch(list, searchKey);
    printf("二分查找法：searchKey = %d, index = %d\n", searchKey, index);
}