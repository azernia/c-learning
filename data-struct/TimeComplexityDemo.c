#include<stdio.h>

void loveYou(int n);

void loveYou(int n)
{
    // n 问题规模
    int i = 1;
    while(i <= n) 
    {
        printf("i love you %d\n", i);
        i++;
    }
    printf("i love you more than %d\n", n);
}

int main()
{
    loveYou(3000);
    return 0;
}