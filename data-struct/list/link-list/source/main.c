#include <stdio.h>
#include <stdlib.h>

#include "../head/linkList.h"
#include "linkList.c"

int main()
{
    int dataArray[] = {
        1,2,3,4,5,6,7,8,9
    };
    LinkList linkList;
    initLinkList(&linkList, dataArray, sizeof(dataArray)/sizeof(dataArray[0]));
    printLinkList(&linkList);
    insertLinkList(&linkList, 10, 1);
    printf("after insert 10 ===================\n");
    printLinkList(&linkList);
    printf("===================\n");
    printf("%d\n",getElement(&linkList, 1));
    printf("===================\n");
    printf("%d\n", delElement(&linkList, 2));
    printf("===================\n");
    printLinkList(&linkList);
    printf("===================\n");
    printf("clear link list\n");
    clearLinkList(&linkList);
    printf("===================\n");
    printLinkList(&linkList);
    return 0;
}