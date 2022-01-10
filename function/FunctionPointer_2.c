#include<stdio.h>

int add(int num1, int num2);
int sub(int num1, int num2);
// 将函数指针用作参数
/**
 * @param f_p 函数地址
 * @param num1 
 * @param num2 
 * @return int 
 */
int calc(int (*f_p)(int, int), int num1, int num2);
// 将函数指针用作返回值，将指针指向有两个参数的函数
int (*selectFunction(char op))(int, int);

int (*selectFunction(char op))(int num1, int num2)
{
    switch(op)
    {
        case '+':
            return add;
        case '-':
            return sub;
    }
    return NULL;
}

int calc(int (*f_p)(int, int), int num1, int num2)
{
    return f_p(num1, num2);
}

int add(int num1, int num2)
{
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

int main()
{
    int num1, num2;
    char op;
    int (*f_p)(int, int);
    printf("Please input a expression:");
    scanf("%d%c%d", &num1, &op, &num2);
    printf("3 + 5 = %d\n", calc(add, 3, 5));
    f_p = selectFunction(op);
    printf("%d %c %d = %d\n",num1, op, num2, calc(f_p, num1, num2));
    return 0;
}