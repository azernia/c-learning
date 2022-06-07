#ifndef _CHECK_H_
#define _CHECK_H_

/**
 * 获取next数组，存储每个位置的最大匹配长度及模式串的回溯位置
 * @param pattern
 * @param next 
 */
void getNext(char *pattern, int *next);

#endif // _CHECK_H_