#include<stdio.h>
/**
 * void 指针
*/
int main()
{
    // error: variable or field 'a' declared void
    // void a;
    /*
        通用指针
            可以指向任意类型的数据
            任何类型的指针都可以复制给 void 指针
            不要直接对 void 类型进行解引用 系统不知道
            支持不同类型指针之间的转换
    */
    int num = 1024;
    int *pi = num;
    char *ps = "Rui";
    void *pv;
    pv = pi;
    printf("pi = %p, pv = %p\n", pi, pv);
    pv = ps;
    printf("pv = %p, ps = %p\n", pv, ps);
    return 0;
}