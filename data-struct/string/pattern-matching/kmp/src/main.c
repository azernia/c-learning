#include <stdio.h>
#include <stdlib.h>
#include "KMP.c"

int main()
{
    char *text = "aaabbbccc";
    char *pattern = "bbb";
    printf("%d\n", kmp(text, pattern));
    return 0;
}