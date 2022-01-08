#include<stdio.h>

int main()
{
    // 二维数组的定义
    // int a[6][6];
    // 二维数组的初始化
    int a[2][2] = {1,2,3,4};
    printf("%d\n", a[0][0]);
    // 二维数组的遍历
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("二维数组输出结果:%d\n", a[i][j]);
        }
    }
    // 二维数组初始化 方式二
    int b[2][2] = {
        {1,2},
        {3,4}
    };
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("二维数组输出结果:%d\n", b[i][j]);
        }
    }
    // 初始化二维数组 方式三
    int c[][2] = {
        {1,2},
        {3,4}
    };
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("二维数组输出结果:%d\n", c[i][j]);
        }
    }
    return 0;
}