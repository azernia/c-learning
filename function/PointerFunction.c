#include<stdio.h>

char *getWord(char);

// 通过 char 的指针接受返回的字符串
char *getWord(char c)
{
    switch(c)
    {
        case 'A':
            return "Apple";
        case 'B':
            return "Banana";
        default:
            return "None";
    }
}

int main()
{   
    /*
        指针函数
            使用指针变量作为返回值的函数
        不要返回局部变量的指针
    */
    char input;
    printf("Please input a letter:");
    scanf("%c", &input);
    printf("%s\n", getWord(input));
    return 0;
}