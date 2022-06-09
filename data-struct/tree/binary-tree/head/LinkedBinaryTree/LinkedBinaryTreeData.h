/**
 * 二叉树链式存储
 * 在有 n 个结点的二叉链表中有 n+1 个空链
 * Created by Rui on 2022/6/9.
 */

#ifndef BINARY_TREE_LINKEDBINARYTREEDATA_H
#define BINARY_TREE_LINKEDBINARYTREEDATA_H

typedef char ElementType;

typedef struct BiNode {
    ElementType data;   // 数据域
    struct BiNode *lChild;  // 左子树
    struct BiNode *rChild;  // 右子树
} BiNode;

typedef struct BiTree {
    BiNode *root;   // 根结点
    int count;  // 结点总数
    int depth;  // 深度
    int diameter;   // 从叶结点到叶结点的最长路径
} BiTree;

#endif //BINARY_TREE_LINKEDBINARYTREEDATA_H
