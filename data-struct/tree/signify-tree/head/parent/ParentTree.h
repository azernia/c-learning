/**
 * 树的双亲表示法
 * Created by Rui on 2022/6/10.
 */

#ifndef SIGNIFY_TREE_PARENTTREE_H
#define SIGNIFY_TREE_PARENTTREE_H

#include "../common/Element.h"

typedef struct PTreeNode {
    ElementType data;   // 数据域
    int parent; // 双亲位置下标
} PTreeNode;

typedef struct PTree {
    PTreeNode node[MAX_SIZE];   // 结点数组
    int root;   // 根的位置
    int length; // 数组长度，结点树
} PTree;

/**
 * 初始化树
 * @param pTree
 */
void initPTree(PTree *pTree);

/**
 * 创建树
 * @param pTree
 */
void createPTree(PTree *pTree);

/**
 * 为结点赋值
 * @param node
 * @param parent
 * @param data
 */
void assignPTree(PTreeNode *node, int parent, ElementType data);

/**
 * 判断树是否为空
 * @param pTree
 * @return
 */
int isPTreeEmpty(PTree *pTree);

/**
 * 获取树的深度
 * @param pTree
 * @return 树的深度
 */
int getPTreeDepth(PTree *pTree);

/**
 * 层序遍历树
 * @param pTree
 */
void levelOrderTraverse(PTree *pTree);

/**
 * 销毁树
 * @param pTree
 */
void destroyPTree(PTree *pTree);

/**
 * 测试函数
 */
void testPTree();

#endif //SIGNIFY_TREE_PARENTTREE_H
