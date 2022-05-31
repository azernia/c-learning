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

Status strCopy(HeepString *str, HeepString *source)
{
    init(str);
    if(isEmpty(source))
    {
        printf("source is empty\n");
        return ERROR;
    }
    str->ch = (char *)malloc(source->length * sizeof(char));
    // malloc error
    if(!str->ch)
    {
        exit(OVERFLOW);
    }
    for(int i = 0; i < source->length; i++)
    {
        str->ch[i] = source->ch[i];
    }
    str->length = source->length;
    return OK;
}

Status strCompare(HeepString *str1, HeepString *str2)
{
    if(isEmpty(str1) || isEmpty(str2))
    {
        printf("str1 or str2 is empty\n");
        return ERROR;
    }
    if(str1->length > str2->length)
    {
        return GT;
    }
    else if(str1->length < str2->length)
    {
        return LT;
    }
    else
    {
        for(int i = 0; i < str1->length; i++)
        {
            if(str1->ch[i] > str2->ch[i])
            {
                return GT;
            }
            else if(str1->ch[i] < str2->ch[i])
            {
                return LT;
            }
        }
        return EQ;
    }
}

Status concat(HeepString *resultStr, HeepString *str1, HeepString *str2)
{
    if(isEmpty(str1) || isEmpty(str2))
    {
        printf("str1 or str2 is empty\n");
        return ERROR;
    }
    init(resultStr);
    resultStr->ch = (char *)malloc((str1->length + str2->length) * sizeof(char));
    if(!resultStr->ch)
    {
        exit(OVERFLOW);
    }
    for(int i = 0; i < str1->length; i++)
    {
        resultStr->ch[i] = str1->ch[i];
    }
    for(int i = 0; i < str2->length; i++)
    {
        resultStr->ch[str1->length + i] = str2->ch[i];
    }
    resultStr->length = str1->length + str2->length;
    return OK;
}

Status subStr(HeepString *resultStr, HeepString *source, int pos, int len)
{
    if(isEmpty(source))
    {
        printf("source is empty\n");
        return ERROR;
    }
    if(pos < 0 || pos > source->length)
    {
        printf("pos is error\n");
        return ERROR;
    }
    if(len < 0 || len > source->length - pos)
    {
        printf("len is error\n");
        return ERROR;
    }
    init(resultStr);
    resultStr->ch = (char *)malloc(len * sizeof(char));
    if(!resultStr->ch)
    {
        exit(OVERFLOW);
    }
    for(int i = 0; i < len; i++)
    {
        resultStr->ch[i] = source->ch[pos + i];
    }
    resultStr->length = len;
    return OK;
}

int indexOf(HeepString *parent, HeepString *child, int pos)
{
    if(isEmpty(parent) || isEmpty(child))
    {
        printf("parent or child is empty\n");
        return ERROR;
    }
    if(pos < 0 || pos > parent->length)
    {
        printf("pos is error\n");
        return ERROR;
    }
    int i = pos;
    HeepString *subString = (HeepString *)malloc(sizeof(HeepString));
    init(subString);
    while (i + child->length - 1 <= parent->length)
    {
        subStr(subString, parent, i - 1, child->length);
        if(strCompare(subString, child) == EQ)
        {
            return i;
        }
        else {
            i++;
        }
    }
    return 0;
}

Status delete(HeepString *source, int pos, int len)
{
    if(isEmpty(source))
    {
        printf("source is empty\n");
    }
    if(pos < 0 || pos > source->length)
    {
        printf("pos is ERROR\n");
        return ERROR;
    }
    if(len < 0 || len > source->length)
    {
        printf("len is ERROR\n");
        return ERROR;
    }
    for(int i = pos - 1; i + len < source->length; i++)
    {
        source->ch[i] = source->ch[i + len];
    }
    source->length -= len;
    // 缩小分配空间
    source->ch = (char *)realloc(source->ch, source->length * sizeof(char));
    return OK;
}

Status insert(HeepString *source, int pos, HeepString *insertStr)
{
    if(isEmpty(source))
    {
        printf("source is empty\n");
        return ERROR;
    }
    if(isEmpty(insertStr))
    {
        printf("insertStr is empty\n");
        return ERROR;
    }
    if(pos < 0 || pos > source->length)
    {
        printf("pos is ERROR\n");
        return ERROR;
    }
    source->ch = (char *)realloc(source->ch, (source->length + insertStr->length) * sizeof(char));
    if(!source->ch)
    {
        exit(OVERFLOW);
    }
    // 为插入腾出位置
    for(int i = source->length - 1; i >= pos - 1; i--)
    {
        source->ch[i + insertStr->length] = source->ch[i];
    }
    // 插入字符
    for(int i = 0; i < insertStr->length; i++)
    {
        source->ch[pos - 1 + i] = insertStr->ch[i];
    }
    source->length += insertStr->length;
    return OK;
}

Status replace(HeepString *str, HeepString oldStr, HeepString newStr)
{
    if(isEmpty(str))
    {
        printf("str is empty\n");
        return ERROR;
    }
    // 找到oldStr
    int pos = indexOf(str, &oldStr, 0);
    while(pos != 0)
    {
        delete(str, pos, oldStr.length);
        insert(str, pos, &newStr);
        pos += newStr.length;
        pos = indexOf(str, &oldStr, pos);
    }
    return OK;
}

Status clearString(HeepString *str)
{
    if(str->ch)
    {
        free(str->ch);
        str->ch = NULL;
    }
    str->length = 0;
    return OK;
}

Status isEmpty(HeepString *str)
{
    if(str->length == 0 || str->ch == NULL)
    {
        return TRUE;
    }
    return FALSE;
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