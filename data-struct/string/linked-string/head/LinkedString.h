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

#endif