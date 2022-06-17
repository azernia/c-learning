/**
 * 邻接矩阵（数组）
 * Created by Rui on 2022/6/16.
 */

#ifndef GRAPH_ADJMATRIX_H
#define GRAPH_ADJMATRIX_H

#include "../common/GraphModel.h"

/**
 * 邻接矩阵表示
 */
typedef struct AdjMatrixGraph {
    VerTex verTex[MAX_VERTEX];  // 顶点数组
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];  // 领接矩阵
    int verTexNum;  // 定点数
    int arcNum; // 弧
    GraphType type; //图的类型
}AdjMatrixGraph;

/**
 * 使用邻接矩阵创建无向图
 * @param graph 操作的图
 * @return
 */
Status createUDG(AdjMatrixGraph *graph);

/**
 * 使用邻接矩阵创建有向图
 * @param graph 操作的图
 * @return
 */
Status createDG(AdjMatrixGraph *graph);

/**
 * 使用邻接矩阵创建有向网
 * @param graph
 * @return
 */
Status createDN(AdjMatrixGraph *graph);

/**
 * 获取顶点在数组中的下标
 * @param graph 图
 * @param verTex 顶点
 * @return 返回顶点的下标 0 开始，不存在返回 -1
 */
int locateVerText(AdjMatrixGraph *graph, VerTex verTex);

/**
 * 测试邻接矩阵
 */
void testAdjMatrix(GraphType graphType);

#endif //GRAPH_ADJMATRIX_H
