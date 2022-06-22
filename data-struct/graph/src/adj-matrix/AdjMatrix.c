/**
 * 邻接矩阵
 * 无向图的特点
 * 1. 无向图的邻接矩阵是对称的
 * 2. 顶点 i 的度 = 第 i 行（列）中 1 的个数
 * Created by Rui on 2022/6/16.
 */
#include "../../head/adj-matrix/AdjMatrix.h"

Status createUDG(AdjMatrixGraph *graph) {
    graph->type = UNDIGRAPH;    // 设置图的类型为无向图
    printf("请输入无向图的顶点数:");
    scanf("%d", &graph->verTexNum);
    printf("请输入无向图弧(边)数:");
    scanf("%d", &graph->arcNum);
    printf("依次输入顶点信息:\n");
    for (int i = 0; i < graph->verTexNum; ++i) {
        graph->verTex[i] = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点 %d:", i + 1);
        scanf("%s", graph->verTex[i]);
    }
    // 初始化邻接矩阵，所有边的权值为 0
    for (int i = 0; i < graph->verTexNum; ++i) {
        for (int j = 0; j < graph->verTexNum; ++j) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    printf("请输入顶点和领接顶点信息构建邻接矩阵\n");
    for (int i = 0; i < graph->arcNum; ++i) {
        VerTex verTex1 = (VerTex) malloc(sizeof(char) * 10);
        VerTex verTex2 = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点:");
        scanf("%s", verTex1);
        printf("邻接点:");
        scanf("%s", verTex2);
        // 分别获取两个顶点在数组中的下标
        int x = locateVerText(graph, verTex1);
        int y = locateVerText(graph, verTex2);
        if (x == -1 || y == -1) {
            return ERROR;
        }
        /*
         * 无向图在邻接矩阵对称
         */
        graph->adjMatrix[x][y] = 1;
        graph->adjMatrix[y][x] = graph->adjMatrix[x][y];
        free(verTex1);
        free(verTex2);
    }
    return OK;
}

Status createDG(AdjMatrixGraph *graph) {
    graph->type = DIGRAPH;    // 设置图的类型为有向图
    printf("请输入有向图的顶点数:");
    scanf("%d", &graph->verTexNum);
    printf("请输入有向图弧(边)数:");
    scanf("%d", &graph->arcNum);
    printf("依次输入顶点信息:\n");
    for (int i = 0; i < graph->verTexNum; ++i) {
        graph->verTex[i] = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点 %d:", i + 1);
        scanf("%s", graph->verTex[i]);
    }
    // 初始化邻接矩阵，所有边的权值为 0
    for (int i = 0; i < graph->verTexNum; ++i) {
        for (int j = 0; j < graph->verTexNum; ++j) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    printf("请输入顶点和领接顶点信息构建邻接矩阵\n");
    for (int i = 0; i < graph->arcNum; ++i) {
        VerTex verTex1 = (VerTex) malloc(sizeof(char) * 10);
        VerTex verTex2 = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点:");
        scanf("%s", verTex1);
        printf("邻接点:");
        scanf("%s", verTex2);
        // 分别获取两个顶点在数组中的下标
        int x = locateVerText(graph, verTex1);
        int y = locateVerText(graph, verTex2);
        if (x == -1 || y == -1) {
            return ERROR;
        }
        graph->adjMatrix[x][y] = 1;
        free(verTex1);
        free(verTex2);
    }
    return OK;
}

Status createDN(AdjMatrixGraph *graph) {
    graph->type = DINET;    // 设置图的类型为有向网
    printf("请输入有向网的顶点数:");
    scanf("%d", &graph->verTexNum);
    printf("请输入有向网弧(边)数:");
    scanf("%d", &graph->arcNum);
    printf("依次输入顶点信息:\n");
    for (int i = 0; i < graph->verTexNum; ++i) {
        graph->verTex[i] = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点 %d:", i + 1);
        scanf("%s", graph->verTex[i]);
    }
    // 初始化邻接矩阵，所有边的权值为 0
    for (int i = 0; i < graph->verTexNum; ++i) {
        for (int j = 0; j < graph->verTexNum; ++j) {
            graph->adjMatrix[i][j] = INT16_MAX; // 使用 INT16_MAX 作为无限大
        }
    }
    printf("请输入顶点和领接顶点信息构建邻接矩阵\n");
    for (int i = 0; i < graph->arcNum; ++i) {
        VerTex verTex1 = (VerTex) malloc(sizeof(char) * 10);
        VerTex verTex2 = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点:");
        scanf("%s", verTex1);
        printf("邻接点:");
        scanf("%s", verTex2);
        // 分别获取两个顶点在数组中的下标
        int x = locateVerText(graph, verTex1);
        int y = locateVerText(graph, verTex2);
        if (x == -1 || y == -1) {
            return ERROR;
        }
        int weight;
        printf("请输入权值:");
        scanf("%d", &weight);
        graph->adjMatrix[x][y] = weight;
        free(verTex1);
        free(verTex2);
    }
    return OK;
}

int locateVerText(AdjMatrixGraph *graph, VerTex verTex) {
    int index = 0;
    while (index < graph->verTexNum) {
        if (strcmp(graph->verTex[index], verTex) == 0) {
            break;
        }
        index++;
    }
    return index == graph->verTexNum ? -1 : index;
}

/** 邻接矩阵的深度优先遍历 */
void adjMatrixGraphDFS(AdjMatrixGraph G){
    //初始化状态数组
    for(int i = 0; i < G.verTexNum; i++){
        visited[i] = UN_VISITED;     //初始状态设置为未访问
    }
    //DFS遍历
    for(int i = 0; i < G.verTexNum; i++){
        if(!visited[i]){//如果某个顶点未访问
            //调用遍历函数
            adjMatrixDFS(G, i);
        }
    }
}

/** 深度优先搜索的核心算法，index为深度搜索的某个顶点下标 */
void adjMatrixDFS(AdjMatrixGraph G, int index){
    printf(" -> %s", G.verTex[index]);     //访问当前顶点
    visited[index] = VISITED;               //更改当前顶点的访问状态
    for(int i = firstAdjVerTex(G, G.verTex[index]); i;
        i = secondAdjVerTex(G, G.verTex[index], G.verTex[i])){
        if(!visited[i]){
            adjMatrixDFS(G, i);  //如果没有访问过，就继续递归调用访问
        }
    }
}

/** 返回顶点vex所在行中的第一个邻接点下标 */
int firstAdjVerTex(AdjMatrixGraph G, VerTex vex){
    int i = locateVerText(&G, vex);         //找到顶点vex在顶点数组中的下标
    if(i == -1) return ERROR;
    int defaultWeight;                  //默认权重
    defaultWeight = G.type <= 1 ? 0 : INT16_MAX;          //图/网
    //搜索图的邻接矩阵中与顶点vex的第一个邻接点下标
    for(int j = i + 1; j < G.verTexNum; j++){
        if(G.adjMatrix[i][j] != defaultWeight){
            return j;
        }
    }
    return 0;
}

/** 返回与顶点vex1邻接的另一个邻接点，没有就返回0 */
int secondAdjVerTex(AdjMatrixGraph G, VerTex vex1, VerTex vex2){
    int index1 = locateVerText(&G, vex1);
    int index2 = locateVerText(&G, vex2);
    if(index1 == -1 || index2 == -1) return 0;
    int defaultWeight;
    defaultWeight = G.type <= 1 ? 0 : INT16_MAX;
    for(int i = index2 + 1; i< G.verTexNum; i++){
        if(G.adjMatrix[index1][i] != defaultWeight){
            return i;
        }
    }
    return 0;
}

/** 广度优先搜索的核心算法 - index为广度优先搜索的某个顶点下标 */
void adjMatrixBFS(AdjMatrixGraph G, int index){
    printf(" -> %s", G.verTex[index]);
    visited[index] = VISITED;               //设置顶点状态为已访问

    LinkedQueue queue;
    initLinkedQueue(&queue);
    //将当前顶点入队
    enqueue(&queue, G.verTex[index]);
    while(isLinkedQueueEmpty(&queue)){
        //取出队头元素，遍历队头顶点的所有邻接点
        VerTex vex;                     //取出的队头顶点
        dequeue(&queue, &vex);
        for(int i = firstAdjVerTex(G, vex); i; i = secondAdjVerTex(G, vex, G.verTex[i])){
            if(!visited[i]){
                printf(" -> %s", G.verTex[i]);
                visited[i] = VISITED;        //设置顶点状态为已访问
                enqueue(&queue, G.verTex[i]);
            }
        }
    }
}

/** 邻接矩阵的广度优先遍历 */
void adjMatrixGraphBFS(AdjMatrixGraph G){
    //初始化状态数组
    for(int i = 0; i < G.verTexNum; i++){
        visited[i] = UN_VISITED;
    }
    //循环遍历每个顶点
    for(int i = 0; i < G.verTexNum; i++){
        if(!visited[i]){
            adjMatrixBFS(G, i);
        }
    }
}


void testAdjMatrix(GraphType type) {
    AdjMatrixGraph graph;
    Status status = ERROR;
    if (type == UNDIGRAPH) {
        // 创建无向图
        status = createUDG(&graph);
    } else if (type == DIGRAPH) {
        // 创建有向图
        status = createDG(&graph);
    } else if (type == DINET) {
        // 创建有向网
        status = createDN(&graph);
    }
    if (status == ERROR) {
        printf("创建失败\n");
        return;
    }
    printf("打印邻接矩阵\n");
    printf("\t");
    for (int i = 0; i < graph.verTexNum; ++i) {
        printf("\t%s", graph.verTex[i]);
    }
    printf("\n");
    for (int i = 0; i < graph.verTexNum; ++i) {
        printf("\t%s", graph.verTex[i]);
        for (int j = 0; j < graph.verTexNum; ++j) {
            if (graph.adjMatrix[i][j] == INT16_MAX) {
                printf("\t∞");
            } else {
                printf("\t%d", graph.adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n深度优先遍历 DFS\n");
    adjMatrixGraphDFS(graph);
    printf("\n广度优先遍历 BFS\n");
    adjMatrixGraphBFS(graph);
}
