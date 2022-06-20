/**
 * Created by Rui on 2022/6/17.
 */

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
    printf("邻接表：\n");
    for(int i = 0; i < graph.vexCount; i++){
        VNode vNode = graph.vexes[i];
        ArcNode * arcNode = vNode.firstArc;
        printf("顶点%s：", vNode.vex);
        while(arcNode){
            printf(" -> %d(%d)", arcNode->adjVex, arcNode->weight);
            arcNode = arcNode->nextArc;
        }
        printf("\n");
    }

    printf("逆邻接表：\n");
    for(int i = 0; i < graph.vexCount; i++){
        VNode vNode = graph.vexes[i];
        ArcNode * arcNode = vNode.firstEdge;
        printf("顶点%s：", vNode.vex);
        while(arcNode){
            printf(" <- %d(%d)", arcNode->adjVex, arcNode->weight);
            arcNode = arcNode->nextEdge;
        }
        printf("\n");
    }
//    for(int i = 0; i < graph.vexCount; i++){
//        VNode vNode = graph.vexes[i];
//        printf("顶点：%s", vNode.vex);
//        EdgeNode * eNode = vNode.firstEdge;
//        while(eNode){
//            printf(" -> %d", eNode->adjVex);
//            eNode = eNode->nextEdge;
//        }
//        printf("\n");
//    }
}

