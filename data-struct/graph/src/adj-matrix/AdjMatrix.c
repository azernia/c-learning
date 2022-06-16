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
        graph->verTex[i] = (VerTex) malloc(sizeof (char) * 10);
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
        VerTex  verTex1 = (VerTex) malloc(sizeof (char) * 10);
        VerTex  verTex2 = (VerTex) malloc(sizeof (char) * 10);
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

void testAdjMatrix(GraphType type) {
    if (type == UNDIGRAPH) {
        AdjMatrixGraph graph;
        // 创建无向图
        Status status = createUDG(&graph);
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
                printf("\t%d", graph.adjMatrix[i][j]);
            }
            printf("\n");
        }
        return;
    }
    if (type == DIGRAPH) {

    }
}
