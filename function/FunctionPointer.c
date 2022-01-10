#include<stdio.h>

// int square(int num); 函数声明方式二
int square(int);

int square(int num)
{
    return num * num;
}

int main()
{
    /*
        函数指针
            指向函数的指针
    */
    int num;
    // 定义函数指针
    int (*f_p)(int);
    printf("Please input a integer:");
    scanf("%d", &num);
    // 函数名相当于函数的地址
    f_p = square;
    printf("%d\n", (*f_p)(num));
    printf("%d\n", f_p(num));
    return 0;
}