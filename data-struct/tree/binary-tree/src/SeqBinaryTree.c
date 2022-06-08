//
// Created by Rui on 2022/6/8.
//
#include "../head/SeqBinaryTree/SeqBinaryTree.h"

void initSeqBinaryTree(SeqTree seqTree) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        seqTree[i] = '\0';
    }
}

void createSeqBinaryTree(char *seqTree, int index) {
    char ch;
    ch = getchar();
    fflush(stdin);
    if (ch == '^') {
        // 标识结束当前节点的输入
        seqTree[index] = '\0';
        return;
    }
    seqTree[index] = ch;
    // 需要输入左子树或右子树
    printf("左孩子结点:");
    createSeqBinaryTree(seqTree, index * 2 + 1);
    printf("右孩子结点:");
    createSeqBinaryTree(seqTree, index * 2 + 2);
}

char getSeqBinaryTreeRootNode(SeqTree seqTree) {
    return seqTree[0];
}

int getSeqBinaryTreeNodes(const SeqTree seqTree)
{
    int count;
    for (count = MAX_SIZE; count >= 1; count--) {
        if (seqTree[count - 1] != '\0') {
            break;
        }
    }
    return count;
}

int getSeqBinaryTreeDepth(const SeqTree seqTree) {
    // 深度为 k 的二叉树最多有 2^k - 1 个结点
    int depth = 0;
    int nodes = getSeqBinaryTreeNodes(seqTree);
    while ((int) pow(2, depth) - 1 < nodes) {
        depth++;
    }
    return depth;
}