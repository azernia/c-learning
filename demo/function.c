#include<stdio.h>
#include"function.h"

void showMessage(char *str)
{
    printf("%s\n", str);
}

int main()
{
    showMessage("hello world");
    return 0;
}