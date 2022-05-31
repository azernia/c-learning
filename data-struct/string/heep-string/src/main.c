#include <stdio.h>
#include <stdlib.h>
#include "../head/HeepString.h"
#include "HeepString.c"

int main()
{
    HeepString str1, str2;
    strAssign(&str1, "hello");
    strAssign(&str2, "ll");
    printf("%d\n", indexOf(&str1, &str2, 1));
    // HeepString resultStr, source;
    // strAssign(&source, "hello");
    // subStr(&resultStr, &source, 1, 2);
    // strPrint(&resultStr);
    // HeepString str;
    // HeepString source;
    // init(&str);
    // strAssign(&source, "hello");
    // strCopy(&str, &source);
    // strPrint(&source);
    // strPrint(&str);
    // HeepString resultStr;
    // HeepString str1;
    // HeepString str2;
    // strAssign(&str1, "hello");
    // strAssign(&str2, "world");
    // concat(&resultStr, &str1, &str2);
    // strPrint(&resultStr);
    return 0;
}