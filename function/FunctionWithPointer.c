#include<stdio.h>

/**
 * 交换 x y
 * 
 * @param x 
 * @param y 
 */
void swap(int x, int y);

/**
 * 通过指针的方式进行交换
 * 
 * @param p_x 
 * @param p_y 
 */
void swapByPointer(int *p_x, int *p_y);

/**
 * 打印数组的值
 * 
 * @param a 
 */
void showArray(int a[10]);

void showArray(int a[10])
{
    for(int i = 0; i < 10; i++)
    {
        printf("Array[%d] = %d\n", i, a[i]);
    }
}

void swapByPointer(int *p_x, int *p_y)
{
    int temp;
    temp = *p_x;
    *p_x = *p_y;
    *p_y = temp;
    printf("x = %d, y = %d\n", *p_x, *p_y);
}

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("x = %d, y = %d\n", x, y);
}

int main()
{
    /*
        通过指针传递值函数可以修改实参的值
    */
    int x, y;
    int array[10] = {
        0,1,2,3,4,5,6,7,8,9
    };
    printf("Please input x:");
    scanf("%d", &x);
    printf("Please input y:");
    scanf("%d", &y);
    printf("before swap\n");
    printf("x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("after swap\n");
    printf("x = %d, y = %d\n", x, y);
    printf("======================\n");
    printf("before swap by pointer\n");
    printf("x = %d, y = %d\n", x, y);
    swapByPointer(&x, &y);
    printf("after swap by pointer\n");
    printf("x = %d, y = %d\n", x, y);
    // 只传递了数组的第一个元素的地址
    showArray(array);
    return 0;
}