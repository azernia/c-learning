#include "../../head/queue/LinkedQueue.h"

///** 初始化链队列 - 有头结点实现 */
void initLinkedQueue(LinkedQueue * linkedQueue){
    QueueNode * node = (QueueNode *)malloc(sizeof(QueueNode));
    node->next = NULL;
    linkedQueue->front = node;  //队头指向一个空结点
    linkedQueue->rear = node;
    linkedQueue->length = 0;
}

///** 入队 - 有头结点 */
void enqueue(LinkedQueue * linkedQueue, VerTex element){
//创建一个新结点
    QueueNode * node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = element;
    node->next = NULL;      //在队尾添加，所以新结点的next指向NULL
    linkedQueue->rear->next = node;
    linkedQueue->rear = node;
    linkedQueue->length++;
}

///** 出队 */
void dequeue(LinkedQueue * linkedQueue, VerTex *element){
    //如果首尾相连，证明队列为空
    if(linkedQueue->front == linkedQueue->rear){
        printf("队列为空，出队失败！\n");
        return;
    }
    //取出头结点-这里注意，front不存放内容
    QueueNode * node = linkedQueue->front->next;
    *element = node->data;
    //我们只关注front->next，因为front会一直指向第一个结点空间
    linkedQueue->front->next = node->next;
    if(linkedQueue->rear == node){
        linkedQueue->rear = linkedQueue->front;
    }
    free(node);
    linkedQueue->length--;
}

int isLinkedQueueEmpty(LinkedQueue * linkedQueue){
    return linkedQueue->front == linkedQueue->rear;
}


///** 初始化链队列 - 无头结点实现 */
//void InitLinkedQueue(LinkedQueue * linkedQueue){
//    linkedQueue->front = NULL;
//    linkedQueue->rear = NULL;
//    linkedQueue->length = 0;
//}
//
///** 入队 - 无头结点 */
//void OfferLinkedQueue(LinkedQueue * linkedQueue, VerTex element){
//    //创建一个新结点
//    QueueNode * node = (QueueNode *)malloc(sizeof(QueueNode));
//    node->data = element;
//    node->next = NULL;      //在队尾添加，所以新结点的next指向NULL
//    if(linkedQueue->front == NULL){//如果队列为空
//        linkedQueue->front = node;
//        linkedQueue->rear = node;
//    }else{
//        //原队尾next指向新结点
//        linkedQueue->rear->next = node;
//        linkedQueue->rear = node;
//    }
//    linkedQueue->length++;
//}
//
///** 出队 */
//void PollLinkedQueue(LinkedQueue * linkedQueue, VerTex *element){
//    if(linkedQueue->front == NULL && linkedQueue->rear == 0){
//        printf("队列为空，出队失败！\n");
//        return;
//    }
//    QueueNode * node = linkedQueue->front;  //记录下要出队的结点
//    *element = node->data;
//    linkedQueue->front = node->next;
//    if(linkedQueue->rear == node){//空队的情况
//        linkedQueue->rear = linkedQueue->front;
//    }
//    free(node);
//}






