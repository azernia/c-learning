#include <stdio.h>
#include <stdlib.h>
#include "../head/BF.h"
#include "BF.c"

/**
 * BF 算法
 * @return int 
 */
int main()
{
    char *pattern = "aaaacab";
    char *text = "ab";
    printf("%d\n", BF(pattern, text, 1));
    return 0;
}