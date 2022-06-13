/**
 * Created by Rui on 2022/6/13.
 */
#include "../head/queue/Queue.h"

static int id = 0;

void initCSTree(CSTree *tree) {
    // 二级指针可在函数内初始化
    *tree = (CSTree) malloc(sizeof (CSTree));
    (*tree)->child = NULL;
    (*tree)->sibling = NULL;
}

void createCSTree(CSNode **node) {
    char inputName[255];
    gets(inputName);
    // 判断用户是否输入回车
    if (strcmp(inputName, "\0") == 0) {
        return;
    }
    if (*node == NULL) {
        *node = (CSNode *) malloc(sizeof (CSNode));
        (*node)->child = NULL;
        (*node)->sibling = NULL;
    }
    // 赋值
    (*node)->data.id = ++id;
    strcpy((*node)->data.name, inputName);
    // 分别输入孩子结点和兄弟结点
    printf("请输入孩子结点:");
    createCSTree(&((*node)->child));
    printf("请输入兄弟结点:");
    createCSTree(&((*node)->sibling));
}

void preOrderCSTreeTraverse(CSNode *node) {
    if (node != NULL) {
        printf("[%d, %s]", node->data.id, node->data.name);
        CSNode *child = node->child;
        preOrderCSTreeTraverse(child);
        while (child) {
            child = child->sibling;
            preOrderCSTreeTraverse(child);
        }
    }
}

void testCSTree() {
    CSTree tree;
    initCSTree(&tree);
    printf("根结点:");
    createCSTree(&tree);
    printf("先序遍历:\n");
    preOrderCSTreeTraverse(tree);
    printf("层序遍历:\n");
    getCSTreeDepth(tree);
}

int getCSTreeDepth(CSTree tree) {
    LinkedQueue queue;
    initLinkedQueue(&queue);
    enqueue(&queue, tree);  // 根结点入队
    int zOrder = 1;     // 层号
    printf("\n第%d层", zOrder);
    CSNode *last = tree;    // 每轮遍历时的最后一个结点
    CSNode *lastChild = tree;   // 每次遍历时的最后一个子结点
    while (!isLinkedQueueEmpty(&queue)) {
        CSNode *node = dequeue(&queue); // 出队
        printf("[%d, %s]", node->data.id, node->data.name);
        // 将当前出队结点的所有子结点入队，等待出队打印
        CSNode *tempNode = node->child;
        while (tempNode) {
            enqueue(&queue, tempNode);
            lastChild = tempNode;
            tempNode = tempNode->sibling;
        }
        // 所有孩子结点都出队了，并且下一层还有孩子结点，就进入下一层
        if (last == node && !isLinkedQueueEmpty(&queue)) {
            zOrder++;
            printf("\n第%d层", zOrder);
            last = lastChild;
        }
    }
    return zOrder;
}