#include<stdio.h>
#include<stdlib.h>
// 给结构体取别名为 Date
typedef struct Date
{
    int year;
    int month;
    int day;
} Date, *P_Date;


int main()
{
    struct Date *date;

    // date = (struct Date *)malloc(sizeof(struct Date)); 原写法

    // 使用 typedef 后的写法
    date = (P_Date)malloc(sizeof(Date));
    if(date == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    date->year = 12;
    date->month = 1;
    date->day = 1;
    printf("%d - %d - %d\n", date->year, date->month, date->day);
    return 0;
}