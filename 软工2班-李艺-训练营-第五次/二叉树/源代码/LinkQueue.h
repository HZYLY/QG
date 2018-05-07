#include "BinaryTree.h"  
  
typedef struct QueueNode {  
    BiTree data;  
    struct QueueNode* next;  
}QueueNode;  
  
typedef struct {  
    QueueNode* front;  
    QueueNode* rear;  
}LinkQueue;  
  
LinkQueue* InitQueue();                            /** �����еĳ�ʼ�� */  
void DestoryQueue(LinkQueue*);                     /** ���ٶ��� */  
void EnQueue(LinkQueue*, BiTree T);             /** ��� */  
BiTree DeQueue(LinkQueue*);                   /** ���� */ 