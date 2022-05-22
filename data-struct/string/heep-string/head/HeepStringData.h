#ifndef _HEEPSTRINGDATA_H_
#define _HEEPSTRINGDATA_H_

/**
 * 串的顺序结构实现 
 */
#define MAX_SIZE 1024

// typedef struct SeqString
// {
//     char ch[MAX_SIZE + 1];  // 定长方式实现字符串的顺序结构，缺点是浪费空间
//     int length;
// };
/**
 * 串的堆式顺序存储结构，堆(Heep)
 */
typedef struct HeepString
{
   char *ch;    // 如果是非空字符串，那么久按照指定长度分配内存，否则 char 指向 NULL
   int length; // 指定长度
} HeepString;



#endif