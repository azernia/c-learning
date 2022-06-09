//
// Created by Rui on 2022/6/9.
//

#ifndef BINARY_TREE_LINKEDBINARYTREE_H
#define BINARY_TREE_LINKEDBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "LinkedBinaryTreeData.h"
#include "../Stack/LinkedStack.h"
#include "../Queue/Queue.h"

/**
 * 初始化空二叉树
 * @param tree
 */
void initBiTree(BiTree *tree);

/**
 * 构造二叉树
 * 需先分配内存
 * @param node
 * @return 返回值为0时为失败
 */
int createBiTree(BiNode *node);

/**
 * 构造二叉树-测试
 * 需先分配内存
 * @param node
 * @return 返回值为0时为失败
 */
int createBiTreeTest(BiNode *node);

/**
 * 前序遍历二叉树
 * 根左右
 * @param node
 */
void preOrderTraverse(BiNode *node);

/**
 * 中序遍历二叉树
 * 左根右
 * @param node
 */
void inOrderTraverse(BiNode *node);

/**
 * 后续遍历二叉树
 * 左右根
 * @param node
 */
void postOrderTraverse(BiNode *node);

/**
 * 非递归方式的中序遍历
 * @param node
 */
void inorderTraverseByStack(BiNode *node);

/**
 * 层序遍历
 * 不需要递归，需要队列
 * @param node
 */
void levelOrderTraverse(BiNode *node);

#endif //BINARY_TREE_LINKEDBINARYTREE_H
