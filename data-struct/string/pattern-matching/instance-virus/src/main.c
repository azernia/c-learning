#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/check.h"
#include "check.c"

int main()
{
    char *str[10] = {
        "bbaabbba",
        "aaabbbba",
        "abceaabb",
        "abaabcea"
    };
    char *pattern[2] = {
        "baa",
        "aabb"
    };
    for(int i = 0; i < 2; i++)
    {
        printf("%s\n", str[i]);
        printf("%s\n", pattern[0]);
        printf("%s\n", checkVirus(str[i], pattern[i]) ? "YES" : "NO");
        printf("%d\n", checkVirus(str[i], pattern[i]));
    }
    return 0;
}