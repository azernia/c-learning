#include<stdio.h>

struct Demo
{
    int a;
    int b;
} demo = {
    1,2
};


int main()
{
    /*
        . 用于结构体对象
        -> 用于指针
    */
    // 结构体指针
    struct Demo *demo1;
    // 结构体指针使用方式 1
    demo1 = &demo;
    // . 优先级高于 *
    printf("a = %d\n", (*demo1).a);
    // 结构体指针使用方式 2 指向成员变量
    printf("b = %d\n", demo1->b);
    return 0;
}