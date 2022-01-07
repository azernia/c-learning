#include<stdio.h>

int main()
{
    /*
        一个指针占 4bytes
        a -> 10000 指针
        pa -> 11000 -> 10000 指针变量
        避免访问未初始化的指针
    */

    // 直接赋值
    int a = 10;
    // 指针变量的定义
    // 取地址运算符 &
    int *pa = &a;
    // 访问指针变量指向的数据 取值运算符 *
    printf("%d\n", *pa);
    // 通过指针变量赋值 间接赋值
    *pa = 3;
    printf("%d\n", *pa);
    printf("size pointer : %lu\n", sizeof(*pa));
    return 0;
}