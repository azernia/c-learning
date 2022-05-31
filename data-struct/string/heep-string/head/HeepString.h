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
 * 复制字符串
 * @param str 操作的字符串
 * @param source 复制的字符串
 * @return Status 
 */
Status strCopy(HeepString *str, HeepString *source);

/**
 * 判断是否为空
 * @param str 判断的字符串
 * @return Status 
 */
Status isEmpty(HeepString *str);

/**
 * 比较两个字符串的大小
 * @param str1 
 * @param str2 
 * @return Status 
 */
Status strCompare(HeepString *str1, HeepString *str2);

/**
 * 连接两个字符串
 * @param resultStr 返回的字符串
 * @param str1 
 * @param str2 
 * @return Status 
 */
Status concat(HeepString *resultStr, HeepString *str1, HeepString *str2);

/**
 * 字符串截取
 * @param resultStr 
 * @param source 
 * @param pos 0 开始
 * @param len 
 * @return Status 
 */
Status subStr(HeepString *resultStr, HeepString *source, int pos, int len);

/**
 * 从pos位置开始的字串在父串中的位置
 * @param parent 
 * @param child 
 * @param pos 0
 * @return int 
 */
int indexOf(HeepString *parent, HeepString *child, int pos);

/**
 * 删除字符串
 * @param source 
 * @param pos 1
 * @param len 
 * @return Status 
 */
Status delete(HeepString *source, int pos, int len);

/**
 * 向指定位置插入串
 * @param source 
 * @param pos 
 * @param insertStr 
 * @return Status 
 */
Status insert(HeepString *source, int pos, HeepString *insertStr);

/**
 * 将串中的字符串替换
 * @param str 
 * @param oldStr 
 * @param newStr 
 * @return Status 
 */
Status replace(HeepString *str, HeepString oldStr, HeepString newStr);

/**
 * 打印字符串
 * @param str 
 */
void strPrint(HeepString *str);

#endif