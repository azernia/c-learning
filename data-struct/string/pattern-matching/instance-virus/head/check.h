#ifndef _CHECK_H_
#define _CHECK_H_

/**
 * 获取next数组，存储每个位置的最大匹配长度
 * @param pattern
 * @param next 从 1 开始存储 0 存 -1
 */
void getNext(char *pattern, int *next);

#endif // _CHECK_H_