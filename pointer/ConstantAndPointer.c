#include<stdio.h>

// 常量的定义
#define PRICE 520

int main()
{
    // 使用 const 关键字定义常量
    const float pi = 3.14;
    // 指向常量的指针 指针指向的地址可以修改 不可改变指针指向的值
    const float *ppi = &pi;
    // 常量指针 指针本身不可改变 指针指向的值可以改变
    float * const pppi = &pi;
    return 0;
}