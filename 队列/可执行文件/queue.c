#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void InitAQueue(AQueue *Q)
{
	int i;
	Q->front=0;
	Q->rear=0;
	for(i=0;i<MAXQUEUE;i++) 
	   Q->data[i]=(void *)malloc(Q->data_size);
	printf("创建成功\n\n"); 
}

void DestoryAQueue(AQueue *Q)
{
	if(Q==NULL)  printf("ERROR\n");exit(-1);
	free(Q->data);
	printf("销毁成功\n\n");
}

Status IsFullAQueue(const AQueue *Q)
{

	if(Q==NULL)   return FALSE;
	if(Q->front==(Q->rear+1)%MAXQUEUE)  return TRUE;
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q==NULL||Q->front==Q->rear)   return FALSE;
	return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q==NULL||Q->front==Q->rear)
	{printf("error\n"); return FALSE;
	}
	e=Q->data[Q->front];
	return TRUE;
}

Status EnAQueue(AQueue *Q, void *data)
{
	if((Q->rear+1)%MAXQUEUE==Q->front) return FALSE;
	Q->data[Q->rear]=data;
	Q->rear=(Q->rear+1)%MAXQUEUE;
	return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	if(Q==NULL)  return 0;
	return ((Q->rear)-Q->front+MAXQUEUE)%MAXQUEUE;
}

Status DeAQueue(AQueue *Q)
{
	if(Q->front==Q->rear)  return FALSE;
	Q->front=(Q->front+1)%MAXQUEUE;
	return TRUE;
}

void ClearAQueue(AQueue *Q)
{
	Q->front=Q->rear=0;printf("清空成功\n\n");
}

/*Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	AQueue *p=Q;
	if(Q==NULL||Q->front==Q->rear) return FALSE;
	int i,k;
	k=LengthAQueue(p);
	for(i=0;i<k;i++)
	{
		(*foo)(p);
		p->front=(p->front+1)%MAXQUEUE;
	}
	return TRUE;
}

void APrint(void *q)
{
	if(q==NULL)  printf("ERROR\n");exit(-1);
	printf("%d  ",(int)q->data[q->front]);
}
*/
/***
void InitLQueue(LQueue *Q)
{
	Q->data_size=(int *)malloc(MAXQUEUE*Q->data_size);
	Q->front=Q->rear=NULL;
	printf("创建成功");
}

void DestoryLQueue(LQueue *Q)
{
	while(Q->front)
	{
		Q->rear=Q->front;
		free(Q->front);
		Q->front=Q->rear;
	}
	printf("销毁成功\n");
}

Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->front==NULL||Q==NULL)
		return TRUE;
	return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q==NULL||Q->front==NULL)
	{ printf("ERROR\n");return FALSE;}
	Node *p;
	p=Q->front;
	e=p->data;
	return TRUE;
}

int LengthLQueue(LQueue *Q)
{
	Node *p;
	if(Q==NULL)
	{ printf("ERROR\n");return FALSE;}
	int count=0;
    p=Q->front;
	while(p!=NULL)
	{
       count++;p=p->next;
	}
	return count;
}


Status EnLQueue(LQueue *Q, void *data)
{
    Node *p=(Node *)malloc(sizeof(Node));
	if(p==NULL||Q==NULL)
	{  printf("ERROR\n");return FALSE;}	
	p->data=data;
	p->next=NULL;
	if(Q->front==NULL)
		Q->front=Q->rear=p;
	else
	{
    	Q->rear->next=p;
    	Q->rear=p;
	}
	return TRUE;
}

Status DeLQueue(LQueue *Q)
{
	Node *p;
	if(Q->front==NULL||Q==NULL)
		return FALSE;
	p=Q->front;
	Q->front=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	free(p);
	return TRUE;
}

void ClearLQueue(LQueue *Q)
{
	Node *p,*q;
	p=Q->front;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	Q->front=NULL;
	printf("清空成功\n");
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node *p;
	if(Q==NULL)
		return FALSE;
	p=Q->front;
	while(Q->front)
	{
		(*foo)(p);
		p=p->next;
	}
	return TRUE;		
}

void LPrint(void *q)
{
	printf("%d   ",(int)q->data);
}
**/
