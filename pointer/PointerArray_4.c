#include<stdio.h>

int main()
{
    // 指针数组 指针类型的数组 每个数组元素存放一个指针变量
    char *p1[5] = {
        "hello world",
        "today is a nice day",
        "how are you going in the past few days",
        "can i go with you",
        "thank you"
    };
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", p1[i]);
    }
    printf("=================================\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%c\n", *p1[i]);
    }
    printf("=================================\n");
    // 数组指针 是一个指针 一个指向数组的指针 (*p2) => char *p = str p
    /*
        对于数组指针(*p)[5] -> *p(取出数组) -> *(*p + i) -> 访问第i个元素
    */
    int temp[5] = {1,2,3,4,5}; 
    int (*p2)[5] = &temp;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(*p2 + i));
    }
    
    return 0;
}