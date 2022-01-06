#include<stdio.h>
#include<string.h>
/*
    数组的处理
    C 没有字符串类型
    表示方法
    1. 字符串常量 "a" 无法改变
    2. 字符类型的数组 需添加字符串的结束符 \0
*/

int main()
{
    // 初始化字符数组
    char str1[5] = {'H', 'L', 'L', 'O', '\0'};
    char str2[] = {'H', 'L', 'L', 'O', '\0'};
    char str3[] = {"hello world"};
    char str4[] = "Hello Rui";
    char testStr1[] = "hello";
    char testStr2[] = "hello";
    printf("%s\n", &str1);
    printf("%s\n", &str2);
    printf("%s\n", &str3);
    printf("%s\n", &str4);
    printf("==============================\n");
    // 获取字符串长度
    printf("sizeof = %d\n", sizeof(str1));
    printf("length = %d\n", strlen(str1));
    // 拷贝字符串
    char str5[15];
    // 第一个参数为目标
    // strcpy 目标字符数组中
    strcpy(str5, str1);
    printf("%s\n", str5);
    strcpy(str3, str4);
    printf("%s\n", str3);
    // 追加字符串
    strcat(str1, str2);
    printf("%s\n",str1);
    printf("======================================\n");
    // 相同返回0
    printf("%d", strcmp(testStr1, testStr2));
    return 0;
}