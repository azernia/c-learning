#include<stdio.h>

// 常量
#define SIZE  10

int main()
{
    // 数组的定义
    int array[SIZE];
    int i;
    for(i = 0 ; i < 6; i++) {
        printf("please input %d number:", i+1);
        scanf("%d", &array[i]);
    }
    printf("%d", array[0]);
    return 0;
}