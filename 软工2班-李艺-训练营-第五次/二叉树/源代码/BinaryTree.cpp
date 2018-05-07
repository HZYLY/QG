#include<stdio.h>
#include<stdlib.h>

#include "LinkQueue.h"

Status InitBiTree(BiTree T)                                              //初始化
{
	T=(BiTree)malloc(sizeof(BiTree));
	if(T==NULL)
	{	printf("ERROR");return ERROR;}
	T->data=NULL;
	T->lchild=NULL;
	T->rchild=NULL;
	return SUCCESS;
}

Status DestroyBiTree(BiTree T)                                         //销毁
{
	if(T)
	{
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
		free(T);
		T=NULL;
	}
	else
		return ERROR;
	return SUCCESS;
}

Status CreateBiTree(BiTree T, char* definition)                        //创造
{
	char a;
	if(T==NULL)
		return ERROR;
	if(*definition==1)                                                  //输入一 先序创造
	{
		scanf("%a",&a);
		if(a==0)
			T=NULL;
		else
		{
			T->data=a;
			InitBiTree(T->lchild);
			CreateBiTree(T->lchild,definition);
			InitBiTree(T->rchild);
            CreateBiTree(T->rchild,definition);
		}
	}

	return SUCCESS;
}



Status PreOrderTraverse(BiTNode T)                             //先序
{
	if(&T)
	{
		printf("%c\n",T.data);
		PreOrderTraverse(*(T.lchild));
		PreOrderTraverse(*(T.rchild));
	}
	else 
		return ERROR;
	return SUCCESS;
}

Status InOrderTraverse(BiTNode T)                              //中序
{
	if(&T)
	{
          InOrderTraverse(*(T.lchild));
		  printf("%c\n",T.data);
		  InOrderTraverse(*(T.rchild));
	}
	else
		return ERROR;
	return SUCCESS;
}

Status PostOrderTraverse(BiTNode T)                              //后序
{
	if(&T)
	{
		PostOrderTraverse(*(T.lchild));
		PostOrderTraverse(*(T.rchild));
        printf("%c\n",T.data);
	}
	else
		return ERROR;
	return SUCCESS;
}

Status LevelOrderTraverse(BiTNode T)                             //层序遍历
{
	int curLayerCount =0;
	int nextLayerCount =0;
	if(&T)
		return ERROR;
	LinkQueue* queue =InitQueue();
	EnQueue(queue,&T);
	curLayerCount++;
	BiTNode *p;
	while(p=DeQueue(queue))
	{
		curLayerCount--;
		printf("%c\n",T.data);
		if(p->lchild)
		{
			EnQueue(queue,p->lchild);
			nextLayerCount++;
		}
	    if (curLayerCount == 0)//一层已经遍历完毕  
        {  
            curLayerCount = nextLayerCount;  
            nextLayerCount = 0;  
            printf("\n");  
		}
	}
	return SUCCESS;
}
