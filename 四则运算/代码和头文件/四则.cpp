#include<stdio.h>
#include<stdlib.h>
#define  MAXSIZE 100

typedef int ElemType;
typedef char ElemTypeC;

typedef struct SqStack{     //int
       ElemType	*elem;
       int top;      //����ջ��ָ��
       int size;
}SqStack;

typedef struct SqStackC{    //char
       ElemTypeC	*elemC;
       int topC;      //����ջ��ָ��
       int size;
}SqStackC;

void initStack(SqStack *s,int sizes)  //��ʼ��int����
{
    s->elem=(ElemType *)malloc(sizes * sizeof(ElemType));
    s->top=-1;
	s->size=sizes;
}

void initStackC(SqStackC *s,int sizes)  //��ʼ��char����
{
    s->elemC=(ElemTypeC *)malloc(sizes * sizeof(ElemTypeC));
    s->topC=-1;
	s->size=sizes;
}

void pushStack(SqStack *s,ElemType datas)  //��ջint
{
	if(NULL==s||s->top>=s->size-1)          //�жϿջ�����ջ
		printf("error\n");
	else{
	   s->top++;
	   s->elem[s->top]=datas;}
}

void pushStackC(SqStackC *s,ElemTypeC datas)  //��ջchar
{
	if(NULL==s||s->topC>=s->size-1)          //�жϿջ�����ջ
		printf("error\n");
	else{
	   s->topC++;
	   s->elemC[s->topC]=datas;}
}

int popStack(SqStack *s)   //��ջint
{
	int x;
	if(NULL==s||s->top==-1){
		printf("error\n");x=-1;}
	else{
	    x=s->elem[s->top];
		s->top--;}
	return x;
}

char popStackC(SqStackC *s)   //��ջchar
{
	char x;
	if(NULL==s||s->topC==-1){
		printf("error\n");x=0;}
	else{
	    x=s->elemC[s->topC];
		s->topC--;}
	return x;
}

int getTopStack(SqStack *s)   //�õ�����ͷԪ��int
{
	int x;
	if(NULL==s||s->top==-1){
		printf("error\n");x=-1;}
	else
		x=s->elem[s->top];
	return x;
}

char getTopStackC(SqStackC *s)   //�õ�����ͷԪ��char
{
	char x;
	if(NULL==s||s->topC==-1){
		printf("error\n");x=0;}
	else
		x=s->elemC[s->topC];
	return x;
}

int iso(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='='||c=='#')
        return 1;
    else
        return 0;
}

int ope(int x,char c,int y){
    int s;
    switch(c){
        case '+':s=x+y;break;
        case '-':s=x-y;break;
        case '*':s=x*y;break;
        case '/':s=x/y;break;
    }
    return s;
}

char pre(char s,char c)
{
	char a='>';
	switch(s)
	{
		case '+':
		case '-':if(c=='+'||c=='-')  a='>';
			     else if(c=='/'||c=='*') a='<';
                 else if(c=='(')     a='<';
                 else if(c==')')     a='>';break;
		case '*':
		case '/':if(c=='+'||c=='-')       a='>';
                 else if(c=='/'||c=='*')  a='>';
                 else if(c=='(')          a='<';
                 else if(c==')')          a='>';break;
		case '(':if(c=='(')               a='=';
			     else a='<';break;
		case '#':if(c=='#')               a='=';
			     else                     a='<';break;
	}
	return a;
}
 
int main()
{
	SqStack s1;
	SqStackC s2;
	int i,e,f,s;
	char c[101];
	printf("����������ʽ��(+-*/=)\t����0����\n");
	scanf("%s",c);
	while(c[0]!='0')
	{
        s=0;
		initStack(&s1,MAXSIZE);
		initStackC(&s2,MAXSIZE);
		pushStackC(&s2,'#');
		for(i=0;c[i]||getTopStackC(&s2)!='#';)
		{
			if(c[i]=='#' || c[i]=='=') 
              c[i] = 0; 
            if(c[i] && !iso(c[i]))
			{ 
                s=s*10+c[i]-'0';
                if(iso(c[i+1])||c[i+1]=='\0')
                    pushStack(&s1,s);
			}
            else
			{
                if(c[i] && pre(getTopStackC(&s2),c[i])=='<')
                    pushStackC(&s2,c[i]);
                else if(pre(getTopStackC(&s2),c[i])=='>')
				{
                    while(pre(getTopStackC(&s2),c[i])=='>'){
                        e=popStack(&s1);
                        f=popStack(&s1);
                        s=ope(f,popStackC(&s2),e);
                        pushStack(&s1,s);}
                    if(c[i] && pre(getTopStackC(&s2),c[i])=='<')
                        pushStackC(&s2,c[i]);
                    else if(pre(getTopStackC(&s2),c[i])=='=')
                        popStackC(&s2);
				}
                else if(pre(getTopStackC(&s2),c[i])=='=')
                    popStackC(&s2);
                s=0;
            }
            if(c[i]) i++; //��
        }
        s=popStack(&s1);
        printf("%d\n",s);
        printf("\n����������ʽ��(+-*/=)\t����0����\n");
	    scanf("%s",c);
    }
 getchar();
 getchar();
 return 0;
}
