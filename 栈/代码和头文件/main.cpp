#include<stdio.h>
#include<stdlib.h>
#include "stack.h.h"
#include "stack.c.c" 


int main()
{
	SqStack *s1=(SqStack *)malloc(sizeof(SqStack));              //s1数组栈
	LinkStack *s2=(LinkStack *)malloc(sizeof(LinkStack));                //s2链栈
	int sizes=0,t,length,datas,e;
	char c0;
	printf("输入1进入数组栈操作，输入2进入链栈操作，输入0结束\n");
	scanf("%d",&t);
	c0=getchar();
	if(c0!='\n') {printf("error");t=c0;}
	while(t)
	{
		if(t==1)
		{
			printf("输入1初始化顺序栈  2判断是否为空  3栈顶元素  4清空  5比较长度  6入栈  7出栈  8销毁  0结束\n");
	        scanf("%d",&t);
 	        c0=getchar();
			if(c0!='\n') {printf("请不要随便输入");t=c0;}
	        while(t)
			{
				switch(t)
				{
					case 1:printf("输入大小\n");scanf("%d",&sizes);c0=getchar();if(c0!='\n') sizes=c0;
					       printf("1成功  0失败：  %d\n\n",initStack(s1,sizes));break;

					case 2:printf("1空的  0非空：  %d\n\n",isEmptyStack(s1));break;

					case 3:printf("1成功  0错误：  %d\n",getTopStack(s1,&e));
						   if(getTopStack(s1,&e)==1)  printf("栈顶元素e=%d\n",e);
						   printf("\n");break;

					case 4:printf("1成功  0错误：  %d\n\n",clearStack(s1));break;

					case 5:printf("输入长度\t");scanf("%d",&length);c0=getchar();if(c0!='\n') length=c0;
						   printf("1大于或等于栈长度  0失败或小于栈长度：%d\n\n",stackLength(s1,length));break;

					case 6:printf("输入入栈的数据\t");scanf("%d",&datas);c0=getchar();if(c0!='\n') datas=c0;
						   printf("1成功  0失败：  %d\n\n",pushStack(s1,datas));break;

					case 7:e=popStack(s1,&datas);
						   printf("1成功  0失败：  %d\n",e);
						   if(e==1)  printf("栈顶元素datas=%d\n",datas);
						   printf("\n");break;

					case 8:printf("1成功  0失败：  %d\n\n",destoryStack(s1));break;

					default:printf("输入错误\n");
				}
                printf("输入1初始化顺序栈  2判断是否为空  3栈顶元素  4清空  5比较长度  6入栈  7出栈  8销毁  0结束\n");
	            scanf("%d",&t);
 	            c0=getchar();
	            if(c0!='\n') t=c0;
			}
		}
		else if(t==2)
		{
			printf("输入1创建链栈  2判断是否为空  3栈顶元素  4清空  5比较长度  6入栈   7出栈  8销毁  0结束\n");
            scanf("%d",&t);
 	        c0=getchar();
	        if(c0!='\n') t=c0;
			while(t)
			{
				switch(t)
				{
				case 1:printf("1成功  0失败：  %d\n\n",initLStack(s2));break;

				case 2:printf("1空的  0非空：  %d\n\n",isEmptyLStack(s2));break;

				case 3:printf("1成功  0错误：  %d\n",getTopLStack(s2,&e));
					   if(getTopLStack(s2,&e)==1)  printf("栈顶元素e1=%d\n",e);
					   printf("\n");break;

				case 4:printf("1成功  0错误：  %d\n\n",clearLStack(s2));break;

                case 5:printf("输入长度\t");scanf("%d",&length);c0=getchar();if(c0!='\n') length=c0;
					   printf("1大于或等于栈长度  0失败或小于栈长度：  %d\n",LStackLength(s2,&length));
					   printf("栈表长度：%d\n\n",s2->count);break;

				case 6:printf("输入入栈的数据\t");scanf("%d",&datas);c0=getchar();if(c0!='\n') datas=c0;
					   printf("1成功  0失败：  %d\n\n",pushLStack(s2,datas));break;
				
                case 7:e=popLStack(s2,&datas);
					   printf("1成功  0失败：  %d\n",e);
					   if(e==1)  printf("栈顶元素datas=%d\n",datas);
				       printf("\n");break;

                case 8:printf("1成功  0失败：  %d\n\n",destoryLStack(s2));break;

				default:printf("输入错误\n");
				}
                printf("\n输入1初始化顺序栈  2判断是否为空  3栈顶元素  4清空  5长度  6入栈  7出栈  8销毁  0结束\n");
	            scanf("%d",&t);
 	            c0=getchar();
	            if(c0!='\n') t=c0;
			}
		}
		else  printf("error\n");
        printf("\n输入1进入数组栈操作，输入2进入链栈操作，输入0结束\n");
	    scanf("%d",&t);
	    c0=getchar();
	    if(c0!='\n') {printf("error");t=c0;}
	}
	getchar();
	return 0;
}
