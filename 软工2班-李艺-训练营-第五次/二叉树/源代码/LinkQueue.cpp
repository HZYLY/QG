#include <stdio.h>  
#include <stdlib.h>  
#include "BinaryTree.h"  
  
/** 链队列的初始化 */  
LinkQueue* InitQueue()  
{  
    LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));  
    if (!queue)  
    {  
        printf("error!\n");  
        exit(0);  
    }  
    queue->front = (QueueNode*)malloc(sizeof(QueueNode));  
    queue->front->next = NULL;  
    queue->rear = queue->front;  
    return queue;  
}  
  
/** 链队列的销毁 */  
void DestoryQueue(LinkQueue* queue)  
{  
    while (queue->front)  
    {  
        queue->rear = queue->front->next;  
        free(queue->front);  
        queue->front = queue->rear;  
    }  
}  
  
/** 入队 */  
void EnQueue(LinkQueue* queue, BiTree node)  
{  
    QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));  
    queueNode->data = node;  
    queueNode->next = NULL;  
    queue->rear->next = queueNode;  
    queue->rear = queueNode;  
}  
  
/** 出队 */  
BiTree DeQueue(LinkQueue* queue)  
{  
    if (queue->front == queue->rear)//队列为空  
        return NULL;  
    QueueNode* p = queue->front->next;  
    BiTree node = p->data;  
    queue->front = p;  
    return node;  
} 