/**
 * Created by Rui on 2022/6/10.
 */
#include "../head/parent/ParentTree.h"

void initPTree(PTree *pTree) {
    pTree->root = -1;
    pTree->length = 0;
}

void createPTree(PTree *pTree) {
    printf("请输入结点个数：");
    scanf("%d", &(pTree->length));
    printf("请输入结点的值及双亲序号：\n");
    pTree->root = 0;
    for (int i = pTree->root; i < pTree->length; ++i) {
        ElementType *data = (ElementType *) malloc(sizeof (ElementType));
        int parentPosition;
        data->id = i + 1;
        printf("请输入第%d个结点的值：", i + 1);
        scanf("%s", data->name);
        pTree->node[i].data = *data;
        printf("请输入第%d个结点的双亲位置：", i + 1);
        scanf("%d", &parentPosition);
        // 为结点赋值
        assignPTree(&(pTree->node[i]), parentPosition, *data);
    }
    pTree->node[pTree->root].parent = -1;   // 根结点双亲设置为-1
    printf("创建成功，结点数为：%d\n", pTree->length);
    for(int i = 0; i < pTree->length; i++){
        printf("[%d, %s, %d] ", pTree->node[i].data.id, pTree->node[i].data.name, pTree->node[i].parent);
    }
}

void assignPTree(PTreeNode *node, int parent, ElementType data) {
    node->data = data;
    node->parent = parent;
}

int isPTreeEmpty(PTree *pTree) {
    return pTree->length == 0;
}

int getPTreeDepth(PTree *pTree) {
    if (isPTreeEmpty(pTree)) {
        return 0;
    }
    int max = 0;    // 最大深度
    for (int i = pTree->root; i < pTree->length; ++i) {
        int height = 1; // 根结点开始高度至少为1
        int node = pTree->node[i].parent;
        while (node != -1) {
            // 不为根结点
            node = pTree->node[node].parent;    // 通过双亲的位置找到双亲结点，并记录下双亲
            height++;
        }
        if (max < height) {
            max = height;
        }
    }
    return max;
}

void levelOrderTraverse(PTree *pTree) {
    int level = 1;
    printf("第%d层：", level);
    printf("[%d, %s] ", pTree->node[pTree->root].data.id, pTree->node[pTree->root].data.name);
    level++;
    int depth = getPTreeDepth(pTree);
    //遍历根结点以后的每个结点
    printf("\n第%d层：", level);
    for(int i = 0; i < pTree->length; i++){
        //查找第i个结点的所有孩子结点(注意：存储顺序要求双亲位置一定在孩子前面)
        int flag = 0;       //换行标识
        for(int j = i + 1; j < pTree->length; j++){
            if(pTree->node[j].parent == i){//双亲位置==i：即找到位置i结点的孩子结点
                printf("[%d, %s] ", pTree->node[j].data.id, pTree->node[j].data.name);
                flag = 1;
            }
        }
        if(flag == 1 && level < depth){
            level++;
            printf("\n第%d层：", level);
        }
    }
}

void destroyPTree(PTree *pTree) {
    if (pTree) {
        free(pTree);
    }
}

void testPTree() {
    PTree tree;
    initPTree(&tree);
//  测试输入顺序：
//请输入结点个数：7
//请输入结点的值及双亲序号：
//请输入第1个结点的值：A
//请输入第1个结点的双亲位置：-1
//请输入第2个结点的值：B
//请输入第2个结点的双亲位置：0
//请输入第3个结点的值：C
//请输入第3个结点的双亲位置：0
//请输入第4个结点的值：D
//请输入第4个结点的双亲位置：1
//请输入第5个结点的值：E
//请输入第5个结点的双亲位置：1
//请输入第6个结点的值：F
//请输入第6个结点的双亲位置：2
//请输入第7个结点的值：G
//请输入第7个结点的双亲位置：2
//[1, A, -1] [2, B, 0] [3, C, 0] [4, D, 1] [5, E, 1] [6, F, 2] [7, G, 2]
//层序遍历：
//第1层：[1, A]
//第2层：[2, B] [3, C]
//第3层：[4, D] [5, E] [6, F] [7, G]
    createPTree(&tree);
    printf("深度：%d\n", getPTreeDepth(&tree));
    printf("层序遍历：\n");
    levelOrderTraverse(&tree);
}
