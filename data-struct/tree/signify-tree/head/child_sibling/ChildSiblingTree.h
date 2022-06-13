/**
 * 孩子兄弟表示法
 * 将一般的树结构转换为二叉树
 * Created by Rui on 2022/6/13.
 */

#ifndef SIGNIFY_TREE_CHILDSIBLINGTREE_H
#define SIGNIFY_TREE_CHILDSIBLINGTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common/Element.h"

typedef struct CSNode {
    ElementType data;
    struct CSNode *child;  // 孩子结点
    struct CSNode *sibling;    // 兄弟结点
} CSNode, *CSTree;

/**
 * 初始化空树
 * @param node
 */
void initCSTree(CSTree *tree);

/**
 * 构造树
 * @param node
 */
void createCSTree(CSNode **node);

/**
 * 前序遍历
 * @param csTree
 */
void preOrderCSTreeTraverse(CSNode *node);

/**
 * 获取树的深度
 * 使用了层序遍历
 * @param tree
 */
int getCSTreeDepth(CSTree tree);

void testCSTree();

#endif //SIGNIFY_TREE_CHILDSIBLINGTREE_H
