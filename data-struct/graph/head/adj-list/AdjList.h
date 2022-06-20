/**
 * 图的邻接表表示法
 * Created by Rui on 2022/6/17.
 */

#ifndef GRAPH_ADJLIST_H
#define GRAPH_ADJLIST_H

#include "../common/GraphModel.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common/GraphModel.h"


/** 边/弧的结点 */
typedef struct node{
    int adjVex;                     //该边指向这条边邻接点的下标
    struct node * nextEdge;         //指向下一条边结点的指针
    struct node * nextArc;          //指向下一个弧结点的指针
    int weight;                 //权重
}EdgeNode, ArcNode;

/** 顶点结点 */
typedef struct vexNode{
    VerTex vex;                 //顶点值
    EdgeNode * firstEdge;           //指向第一条边的指针
    ArcNode * firstArc;             //指向第一条弧的指针
}VNode, AdjList[MAX_VERTEX];

/** 邻接表实现的图结构 */
typedef struct adjGraph{
    AdjList vexes;                  //顶点数组
    int vexCount;                   //顶点数量
    int edgeCount;                  //图的边数
    int arcCount;                   //图的弧数
    GraphType type;                 //图的类型
}AdjListGraph;

/**
 * 通过领接表创建无向图
 * @param graph
 * @return
 */
Status createUDGAdjList(AdjListGraph *graph);

/**
 * 通过邻接表创建有向图
 * @param graph
 * @return
 */
Status createDGAdjList(AdjListGraph *graph);

/**
 * 通过邻接表创建有向网
 * @param graph
 * @return
 */
Status createDNAdjList(AdjListGraph *graph);

/**
 * 返回顶点 VerTex 在顶点数组中的下标，没找到返回 -1
 * @param graph
 * @param verTex
 * @return
 */
int locateVerTextAdjList(AdjListGraph *graph, VerTex verTex);

void testAdjList(GraphType type);

#endif //GRAPH_ADJLIST_H
