#include <stdio.h>  
#include <stdlib.h>  
#include "BinaryTree.h"  
  
/** �����еĳ�ʼ�� */  
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
  
/** �����е����� */  
void DestoryQueue(LinkQueue* queue)  
{  
    while (queue->front)  
    {  
        queue->rear = queue->front->next;  
        free(queue->front);  
        queue->front = queue->rear;  
    }  
}  
  
/** ��� */  
void EnQueue(LinkQueue* queue, BiTree node)  
{  
    QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));  
    queueNode->data = node;  
    queueNode->next = NULL;  
    queue->rear->next = queueNode;  
    queue->rear = queueNode;  
}  
  
/** ���� */  
BiTree DeQueue(LinkQueue* queue)  
{  
    if (queue->front == queue->rear)//����Ϊ��  
        return NULL;  
    QueueNode* p = queue->front->next;  
    BiTree node = p->data;  
    queue->front = p;  
    return node;  
} 