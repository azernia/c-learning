#include<stdio.h>

int main()
{
     int array[2][3] = {
         {0, 1, 2},
         {3, 4, 5}
     };
     // 数组指针
    int (*p)[3] = array;
    printf("**(p + 1) = %d\n", **(p + 1));
    printf("**(array + 1) = %d\n",  **(array + 1));
    printf("array[1][0] = %d\n", array[1][0]);
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%2d\n", *(*(array + i)+j));
        }
    }
    return 0;
}