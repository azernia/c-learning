#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BF(char *pattern, char *text, int pos)
{
    int i = pos; // 当前模式串的位置
    int j = 1; // 当前文本串的位置
    int pattern_len = strlen(pattern);
    int text_len = strlen(text);
    while(i <= pattern_len && j <= text_len)
    {
        if(pattern[i - 1] == text[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2; // i回退 i 从 1 开始，从 0 开始为 i - j + 1
            j = 1; // j从头开始
        }
    }
    if(j > text_len)
    {
        // return i - j;
        return i - text_len;
    }
    return 0;
}