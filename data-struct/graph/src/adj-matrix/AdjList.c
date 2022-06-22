/**
 * Created by Rui on 2022/6/17.
 */

//#include "../../head/adj-list/AdjList.h"
#include "../../head/queue/LinkedQueue4AdjList.h"
#include "../../head/adj-list/AdjList.h"


Status createUDGAdjList(AdjListGraph *graph) {
    graph->type = UNDIGRAPH;
    printf("请输入顶点数量：");
    scanf("%d", &graph->vexCount);
    printf("请输入边的数量：");
    scanf("%d", &graph->edgeCount);
    printf("请依次输入顶点信息\n");
    for(int i = 0; i < graph->vexCount; i++){
        graph->vexes[i].vex = (VerTex)malloc(sizeof(char) * 10);
        printf("顶点%d：", i + 1);
        scanf("%s", graph->vexes[i].vex);
        //初始化邻接表，把边置空
        graph->vexes[i].firstEdge = NULL;
    }
    printf("请输入顶点和邻接点信息，构建邻接表\n");
    for(int i = 0; i < graph->edgeCount; i++){
        VerTex vex1 = (VerTex) malloc(sizeof(char) * 10);
        VerTex vex2 = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点：");
        scanf("%s", vex1);
        printf("邻接点：");
        scanf("%s", vex2);
        int x = locateVerTextAdjList(graph, vex1);
        int y = locateVerTextAdjList(graph, vex2);
        if(x == -1 || y == -1) {
            free(vex1);
            free(vex2);
            return ERROR;
        }
        EdgeNode * edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex = x;
        edgeNode->nextEdge = graph->vexes[y].firstEdge;
        edgeNode->weight = 0;
        graph->vexes[y].firstEdge = edgeNode;
        edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex = y;
        edgeNode->nextEdge = graph->vexes[x].firstEdge;
        edgeNode->weight = 0;
        graph->vexes[x].firstEdge = edgeNode;

        free(vex1);
        free(vex2);
    }
    return OK;
}

Status createDGAdjList(AdjListGraph *graph) {
    graph->type = UNDIGRAPH;
    printf("请输入顶点数量：");
    scanf("%d", &graph->vexCount);
    printf("请输入边的数量：");
    scanf("%d", &graph->edgeCount);
    printf("请依次输入顶点信息\n");
    for(int i = 0; i < graph->vexCount; i++){
        graph->vexes[i].vex = (VerTex)malloc(sizeof(char) * 10);
        printf("顶点%d：", i + 1);
        scanf("%s", graph->vexes[i].vex);
        //初始化邻接表，把边置空
        graph->vexes[i].firstEdge = NULL;
        graph->vexes[i].firstArc = NULL;
    }
    printf("请输入顶点和邻接点信息，构建邻接表\n");
    for(int i = 0; i < graph->edgeCount; i++){
        VerTex vex1 = (VerTex) malloc(sizeof(char) * 10);
        VerTex vex2 = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点：");
        scanf("%s", vex1);
        printf("邻接点：");
        scanf("%s", vex2);
        int x = locateVerTextAdjList(graph, vex1);
        int y = locateVerTextAdjList(graph, vex2);
        if(x == -1 || y == -1) {
            free(vex1);
            free(vex2);
            return ERROR;
        }
        //生成边结点的邻接表（出边）
        ArcNode * arcNode = (ArcNode*)malloc(sizeof(ArcNode));
        arcNode->adjVex = y;
        arcNode->nextArc = graph->vexes[x].firstArc;
        graph->vexes[x].firstArc = arcNode;
        arcNode->weight = 0;
        //生成边结点的邻接表（入边）
        EdgeNode * edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex = x;
        edgeNode->nextEdge = graph->vexes[y].firstEdge;
        edgeNode->weight = 0;
        graph->vexes[y].firstEdge = edgeNode;

        free(vex1);
        free(vex2);
    }
    return OK;
}

