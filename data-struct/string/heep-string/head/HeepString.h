#ifndef _HEEPSTRING_H_
#define _HEEPSTRING_H_

#include "HeepStringData.h"
#include "StatusLib.h"

/**
 * 初始化字符串
 * @param str 操作字符串
 */
void init(HeepString *str);

/**
 * 插入字符串
 * @param str 操作的串
 * @param chars 字符串
 * @return Status 
 */
Status strAssign(HeepString *str, char *chars);

/**
 * 打印字符串
 * @param str 
 */
void strPrint(HeepString *str);

#endif