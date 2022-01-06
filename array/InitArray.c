#include<stdio.h>

#define SIZE 10

int main()
{    
    // 将数组中的所有元素初始化为10
    int array1[SIZE] = {0}; // 事实上只是将第一个值赋值为0 当第一个值改变时后面的值默认为0
    int array2[SIZE] = {0,1,2,3,4,5,6,7,8,9};   // 单个赋值
    int array3[SIZE] = {0,1,2,3};    // 初始化部分元素
    int array4[] = {0, 1, 2, 3};    // 默认长度4
    return 0;
}