#include<stdio.h>
#include<stdlib.h>
#include "stack.h.h"
#include "stack.c.c" 


int main()
{
	SqStack *s1=(SqStack *)malloc(sizeof(SqStack));              //s1����ջ
	LinkStack *s2=(LinkStack *)malloc(sizeof(LinkStack));                //s2��ջ
	int sizes=0,t,length,datas,e;
	char c0;
	printf("����1��������ջ����������2������ջ����������0����\n");
	scanf("%d",&t);
	c0=getchar();
	if(c0!='\n') {printf("error");t=c0;}
	while(t)
	{
		if(t==1)
		{
			printf("����1��ʼ��˳��ջ  2�ж��Ƿ�Ϊ��  3ջ��Ԫ��  4���  5�Ƚϳ���  6��ջ  7��ջ  8����  0����\n");
	        scanf("%d",&t);
 	        c0=getchar();
			if(c0!='\n') {printf("�벻Ҫ�������");t=c0;}
	        while(t)
			{
				switch(t)
				{
					case 1:printf("�����С\n");scanf("%d",&sizes);c0=getchar();if(c0!='\n') sizes=c0;
					       printf("1�ɹ�  0ʧ�ܣ�  %d\n\n",initStack(s1,sizes));break;

					case 2:printf("1�յ�  0�ǿգ�  %d\n\n",isEmptyStack(s1));break;

					case 3:printf("1�ɹ�  0����  %d\n",getTopStack(s1,&e));
						   if(getTopStack(s1,&e)==1)  printf("ջ��Ԫ��e=%d\n",e);
						   printf("\n");break;

					case 4:printf("1�ɹ�  0����  %d\n\n",clearStack(s1));break;

					case 5:printf("���볤��\t");scanf("%d",&length);c0=getchar();if(c0!='\n') length=c0;
						   printf("1���ڻ����ջ����  0ʧ�ܻ�С��ջ���ȣ�%d\n\n",stackLength(s1,length));break;

					case 6:printf("������ջ������\t");scanf("%d",&datas);c0=getchar();if(c0!='\n') datas=c0;
						   printf("1�ɹ�  0ʧ�ܣ�  %d\n\n",pushStack(s1,datas));break;

					case 7:e=popStack(s1,&datas);
						   printf("1�ɹ�  0ʧ�ܣ�  %d\n",e);
						   if(e==1)  printf("ջ��Ԫ��datas=%d\n",datas);
						   printf("\n");break;

					case 8:printf("1�ɹ�  0ʧ�ܣ�  %d\n\n",destoryStack(s1));break;

					default:printf("�������\n");
				}
                printf("����1��ʼ��˳��ջ  2�ж��Ƿ�Ϊ��  3ջ��Ԫ��  4���  5�Ƚϳ���  6��ջ  7��ջ  8����  0����\n");
	            scanf("%d",&t);
 	            c0=getchar();
	            if(c0!='\n') t=c0;
			}
		}
		else if(t==2)
		{
			printf("����1������ջ  2�ж��Ƿ�Ϊ��  3ջ��Ԫ��  4���  5�Ƚϳ���  6��ջ   7��ջ  8����  0����\n");
            scanf("%d",&t);
 	        c0=getchar();
	        if(c0!='\n') t=c0;
			while(t)
			{
				switch(t)
				{
				case 1:printf("1�ɹ�  0ʧ�ܣ�  %d\n\n",initLStack(s2));break;

				case 2:printf("1�յ�  0�ǿգ�  %d\n\n",isEmptyLStack(s2));break;

				case 3:printf("1�ɹ�  0����  %d\n",getTopLStack(s2,&e));
					   if(getTopLStack(s2,&e)==1)  printf("ջ��Ԫ��e1=%d\n",e);
					   printf("\n");break;

				case 4:printf("1�ɹ�  0����  %d\n\n",clearLStack(s2));break;

                case 5:printf("���볤��\t");scanf("%d",&length);c0=getchar();if(c0!='\n') length=c0;
					   printf("1���ڻ����ջ����  0ʧ�ܻ�С��ջ���ȣ�  %d\n",LStackLength(s2,&length));
					   printf("ջ���ȣ�%d\n\n",s2->count);break;

				case 6:printf("������ջ������\t");scanf("%d",&datas);c0=getchar();if(c0!='\n') datas=c0;
					   printf("1�ɹ�  0ʧ�ܣ�  %d\n\n",pushLStack(s2,datas));break;
				
                case 7:e=popLStack(s2,&datas);
					   printf("1�ɹ�  0ʧ�ܣ�  %d\n",e);
					   if(e==1)  printf("ջ��Ԫ��datas=%d\n",datas);
				       printf("\n");break;

                case 8:printf("1�ɹ�  0ʧ�ܣ�  %d\n\n",destoryLStack(s2));break;

				default:printf("�������\n");
				}
                printf("\n����1��ʼ��˳��ջ  2�ж��Ƿ�Ϊ��  3ջ��Ԫ��  4���  5����  6��ջ  7��ջ  8����  0����\n");
	            scanf("%d",&t);
 	            c0=getchar();
	            if(c0!='\n') t=c0;
			}
		}
		else  printf("error\n");
        printf("\n����1��������ջ����������2������ջ����������0����\n");
	    scanf("%d",&t);
	    c0=getchar();
	    if(c0!='\n') {printf("error");t=c0;}
	}
	getchar();
	return 0;
}
