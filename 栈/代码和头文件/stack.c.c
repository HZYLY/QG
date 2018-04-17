#include <stdio.h>
#include <stdlib.h>
#include "stack.h.h"

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ������
{
    s->elem=(ElemType *)malloc(sizes * sizeof(ElemType));
	if(NULL==s->elem)   return ERROR;
    s->top=-1;
	s->size=sizes;
	return(OK);
}


Status isEmptyStack(SqStack *s)   //�ж������Ƿ�Ϊ��
{
	return(s->top==-1?OK:ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //�õ�����ͷԪ��
{
	if(NULL==s||s->top==-1)
		return ERROR;
	else
		*e=s->elem[s->top];
	return OK;
}


Status clearStack(SqStack *s)   //���˳��ջ
{
	if(s==NULL)   return ERROR;
	s->top=-1;
	return OK;
}


Status destoryStack(SqStack *s)  //����˳��ջ
{
	if(NULL==s)
		return ERROR;
	free(s->elem);
	return OK;
}


Status stackLength(SqStack *s,int length)   //���˳��ջ����
{
	if(s==NULL||s->top==-1)
		return ERROR;
	if(length<s->top+1) 
		return  ERROR;
	printf("ջ���ȣ�  %d\n",++(s->top));
	    return  OK;
}

Status pushStack(SqStack *s,ElemType datas)  //��ջ
{
	if(NULL==s||s->top>=s->size-1)          //�ж�Ϊ�ջ�����ջ
		return ERROR;
	s->top++;
	s->elem[s->top]=datas;
	return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //��ջ
{
	if(NULL==s||s->top==-1)
		return ERROR;
	*datas=s->elem[s->top];
	s->top--;
	return OK;
}

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));
	if(!s->top)
		return ERROR;
	s->top=NULL;
	s->count=0;
	return OK;
}

Status isEmptyLStack(LinkStack *s)  //�ж������Ƿ�Ϊ��
{
	if(s->count==0||s->top==NULL||s==NULL)
		return OK;
	return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�����ͷԪ��
{
	if(isEmptyLStack(s))
		return ERROR;
	*e=s->top->data;
	return OK;
}

Status clearLStack(LinkStack *s)   //�������
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

Status destoryLStack(LinkStack *s)   //��������
{
	if(s==NULL)
		return ERROR;
	free(s);
    return OK;
}

Status LStackLength(LinkStack *s,int *length)    //���������
{
	if(isEmptyLStack(s))
		return ERROR;
	if(*length<s->count)
		return ERROR;
	else
	    return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //��ջ
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

Status popLStack(LinkStack *s,ElemType *datas)   //��ջ
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
