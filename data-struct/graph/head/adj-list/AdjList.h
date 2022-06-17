/**
 * 图的邻接表表示法
 * Created by Rui on 2022/6/17.
 */

#ifndef GRAPH_ADJLIST_H
#define GRAPH_ADJLIST_H

#include "../common/GraphModel.h"

/**
 * 弧或边的结点
 */
typedef struct Node {
    int adjVex; // 指向邻接点的下标
    struct Node * next; // 指向下一结点的指针
    int weight; // 权重
} EdgeNode, ArcNode;

/**
 * 顶点结点
 */
typedef struct VerTexNode {
      VerTex verTex;    // 顶点的取值
      union {
          EdgeNode *firstEdge;  // 指向第一条边的指针
          ArcNode *firstArc;    // 指向第一条弧的指针
      };
} VerTexNode, AdjList[MAX_VERTEX];

/**
 * 邻接表实现图结构
 */
typedef struct AdjListGraph {
    AdjList adjList;    // 邻接表顶点数组
    int vexNum;
    union {
        int edgeNum;    // 边数
        int arcNum;     // 弧数
    };
    GraphType type; // 图的类型
} AdjListGraph;

/**
 * 通过领接表创建无向图
 * @param graph
 * @return
 */
Status createUDGAdjList(AdjListGraph *graph);

/**
 * 返回顶点 VerTex 在顶点数组中的下标，没找到返回 -1
 * @param graph
 * @param verTex
 * @return
 */
int locateVerTextAdjList(AdjListGraph *graph, VerTex verTex);

void testAdjList(GraphType type);

#endif //GRAPH_ADJLIST_H
