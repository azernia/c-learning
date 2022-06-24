/**
 * Created by Rui on 2022/6/24.
 */

#include "../head/BinarySortTree.h"

void init(BinarySortTree *tree) {
    *tree = (BinarySortTree) malloc(sizeof(BinarySortTreeNode));
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    // length = 0;
}

void create(BinarySortTree *tree, SequenceList *list, int low, int high) {
    if (low > high) {
        return;
    }
    int mid = (low + high) / 2;
    if (!(*tree)) {
        // 树为空重新初始化
        init(tree);
    }
    (*tree)->data = list->data[mid];
    // 递归创建左子树
    create(&((*tree)->left), list, low, mid - 1);
    // 递归创建右子树
    create(&((*tree)->right), list, mid + 1, high);
}

void inOrderTraverse(BinarySortTreeNode *treeNode) {
    if (treeNode) {
        inOrderTraverse(treeNode->left);
        printf("%d\t%s\n", treeNode->data.key, treeNode->data.value);
        inOrderTraverse(treeNode->right);
    }
}

void search(BinarySortTree tree, int key, BinarySortTreeNode **node) {
    if (!tree || key == tree->data.key) {
        *node = tree;
    } else if (key < tree->data.key) {
        search(tree->left, key, node);
    } else {
        search(tree->right, key, node);
    }
}

void insert(BinarySortTree *tree, ElementType elementType) {
    if (*tree == NULL) {
        BinarySortTreeNode *newNode = (BinarySortTreeNode *) malloc(sizeof(BinarySortTreeNode));
        newNode->data = elementType;
        newNode->left = newNode->right = NULL;
        *tree = newNode;
    } else if (elementType.key < (*tree)->data.key) {
        insert(&((*tree)->left), elementType);
    } else if(elementType.key > (*tree)->data.key) {
        insert(&((*tree)->right), elementType);
    }
}

void test() {
    SequenceList list;
    initSeqList(&list);
    int keys[] = {
            10, 39, 22, 78, 3, 7, 48
    };
    char *values[] = {
            "刀锋女王","盖伦","阿尔萨斯","吉姆雷诺","劳拉克劳馥","大黄蜂","擎天柱"
    };
    int length = sizeof keys / sizeof keys[0];
    for (int i = 1; i <= length; ++i) {
        list.data[i].key = keys[i - 1];
        list.data[i].value = (char *) malloc(sizeof(char ) * MAX_INFO_SIZE);
        strcpy(list.data[i].value, values[i - 1]);
        list.length++;
    }
    printf("初始化顺序表\n");
    printSeqList(list);
    printf("\n冒泡排序\n");
    bubbleSort(&list);
    printSeqList(list);
    BinarySortTree tree;
    init(&tree);
    create(&tree, &list, 1, list.length);
    printf("中序遍历\n");
    inOrderTraverse(tree);
    ElementType elementType;
    elementType.key = 8;
    elementType.value = (char *) malloc(sizeof(char) * MAX_INFO_SIZE);
    strcpy(elementType.value, "楚留香");
    BinarySortTreeNode *node = (BinarySortTreeNode *) malloc(sizeof(BinarySortTreeNode));
    search(tree, elementType.key, &node);
    if (node) {
        printf("查找结果：%d\t%s\n", node->data.key, node->data.value);
    } else {
        printf("未找到");
        insert(&tree, elementType);
    }
    printf("中序遍历\n");
    inOrderTraverse(tree);
    free(node);
}
