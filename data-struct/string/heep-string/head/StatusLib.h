#ifndef _STATUSLIB_H_
#define _STATUSLIB_H_

/**
 * 状态码定义
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define EQ 0
#define GT 1 // great than
#define LT -1 // less than
#ifndef _STATUS_H_ // 如果系统中已有下面状态码的定义，就不在重复定义
    #define OVERFLOW -2 // 堆栈上溢 超过所能表示的最大正数
    #define UNDERFLOW -3 // 堆栈下溢 超过所能表示的最小负数
#endif

typedef int Status; // 自定义状态码识别类型

#endif