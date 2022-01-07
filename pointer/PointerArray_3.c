#include<stdio.h>

int main()
{
    /*
        指向数组的指针
        当指针指向数组元素时可对指针变量进行加减运算
    */
    char a[] = "Hello";
    char *p = a;
    printf("*p = %c, *(p+1) = %c\n", *p, *(p+1));
    return 0;
}