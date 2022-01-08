#include<stdio.h>

int main()
{
    /*
        指向指针的指针
    */
    int num = 520;
    int *p = &num;
    int **pp = &p;
    printf("num's address = %p, p's value = %p\n", &num, p);
    printf("p's address = %p\n", &p);
    printf("pp's address = %p\n", pp);
    return 0;
}