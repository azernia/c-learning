#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/HeepString.h"
#include "../head/HeepStringData.h"

void init(HeepString *str)
{
    str->ch = NULL;
    str->length = 0;
}

Status strAssign(HeepString *str, char *chars)
{
    int len = strlen(chars);
    if(!len)
    {
        return ERROR;
    }
    init(str);
    str->ch = (char *)malloc(len * sizeof(char));
    if(!str->ch)
    {
        exit(OVERFLOW);
    }
    for(int i = 0; i < len; i++)
    {
        str->ch[i] = chars[i];
    }
    str->length = len;
    return OK;
}

void strPrint(HeepString *str)
{
    if(str->length == 0 || !str->ch)
    {
        printf("NULL\n");
        return;
    }
    for(int i = 0; i < str->length; i++)
    {
        printf("%c", str->ch[i]);
    }
}