#include<stdio.h>

struct Book
{
    char title[255];
    char author[40];
    float price;
    // 日期
    unsigned int date;
    // 出版社
    char publisher[40];
};

/*
    定义方式二
struct Book
{
    char title[255];
    char author[40];
    float price;
    // 日期
    unsigned int date;
    // 出版社
    char publisher[40];
} book; // 全局的
*/

int main()
{
    struct Book book;
    printf("请输入书名:");
    scanf("%s", book.title);
    printf("请输入作者");
    scanf("%s", book.author);
    printf("请输入价格");
    scanf("%f", &book.price);
    printf("请输入日期");
    scanf("%d", &book.date);
    printf("请输入出版社");
    scanf("%s", book.publisher);
    printf("====================");
    printf("作者:%s", book.author);
    return 0;
}