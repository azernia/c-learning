#include<stdio.h>

int main()
{
    char *cBooks[] = {
        "《C程序设计语言》",
        "《C专家编程》",
        "《C和指针》",
        "《C陷阱与缺陷》",
        "《C Primer Plus》",
        "《带你学习带你飞》"
    };
    char **learningC;
    char **favorite[4];
    learningC = &cBooks[5];
    favorite[0] = &cBooks[0];
    favorite[1] = &cBooks[1];
    favorite[2] = &cBooks[2];
    favorite[3] = &cBooks[3];
    favorite[4] = &cBooks[4];
    return 0;
}