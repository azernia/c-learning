#include <stdio.h>
#include "../head/SeqBinaryTree/SeqBinaryTree.h"
#include "../head/LinkedBinaryTree/LinkedBinaryTree.h"

int main() {
    BiTree *tree = (BiTree *) malloc(sizeof (BiTree));
    initBiTree(tree);
    tree->root = (BiNode *) malloc(sizeof (BiNode));
//    printf("请输入根结点:");
//    createBiTree(tree->root);
    createBiTreeTest(tree->root);
    printf("前序遍历：\n");
    preOrderTraverse(tree->root);
    printf("\n");
    printf("中序遍历：\n");
    inOrderTraverse(tree->root);
    printf("\n");
    printf("非递归中序遍历：\n");
    inorderTraverseByStack(tree->root);
    printf("\n");
    printf("后序遍历\n");
    postOrderTraverse(tree->root);
    printf("\n");
    printf("层序遍历\n");
    levelOrderTraverse(tree->root);
    free(tree->root);
    free(tree);
    return 0;
//    SeqTree seqTree;
//    initSeqBinaryTree(seqTree);
//    printf("请输入根结点:");
//    createSeqBinaryTree(seqTree, 0);
//    for (int i = 0; i < 15; ++i) {
//        printf("%c", seqTree[i]);
//    }
//    printf("\n");
//    printf("总结点数:%d\n", getSeqBinaryTreeNodes(seqTree));
//    printf("根结点:%c\n", getSeqBinaryTreeRootNode(seqTree));
//    printf("深度:%d\n", getSeqBinaryTreeDepth(seqTree));
//    return 0;
}
