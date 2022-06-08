//
// Created by Rui on 2022/6/8.
//

#ifndef BINARY_TREE_SEQBINARYTREE_H
#define BINARY_TREE_SEQBINARYTREE_H

#include <stdio.h>
#include <math.h>
#include "SeqBinaryTreeData.h"

/**
 * 初始化树
 * @param seqTree
 */
void initSeqBinaryTree(SeqTree seqTree);

/**
 * 创建二叉树，创建一个结点的时候同时需要创建左结点与右结点
 * @param seqTree
 * @param index 数组下标
 */
void createSeqBinaryTree(SeqTree seqTree, int index);

/**
 * 获取二叉树根结点
 * @param seqTree
 * @return 根结点
 */
char getSeqBinaryTreeRootNode(SeqTree seqTree);

/**
 * 获取二叉树结点个数
 * @param seqTree
 * @return 结点总数
 */
int getSeqBinaryTreeNodes(const SeqTree seqTree);

/**
 * 获取二叉树深度
 * @param seqTree
 * @return 深度
 */
int getSeqBinaryTreeDepth(const SeqTree seqTree);

#endif //BINARY_TREE_SEQBINARYTREE_H
