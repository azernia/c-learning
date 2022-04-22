#include <stdio.h>
#include <stdlib.h>

#include "../head/StaticLinkedList.h"
#include "../head/StaticLinkedListData.h"
#include "StaticLinkedList.c"

int main()
{
    StaticLinkedList list;
    initStaticLinkedList(list);
    printStaticLinekdList(list);
    return 0;
}