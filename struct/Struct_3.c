#include<stdio.h>

struct Date
{
    int year;
    int month;
    int day;
};


struct Book
{
    char title[100];
    char author[40];
    // 结构体的嵌套
    struct Date date;
    char publisher[40];
} book = {
    "A",
    "B",
    {2021,12,12},
    "C"
};

int main()
{
    printf("%s\n%s\n%d%d%d\n%s\n",book.title, book.author, book.date.year, book.date.month, book.date.day, book.publisher);
    return 0;
}