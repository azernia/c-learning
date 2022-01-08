#include<stdio.h>

int main()
{
    /*
        int **p = array;
        p+1 != array+1  二者跨度不同
        p+1 每次增加类型长度
        array+1 每次增加一行
    */
    int array[][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    int (*p)[4] = array;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%3d", *(*(p + i) + j));
        }
        printf("\n");
    }
    return 0;
}