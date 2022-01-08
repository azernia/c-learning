#include<stdio.h>

int main()
{
    /**
     *  array 表示{1,2,3,4,5} 的地址
     *  解引用 将一个地址的值取出来
    */
    int array[4][5];
    // *(array + 1) = array[1]
    int k = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            array[i][j] = k++;
        }
    }
    printf("*(array + 1) = %p\n", *(array + 1));
    printf("array[1] = %p\n", array[1]);
    printf("&array[1][0] = %p\n", &array[1][0]);
    printf("**(array + 1) = %d\n", **(array + 1));
    printf("*(*(array + 1)+3) = %d\n", *(*(array + 1)+3));
    printf("array[1][3] = %d\n", array[1][3]);
    return 0;
}