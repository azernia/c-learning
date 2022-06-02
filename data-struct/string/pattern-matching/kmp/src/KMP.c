#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../head/KMP.h"

void getNext(char *pattern, int *next)
{
    int i = 0;
    int j = -1;
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

int kmp(char *text, char *pattern)
{
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    // int next[10];
    getNext(pattern, next);
    int i = 0;
    int j = 0;
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    while(i < text_len && j < pattern_len){
        if(j == -1 || text[i] == pattern[j]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }
    }
    if(j == strlen(pattern)){
        return (i + 1) - j;
    }
    return 0;
}