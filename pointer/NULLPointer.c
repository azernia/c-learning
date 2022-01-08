#include<stdio.h>

int main()
{
    /*
        NULL 指针
            一个指针不指向任何数据 ---> 空指针
            ((void *)0) 将 0 变为指针
            NULL ===> #define NULL ((void *)0)
            当不清楚指针初始化为什么地址是，将其初始化为 NULL
    */
    int *p1;    // 会有野指针
    int *p2 = NULL;
    printf("%d\n", *p1);
    printf("%d\n", *p2);
    return 0;
}