/**
 * 图的数据模型
 * Created by Rui on 2022/6/16.
 */

#ifndef GRAPH_GRAPHMODEL_H
#define GRAPH_GRAPHMODEL_H

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100  // 最大定点数
#define VISITED 1   // 已访问
#define UN_VISITED 0    // 未访问

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 图的类型枚举
 */
typedef enum {
    UNDIGRAPH,  // 无向图
    DIGRAPH,    // 无向图
    UNDINET,    // 无向网
    DINET       // 有向网
} GraphType;

typedef char * VerTex;    // 定点数据类型为字符串，使用时需要分配数据类型
typedef int Status; // 返回类型

/**
 * 保存每个结点的访问状态
 * 0-未访问
 * 1-已访问
 */
int visited[MAX_VERTEX];

#endif //GRAPH_GRAPHMODEL_H
