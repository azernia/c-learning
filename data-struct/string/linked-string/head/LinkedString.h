#ifndef _LINKEDSTRING_H_
#define _LINKEDSTRING_H_

#include "linkListData.h"
#include "StatusLib.h"

/**
 * 初始化连串
 * @param linkedString 
 */
void initLinkedString(LinkedString *linkedString);

/**
 * 为连串赋值
 * @param linkedString 
 * @param str 
 * @return Status 
 */
Status strAssign(LinkedString *linkedString, char *str);

/**
 * 复制字符串
 * @param dest 
 * @param src 
 * @return Status 
 */
Status strCopy(LinkedString *dest, LinkedString *src);

/**
 * 比较两个字符串
 * @param str1 
 * @param str2 
 * @return Status 
 */
Status compare(LinkedString *str1, LinkedString *str2);

/**
 * 是否为空
 * @param linkedString 
 * @return Status 
 */
Status isEmpty(LinkedString *linkedString);

#endif