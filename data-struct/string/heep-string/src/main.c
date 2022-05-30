#include <stdio.h>
#include <stdlib.h>
#include "../head/HeepString.h"
#include "HeepString.c"

int main()
{
    HeepString str;
    init(&str);
    strAssign(&str, "hello");
    strPrint(&str);
    return 0;
}