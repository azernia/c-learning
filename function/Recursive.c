#include<stdio.h>

/**
 * 阶乘
 * 
 * @param num 
 * @return int 
 */
long factorial(int num);

long factorial(int num)
{
    long result;
    if(num > 0)
    {
        result = num * factorial(num - 1);
    }
    else
    {
        result = 1;
    }
    return result;
}

int main()
{
    printf("%ld\n", factorial(5));
    return 0;
}