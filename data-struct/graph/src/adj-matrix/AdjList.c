/**
 * Created by Rui on 2022/6/17.
 */

#include "../../head/adj-list/AdjList.h"

Status createUDGAdjList(AdjListGraph *graph) {
    graph->type = UNDIGRAPH;
    printf("请输入顶点数量:");
    scanf("%d", &graph->vexNum);
    printf("请输入边的数量:");
    scanf("%d", &graph->edgeNum);
    printf("请依次输入顶点信息\n");
    for (int i = 0; i < graph->vexNum; ++i) {
        graph->adjList[i].verTex = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点%d:", i + 1);
        scanf("%s", graph->adjList[i].verTex);
        // 初始化邻接表，将边置空
        graph->adjList[i].firstEdge = NULL;
    }
    printf("请输入顶点和邻接点信息，构建邻接表\n");
    for (int i = 0; i < graph->edgeNum; ++i) {
        VerTex verTex1 = (VerTex) malloc(sizeof(char) * 10);
        VerTex verTex2 = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点:");
        scanf("%s", verTex1);
        printf("邻接点:");
        scanf("%s", verTex2);
        int x = locateVerTextAdjList(graph, verTex1);
        int y = locateVerTextAdjList(graph, verTex2);
        if (x == -1 || y == -1) {
            free(verTex1);
            free(verTex2);
            return ERROR;
        }
        EdgeNode *edgeNode = (EdgeNode *) malloc(sizeof(EdgeNode));
        edgeNode->adjVex = x;
        edgeNode->next = graph->adjList[y].firstEdge;
        edgeNode->weight = 0;
        graph->adjList[y].firstEdge = edgeNode;
        edgeNode = (EdgeNode *) malloc(sizeof(EdgeNode));
        edgeNode->adjVex = y;
        edgeNode->next = graph->adjList[x].firstEdge;
        edgeNode->weight = 0;
        graph->adjList[x].firstEdge = edgeNode;
        free(verTex1);
        free(verTex2);
    }
    return OK;
}

int locateVerTextAdjList(AdjListGraph *graph, VerTex verTex) {
    int index = -1;
    for (int i = 0; i < graph->vexNum; ++i) {
        if (strcmp(verTex, graph->adjList[i].verTex) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

void testAdjList(GraphType type) {
    AdjListGraph graph;
    Status status = ERROR;
    if (type == UNDIGRAPH) {
        status = createUDGAdjList(&graph);
    }
    for (int i = 0; i < graph.vexNum; ++i) {
        VerTexNode verTexNode = graph.adjList[i];
        printf("下标%d 顶点%s:", i, verTexNode.verTex);
        EdgeNode *edgeNode = verTexNode.firstEdge;
        while (edgeNode) {
            printf("-> %d", edgeNode->adjVex);
            edgeNode = edgeNode->next;
        }
        printf("\n");
    }
}

