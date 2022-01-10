#include<stdio.h>
#include<stdarg.h>  // 可变参数需要引入的头文件

/**
 * 可变参数
 * n 类型可以改变
 * 
 * @param n 表示几个数
 * @param ... 参数个数不确定
 * @return int 
 */
int sum(int n, ...);

int sum(int n, ...)
{
    int sum = 0;
    // 定义参数列表
    va_list list;
    // 初始化参数列表
    va_start(list, n);
    for(int i = 0; i < n; i++)
    {
        sum += va_arg(list, int);
    }
    // 关闭参数列表
    va_end(list);
    return sum;
}

int main()
{
    int result;
    result = sum(3, 1,2,3);
    printf("result = %d\n", result);
    return 0;
}