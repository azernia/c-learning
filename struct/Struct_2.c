#include<stdio.h>

#define PI 3.14

// 结构体的初始化
struct Demo
{
    char a;
    int b;
} demo = {
    'A',
    12
};

int main()
{
    printf("%c\n", demo.a);
    printf("%d\n", demo.b);

    return 0;
}