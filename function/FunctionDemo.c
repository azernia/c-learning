#include<stdio.h>

// 函数声明
void showMessage();

/**
 * 累加
 * @param num 计算的值 
 * @return int 计算结果
*/
int cumulative(int num);

// 函数定义
void showMessage()
{
    printf("This is a show message function\n");
}

int cumulative(int num)
{
    int result, i;
    for(i = 1; i <= num; i++) 
    {
        result += i;
    }
    return result;
}



int main()
{
    /*
        当函数定义在 main 方法后时必须先声明
        当函数定义在 main 方法前时可以不进行声明
    */
    showMessage();
    printf("Please input a number that to cumulative\n");
    int calcNumber;
    int result;
    scanf("%d", &calcNumber);
    result = cumulative(calcNumber);
    printf("result = %d\n", result);
    return 0;
}