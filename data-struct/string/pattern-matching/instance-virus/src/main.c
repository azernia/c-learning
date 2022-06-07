#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/check.h"
#include "check.c"

int main()
{
    char *pattern = "ababaa";
    int next[strlen(pattern)];
    getNext(pattern, next);
    for (int i = 0; i < strlen(pattern); ++i)
    {
        printf("%d ", next[i]);
    }
    return 0;
}