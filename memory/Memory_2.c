#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr = NULL;
    int num;
    printf("请输入待录入整数的个数:");
    scanf("%d", &num);

    // 该方式申请的内存空间是连续的
    ptr = (int *)malloc(num * sizeof(int));

    for (int i = 0; i < num; i++)
    {
        printf("请录入第%d个整数:", i + 1);
        // scanf("%d", ptr + i);
        scanf("%d", &ptr[i]);
    }
    printf("=======================\n");
    for (int i = 0; i < num; i++)
    {
        printf("%2d", ptr[i]);
    }
    putchar('\n');
    free(ptr);

    return 0;
}