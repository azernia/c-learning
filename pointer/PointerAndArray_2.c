#include<stdio.h>

int main()
{
    /*
        数组名为数组第一个元素的地址
            数组中每一个元素的地址间隔为该类型所占的字节大小
    */
    char str[128];
    printf("Please input a sentence\n");
    scanf("%s", str);
    printf("the sentence is :%s\n", str);
    printf("the sentence is :%p\n", str);
    printf("the sentence is :%p\n", &str[0]);
    return 0;
}