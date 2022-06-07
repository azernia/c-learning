#include <stdlib.h>
#include <string.h>
#include "../head/check.h"

// 从 next[1] 开始
// void getNext(char *pattern, int *next)
// {
//     int i = 1;  // i表示模式串的下一个位置
//     int j = 0;  // j表示模式串前一个位置
//     next[0] = -1;
//     next[1] = 0;
//     while (i < strlen(pattern))
//     {
//         if (j == 0 || pattern[i - 1] == pattern[j - 1])
//         {
//             i++;
//             j++;
//             next[i] = j;
//         }
//         else
//         {
//             j = next[j];
//         }
//     }
// }

// next[0] 开始
void getNext(char *pattern, int *next)
{
    int i = 0; // i表示模式串的下一个位置
    int j = -1; // j表示模式串前一个位置
    next[0] = -1;
    while(i < strlen(pattern)){
        if(j == -1 || pattern[i] == pattern[j]){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}