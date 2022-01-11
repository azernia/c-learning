#include<stdio.h>

// 区别名
typedef int integer;

int main()
{
    integer a = 123;
    printf("%d\n, size = %lu\n", a, sizeof(a));
    return 0;
}