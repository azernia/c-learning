//
// Created by Rui on 2022/6/9.
//
#include "../head/LinkedBinaryTree/LinkedBinaryTree.h"

char nodes[] = {
        'A',
        'B',
        'D',
        '\n',
        '\n',
        'E',
        '\n',
        '\n',
        'C',
        'F',
        '\n',
        '\n',
        'G',
        '\n',
        '\n'
};

static int nodeIndex = 0;

void initBiTree(BiTree *tree) {
    tree->root = NULL;
    tree->depth = 0;
    tree->count = 0;
    tree->diameter = 0;
}

int createBiTree(BiNode *node) {
    if (!node) {
        return 0;
    }
    char nodeName = getchar();
    fflush(stdin);
    if (nodeName == '\n') {
        return 0;
    }
    // 创建当前节点
    node->data = nodeName;
    // 为输入左右节点做准备
    node->lChild = (BiNode *) malloc(sizeof (BiNode));
    if (!node->lChild) {
        printf("左节点内存分配失败\n");
        return 0;
    }
    node->rChild = (BiNode *) malloc(sizeof (BiNode));
    if (!node->rChild) {
        printf("右节点内存分配失败\n");
        return 0;
    }
    // 分别创建左子树右子树
    printf("左结点:");
    if (createBiTree(node->lChild) == 0) {
        // 不再创建结点
        free(node->lChild);
        node->lChild = NULL;
    }
    printf("右结点:");
    if (createBiTree(node->rChild) == 0) {
        free(node->rChild);
        node->rChild = NULL;
    }
    return 1;
}

void preOrderTraverse(BiNode *node) {
    if (node) {
        printf("%c", node->data);
        preOrderTraverse(node->lChild);
        preOrderTraverse(node->rChild);
    }
}

void inOrderTraverse(BiNode *node) {
    if (node) {
        inOrderTraverse(node->lChild);
        printf("%c", node->data);
        inOrderTraverse(node->rChild);
    }
}

void postOrderTraverse(BiNode *node) {
    if (node) {
        postOrderTraverse(node->lChild);
        postOrderTraverse(node->rChild);
        printf("%c", node->data);
    }
}

void inorderTraverseByStack(BiNode *node) {
    LinkedStack *stack = (LinkedStack *) malloc(sizeof (LinkedStack));
    initLinkedStack(stack);
    BiNode *treeNode = node;
    // 保存出栈的结点
    BiNode *currentNode = (BiNode *) malloc(sizeof (BiNode));
    // 临时指针确保释放内存
    BiNode *tempNode = currentNode;
    while (treeNode || !isEmpty(stack)) {
        if (treeNode) {
            push(stack, treeNode);
            treeNode = treeNode->lChild;
        } else {
            pop(stack, &currentNode);
            printf("%c", currentNode->data);
            treeNode = currentNode->rChild;
        }
    }
    destroy(stack);
    free(tempNode);
}

void levelOrderTraverse(BiNode *node) {
    LinkedQueue *queue = (LinkedQueue *) malloc(sizeof (LinkedQueue));
    initLinkedQueue(queue);
    enqueue(queue, node);
    while (!isLinkedQueueEmpty(queue)) {
        BiNode *treeNode = dequeue(queue);
        printf("%c", treeNode->data);
        if (treeNode->lChild) {
            enqueue(queue, treeNode->lChild);
        }
        if (treeNode->rChild) {
            enqueue(queue, treeNode->rChild);
        }
    }
}

int createBiTreeTest(BiNode *node) {
    if (!node) {
        return 0;
    }
    char nodeName = nodes[nodeIndex++];
    if (nodeName == '\n') {
        return 0;
    }
    // 创建当前节点
    node->data = nodeName;
    // 为输入左右节点做准备
    node->lChild = (BiNode *) malloc(sizeof (BiNode));
    if (!node->lChild) {
        printf("左节点内存分配失败\n");
        return 0;
    }
    node->rChild = (BiNode *) malloc(sizeof (BiNode));
    if (!node->rChild) {
        printf("右节点内存分配失败\n");
        return 0;
    }
    // 分别创建左子树右子树
    if (createBiTreeTest(node->lChild) == 0) {
        // 不再创建结点
        free(node->lChild);
        node->lChild = NULL;
    }
    if (createBiTreeTest(node->rChild) == 0) {
        free(node->rChild);
        node->rChild = NULL;
    }
    return 1;
}
