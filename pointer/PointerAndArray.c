#include<stdio.h>

int main()
{
    int a;
    int *p = &a;
    printf("Please input a integer\n");
    scanf("%d", &a);
    printf("a = %d\n", a);
    printf("=========================");
    printf("Please input another integer\n");
    scanf("%d", p);
    printf("a = %d\n", a);
    return 0;
}