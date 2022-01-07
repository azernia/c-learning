#include<stdio.h>
#include<string.h>

int main()
{
    /*
        字符数组遍历方法二
    */
    char str[] = "Hello World";
    int length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        printf("%c\n", str[i]);
    }
    printf("========================\n");
    /*
        字符数组遍历方式三
    */
   char *pStr = str;
   for(int i = 0; i < length; i++)
   {
       printf("%c\n", *(pStr+i));
   }
    return 0;
}