#include <stdio.h>
#include <stdlib.h>
#include "stack.h.h"

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化链表
{
    s->elem=(ElemType *)malloc(sizes * sizeof(ElemType));
	if(NULL==s->elem)   return ERROR;
    s->top=-1;
	s->size=sizes;
	return(OK);
}


Status isEmptyStack(SqStack *s)   //判断链表是否为空
{
	return(s->top==-1?OK:ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //得到链表头元素
{
	if(NULL==s||s->top==-1)
		return ERROR;
	else
		*e=s->elem[s->top];
	return OK;
}


Status clearStack(SqStack *s)   //清空顺序栈
{
	if(s==NULL)   return ERROR;
	s->top=-1;
	return OK;
}


Status destoryStack(SqStack *s)  //销毁顺序栈
{
	if(NULL==s)
		return ERROR;
	free(s->elem);
	return OK;
}


Status stackLength(SqStack *s,int length)   //检测顺序栈长度
{
	if(s==NULL||s->top==-1)
		return ERROR;
	if(length<s->top+1) 
		return  ERROR;
	printf("栈长度：  %d\n",++(s->top));
	    return  OK;
}

Status pushStack(SqStack *s,ElemType datas)  //入栈
{
	if(NULL==s||s->top>=s->size-1)          //判断为空或者满栈
		return ERROR;
	s->top++;
	s->elem[s->top]=datas;
	return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //出栈
{
	if(NULL==s||s->top==-1)
		return ERROR;
	*datas=s->elem[s->top];
	s->top--;
	return OK;
}

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));
	if(!s->top)
		return ERROR;
	s->top=NULL;
	s->count=0;
	return OK;
}

Status isEmptyLStack(LinkStack *s)  //判断链表是否为空
{
	if(s->count==0||s->top==NULL||s==NULL)
		return OK;
	return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到链表头元素
{
	if(isEmptyLStack(s))
		return ERROR;
	*e=s->top->data;
	return OK;
}

Status clearLStack(LinkStack *s)   //清空链表
{
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	if(p==NULL)
		return ERROR;
	while(s->top!=NULL)
	{
		p=s->top;
		s->top=s->top->next;
		free(p);
	}
	initLStack(s);
	return OK;
}

Status destoryLStack(LinkStack *s)   //销毁链表
{
	if(s==NULL)
		return ERROR;
	free(s);
    return OK;
}

Status LStackLength(LinkStack *s,int *length)    //检测链表长度
{
	if(isEmptyLStack(s))
		return ERROR;
	if(*length<s->count)
		return ERROR;
	else
	    return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //入栈
{
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	if(s==NULL)
		return ERROR;	
	p->data=datas;
	p->next=s->top;
	s->top=p;
	s->count++;
	return OK;
}

Status popLStack(LinkStack *s,ElemType *datas)   //出栈
{
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	if(isEmptyLStack(s))
		return ERROR;
	p=s->top;
	*datas=s->top->data;
    s->top=s->top->next;
	free(p);
	s->count--;
	return OK;
}