Status createDNAdjList(AdjListGraph *graph) {
    graph->type = DINET;
    printf("请输入顶点数量：");
    scanf("%d", &graph->vexCount);
    printf("请输入边的数量：");
    scanf("%d", &graph->edgeCount);
    printf("请依次输入顶点信息\n");
    for(int i = 0; i < graph->vexCount; i++){
        graph->vexes[i].vex = (VerTex)malloc(sizeof(char) * 10);
        printf("顶点%d：", i + 1);
        scanf("%s", graph->vexes[i].vex);
        //初始化邻接表，把边置空
        graph->vexes[i].firstEdge = NULL;
        graph->vexes[i].firstArc = NULL;
    }
    printf("请输入顶点和邻接点信息，构建邻接表\n");
    for(int i = 0; i < graph->edgeCount; i++){
        VerTex vex1 = (VerTex) malloc(sizeof(char) * 10);
        VerTex vex2 = (VerTex) malloc(sizeof(char) * 10);
        printf("顶点：");
        scanf("%s", vex1);
        printf("邻接点：");
        scanf("%s", vex2);
        int weight;
        printf("权值：");
        scanf("%d", &weight);
        int x = locateVerTextAdjList(graph, vex1);
        int y = locateVerTextAdjList(graph, vex2);
        if(x == -1 || y == -1) {
            free(vex1);
            free(vex2);
            return ERROR;
        }
        //生成边结点的邻接表（出边）
        ArcNode * arcNode = (ArcNode*)malloc(sizeof(ArcNode));
        arcNode->adjVex = y;
        arcNode->nextArc = graph->vexes[x].firstArc;
        graph->vexes[x].firstArc = arcNode;
        arcNode->weight = weight;
        //生成边结点的邻接表（入边）
        EdgeNode * edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex = x;
        edgeNode->nextEdge = graph->vexes[y].firstEdge;
        edgeNode->weight = weight;
        graph->vexes[y].firstEdge = edgeNode;

        free(vex1);
        free(vex2);
    }
    return OK;
}

int locateVerTextAdjList(AdjListGraph *graph, VerTex verTex) {
    int index = -1;
    for(int i = 0; i < graph->vexCount; i++){
        if(strcmp(verTex, graph->vexes[i].vex) == 0){
            index = i;
            break;
        }
    }
    return index;
}

void adjListDFS(AdjListGraph *graph) {
    // 初始化访问状态数组
    for (int i = 0; i < graph->vexCount; ++i) {
        visited[i] = UN_VISITED;
    }
    for (int i = 0; i < graph->vexCount; i++) {
        if (!visited[i]) {
            // 如果顶点没有访问过就递归访问该顶点
            adjListGraphDFS(graph, i);
        }
    }
}

void adjListGraphDFS(AdjListGraph *graph, int index) {
    printf("-> %s", graph->vexes[index].vex);
    visited[index] = VISITED;   // 设置 index 下标的顶点被访问
    if (graph->type == UNDIGRAPH || graph->type == UNDINET) {
        EdgeNode *edgeNode = graph->vexes[index].firstEdge;
        while (edgeNode) {
            if (!visited[edgeNode->adjVex]) {
                // 如果邻接点未访问就递归访问
                adjListGraphDFS(graph, edgeNode->adjVex);
            }
            edgeNode = edgeNode->nextEdge;
        }
    }
    if (graph->type == DIGRAPH || graph->type == DINET) {
        ArcNode *arcNode = graph->vexes[index].firstArc;
        while (arcNode) {
            if (!visited[arcNode->adjVex]) {
                // 如果邻接点未访问就递归访问
                adjListGraphDFS(graph, arcNode->adjVex);
            }
            arcNode = arcNode->nextArc;
        }
    }
}

void adjListGraphBFS(AdjListGraph graph) {
    for (int i = 0; i < graph.vexCount; ++i) {
        visited[i] = UN_VISITED;
    }
    for (int i = 0; i < graph.vexCount; ++i) {
        if (!visited[i]) {
            adjListBFS(graph, i);
        }
    }
}

