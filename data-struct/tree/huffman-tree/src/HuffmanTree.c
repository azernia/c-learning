/**
 * Created by Rui on 2022/6/14.
 */

#include "../head/HuffmanTree.h"

void createHuffTree(HuffNode *nodeArray, int length) {
    if (length <= 1) {
        // 没有结点
        return;
    }
    sortHuffmanCode(nodeArray, length);
    // 构建以 nodeArrays 数组最后两位结点组成的父节点
    HuffNode parent;
    lefts[length] = nodeArray[length - 1];
    rights[length] = nodeArray[length - 2];
    parent.weight = lefts[length].weight + rights[length].weight;
    parent.left = &lefts[length];
    parent.right = &rights[length];
    // parent 的 data 不用赋值
    // 将倒数第二位替换为 parent 结点，数组长度 - 1，递归创建
    nodeArray[length - 2] = parent;
    createHuffTree(nodeArray, length - 1);
}

void sortHuffmanCode(HuffNode *nodeArray, int length) {
    HuffNode tempNode;
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - 1 - i; ++j) {
            if(nodeArray[j].weight < nodeArray[ j + 1].weight) {
                tempNode = nodeArray[j];
                nodeArray[j] = nodeArray[j + 1];
                nodeArray[j + 1] = tempNode;
            }
        }
    }
}

void coding(HuffNode *node, char *tempArray, int index) {
    if (!node) {
        return;
    }
    // 处理叶结点-所有字符结点都为叶结点
    if (node->left == NULL && node->right == NULL) {
        tempArray[index] = '\0';    // {'0', '0', '\0'}
        // 复制到编码数组中
        strcpy(code[(int) node->data], tempArray);
        return;
    }
    // 左分支 0 右分支 1
    tempArray[index] = '0';
    coding(node->left, tempArray, index + 1);
    tempArray[index] = '1';
    coding(node->right, tempArray, index + 1);
}

HuffNode *decoding(HuffNode *node, int flag) {
    if (flag == 0) {
        return node->left;
    }
    if (flag == 1) {
        return node->right;
    }
    return NULL;
}
