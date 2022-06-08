#include <stdio.h>
#include "../head/SeqBinaryTree/SeqBinaryTree.h"

int main() {
    SeqTree seqTree;
    initSeqBinaryTree(seqTree);
    printf("请输入根结点:");
    createSeqBinaryTree(seqTree, 0);
    for (int i = 0; i < 15; ++i) {
        printf("%c", seqTree[i]);
    }
    printf("\n");
    printf("总结点数:%d\n", getSeqBinaryTreeNodes(seqTree));
    printf("根结点:%c\n", getSeqBinaryTreeRootNode(seqTree));
    printf("深度:%d\n", getSeqBinaryTreeDepth(seqTree));
    return 0;
}