void adjListBFS(AdjListGraph graph, int index) {
    printf("-> %s", graph.vexes[index].vex);
    visited[index] = VISITED;
    LinkedQueue queue;
    initLinkedQueue4AdjList(&queue);
    enqueue4AdjList(&queue, &graph.vexes[index]);
    while (!isLinkedQueueEmpty4AdjList(&queue)) {
        VNode *vNode = (VNode *) malloc(sizeof(VNode));
        VNode *tempNode = vNode;
        dequeue4AdjList(&queue, &vNode);
        // 获得出队顶点的下标
        int indexVNode = locateVerTextAdjList(&graph, vNode->vex);
        if (indexVNode == -1) {
            return;
        }
        // 遍历顶点对应的边或弧
        if (graph.type == UNDIGRAPH || graph.type == UNDINET) {
            EdgeNode *edgeNode = graph.vexes[indexVNode].firstEdge;
            while (edgeNode) {
                if (!visited[edgeNode->adjVex]) {
                    printf("-> %s", graph.vexes[edgeNode->adjVex].vex);
                    visited[edgeNode->adjVex] = VISITED;
                    enqueue4AdjList(&queue, &graph.vexes[edgeNode->adjVex]);
                }
                edgeNode = edgeNode->nextEdge;
            }
        } else if (graph.type == DIGRAPH || graph.type == DINET) {
            ArcNode *arcNode = graph.vexes[indexVNode].firstArc;
            while (arcNode) {
                if (!visited[arcNode->adjVex]) {
                    printf("-> %s", graph.vexes[arcNode->adjVex].vex);
                    visited[arcNode->adjVex] = VISITED;
                    enqueue4AdjList(&queue, &graph.vexes[arcNode->adjVex]);
                }
                arcNode = arcNode->nextArc;
            }
        }
        free(tempNode);
    }
}

void testAdjList(GraphType type) {
    AdjListGraph graph;
    Status status = ERROR;
    if (type == UNDIGRAPH) {
        status = createUDGAdjList(&graph);
    } else if (type == DIGRAPH) {
        status = createDGAdjList(&graph);
    } else if (type == DINET) {
        status = createDNAdjList(&graph);
    }
    if (status == ERROR) {
        printf("创建失败");
        return;
    }
    for(int i = 0; i < graph.vexCount; i++){
        VNode vNode = graph.vexes[i];
        printf("顶点：%s", vNode.vex);
        EdgeNode * eNode = vNode.firstEdge;
        while(eNode){
            printf(" -> %d", eNode->adjVex);
            eNode = eNode->nextEdge;
        }
        printf("\n");
    }
    printf("\n邻接表实现的深度优先遍历\n");
    adjListDFS(&graph);

    printf("\n邻接表实现的广度优先遍历\n");
    adjListGraphBFS(graph);
//    printf("邻接表：\n");
//    for(int i = 0; i < graph.vexCount; i++){
//        VNode vNode = graph.vexes[i];
//        ArcNode * arcNode = vNode.firstArc;
//        printf("顶点%s：", vNode.vex);
//        while(arcNode){
//            printf(" -> %d(%d)", arcNode->adjVex, arcNode->weight);
//            arcNode = arcNode->nextArc;
//        }
//        printf("\n");
//    }
//
//    printf("逆邻接表：\n");
//    for(int i = 0; i < graph.vexCount; i++){
//        VNode vNode = graph.vexes[i];
//        ArcNode * arcNode = vNode.firstEdge;
//        printf("顶点%s：", vNode.vex);
//        while(arcNode){
//            printf(" <- %d(%d)", arcNode->adjVex, arcNode->weight);
//            arcNode = arcNode->nextEdge;
//        }
//        printf("\n");
//    }
//    printf("邻接表实现的深度优先搜索\n");
//    adjListDFS(&graph);
//    printf("\n领接表深度优先遍历\n");
//    adjListGraphBFS(graph);
}