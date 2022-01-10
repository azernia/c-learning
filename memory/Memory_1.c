#include<stdio.h>
#include<stdlib.h> // 内存管理库

int main()
{
    /*
        向系统申请 size 个字节的内存空间，并返回一个指向该内存空间的 void 指针
        失败返回 NULL
        size 为 0 时可能返回 NULL 并不是失败
        动态内存存储在堆中
    */
    int *ptr;
    // 显示声明 增加可读性
    ptr = (int *)malloc(sizeof(int));
    if(ptr == NULL)
    {
        printf("内存分配失败");
        exit(1);
    }
    printf("请输入一个整数:");
    scanf("%d", ptr);
    printf("ptr = %d\n", *ptr);
    /*
        释放动态内存空间
        该内存空间必须由 malloc calloc realloc 函数申请
        不能释放局部变量内存
    */
    free(ptr);
    return 0;
}