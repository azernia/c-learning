#include<stdio.h>

int main()
{
    int size;
    printf("请输入字符数组大小:\n");
    scanf("%d", &size);
    char charArray[size+1];
    printf("开始输入字符:\n");
    // 去除换行符
    getchar();
    for (int i = 0; i < size; i++)
    {
        scanf("%c", &charArray[i]);
    }
    charArray[size] = '\0';
    printf("%s\n", charArray);
    return 0;
}