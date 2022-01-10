#include<stdio.h>
#include<stdlib.h>

int main()
{
    /*
        calloc 在申请完内存后自动初始化该内存空间为 0
    */
   int *ptr = (int *)calloc(4, sizeof(int));
    return 0;
}