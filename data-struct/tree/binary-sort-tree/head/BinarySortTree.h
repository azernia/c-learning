/**
 * Created by Rui on 2022/6/24.
 */

#ifndef BINARY_SORT_TREE_BINARYSORTTREE_H
#define BINARY_SORT_TREE_BINARYSORTTREE_H

#include "SequneceList.h"

/**
 * 定义树节点和树
 */
typedef struct BinarySortTreeNode{
    ElementType data;   // 数据域
    struct BinarySortTreeNode *left;    // 左子树
    struct BinarySortTreeNode *right;   // 右子树
    // 结点总数
} BinarySortTreeNode, *BinarySortTree;

/**
 * 初始化
 * @param tree
 */
void init(BinarySortTree *tree);

/**
 * 创建二叉排序树
 * @param tree
 * @param list 升序排序后的顺序表
 * @param low 最小值位置
 * @param high 最大值位置
 */
void create(BinarySortTree *tree, SequenceList *list, int low, int high);

/**
 * 中序遍历
 * @param tree
 */
void inOrderTraverse(BinarySortTreeNode *treeNode);

/**
 * 查找
 * @param tree
 * @param key
 * @param node
 */
void search(BinarySortTree tree, int key, BinarySortTreeNode **node);

/**
 * 插入结点
 * @param tree
 * @param elementType
 */
void insert(BinarySortTree *tree, ElementType elementType);

/**
 * 测试
 */
void test();

#endif //BINARY_SORT_TREE_BINARYSORTTREE_H
