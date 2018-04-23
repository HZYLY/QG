#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "queue.c"

int key;                          //选择存储方式

int main()
{
	int i,t,flag;
	AQueue *p1;                    
	LQueue *p2;
	void *data;
	char c0;
	printf("请选择你要创建的队列类型：1.int  2.char\n");
	scanf("%d",&key);
	c0=getchar();
	if(c0!='\n')  {printf("error");key=c0;}

	printf("\n输入1进入循环队列操作  2进入链式队列操作 0结束\n");
	scanf("%d",&t);
	c0=getchar();
	if(c0!='\n')  {printf("error");t=c0;}
	while(t)
	{
		if(t==1)
		{
			printf("输入1建立队列  2销毁队列  3判断是否为空 4判断是否满队 5查看队头元素  6获取长度 7入队  8出队  9清空  10遍历  11输出  0结束\n");
            scanf("%d",&t);
 	        c0=getchar();
			if(c0!='\n') {printf("请不要随便输入");t=c0;}
			while(t)
			{
				switch(t)
				{
				case 1: InitAQueue(p1);break;
				case 2: DestoryAQueue(p1);break;
				case 3: printf("1：空的  0：非空  %d\n\n",IsEmptyAQueue(p1));break;
				case 4: printf("1：满队  0：未满  %d\n\n", IsFullAQueue(p1));break;
				case 5: flag=GetHeadAQueue(p1,data); if(flag) { if(key==1)printf("成功：%d\n\n",*((int*)data));
							if(key==2)printf("成功：%c\n\n",*((char*)data));};break;
				case 6: printf("%d\n\n",LengthAQueue(p1));break;
				case 7: printf("输入入队元素数据\n");scanf("%d",data);printf("1成功 2失败  %d\n\n",EnAQueue(p1,data));break;
                case 8: printf("1成功  0失败  %d\n\n",DeAQueue(p1));break;
				case 9: ClearAQueue(p1);break;
				default:printf("error\n\n");
				}
  				printf("输入1建队  2销队  3是否为空 4是否满队 5查看队头元素  6获取长度 7入队  8出队  9清空  10遍历  11输出  0结束\n\n");
                scanf("%d",&t);
 	            c0=getchar();
			    if(c0!='\n') {printf("请不要随便输入");t=c0;}	
			}
		}
	    printf("\n输入1进入循环队列操作  2进入链式队列操作 0结束\n");
	    scanf("%d",&t);
	    c0=getchar();
	    if(c0!='\n')  {printf("error");t=c0;}
	}
	getchar();
    return 0;
}
