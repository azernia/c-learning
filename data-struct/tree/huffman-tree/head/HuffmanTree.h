/**
 * 赫夫曼树的顺序存储
 * 1. 读取某个文件统计文件中各个字符出现的次数作为权重
 * 2. 构建赫夫曼树
 * 3. 生成对应编码保存到压缩文件
 * 4. 解压文件并保存到解压文件中
 * Created by Rui on 2022/6/14.
 */

#ifndef HUFFMAN_TREE_HUFFMANTREE_H
#define HUFFMAN_TREE_HUFFMANTREE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 256
#define HALF_MAX MAX_SIZE / 2
#define ASCII_SIZE 128  // ASCII 吗的数量 0-127 个字符

/**
 * 赫夫曼树结点
 */
 typedef struct HuffNode {
     char data; // 存放结点字符的数据域
     int weight;    //权重
     struct HuffNode *left; // 左孩子
     struct HuffNode *right;    // 右孩子
 } HuffNode;

 /**
  * 以顺序结构存储的树节点
  * 编码解码的字符映射表
  * 0100101。。。
  */
 HuffNode nodes[MAX_SIZE];

 /**
  * 保存左孩子的结点数组
  */
 HuffNode lefts[HALF_MAX];

 /**
  * 保存右孩子的结点数组
  */
 HuffNode rights[HALF_MAX];

 /**
  * 编码数组
  * 一维数组 字符的 ASCII 码
  *
  */
 char code[ASCII_SIZE][HALF_MAX];

 /**
  * 冒泡排序
  * 以权重大到小排序
  * @param node
  * @param length
  */
 void sortHuffmanCode(HuffNode *nodeArray, int length);

 /**
  * 构造赫夫曼树
  * @param node 赫夫曼树的结点数组
  * @param length 结点数组的长度
  */
 void createHuffTree(HuffNode *nodeArray, int length);

 /**
  * 编码过程（压缩）
  * @param node 结点
  * @param tempArray 编码后的字符数组（keepCode）
  * @param index 当前操作字符的数组下标
  */
 void coding(HuffNode *node, char *tempArray, int index);

 /**
  * 解码
  * @param node
  * @param flag 0 1 判断向左向右
  * @return
  */
 HuffNode * decoding(HuffNode *node, int flag);

#endif //HUFFMAN_TREE_HUFFMANTREE_H
