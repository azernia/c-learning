#ifndef _KMP_H_
#define _KMP_H_

/**
 * 返回next数组
 * @param text 
 * @param next 
 */
void getNext(char *text, int *next);

/**
 * KMP算法
 * @param text 匹配串
 * @param pattern 模式串
 * @return 
 */
int kmp(char *text, char *pattern);

#endif