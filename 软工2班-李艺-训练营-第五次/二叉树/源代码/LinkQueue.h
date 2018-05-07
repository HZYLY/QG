#include "BinaryTree.h"  
  
typedef struct QueueNode {  
    BiTree data;  
    struct QueueNode* next;  
}QueueNode;  
  
typedef struct {  
    QueueNode* front;  
    QueueNode* rear;  
}LinkQueue;  
  
LinkQueue* InitQueue();                            /** 链队列的初始化 */  
void DestoryQueue(LinkQueue*);                     /** 销毁队列 */  
void EnQueue(LinkQueue*, BiTree T);             /** 入队 */  
BiTree DeQueue(LinkQueue*);                   /** 出队 */ 