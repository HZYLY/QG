#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "queue.c"

int key;                          //ѡ��洢��ʽ

int main()
{
	int i,t,flag;
	AQueue *p1;                    
	LQueue *p2;
	void *data;
	char c0;
	printf("��ѡ����Ҫ�����Ķ������ͣ�1.int  2.char\n");
	scanf("%d",&key);
	c0=getchar();
	if(c0!='\n')  {printf("error");key=c0;}

	printf("\n����1����ѭ�����в���  2������ʽ���в��� 0����\n");
	scanf("%d",&t);
	c0=getchar();
	if(c0!='\n')  {printf("error");t=c0;}
	while(t)
	{
		if(t==1)
		{
			printf("����1��������  2���ٶ���  3�ж��Ƿ�Ϊ�� 4�ж��Ƿ����� 5�鿴��ͷԪ��  6��ȡ���� 7���  8����  9���  10����  11���  0����\n");
            scanf("%d",&t);
 	        c0=getchar();
			if(c0!='\n') {printf("�벻Ҫ�������");t=c0;}
			while(t)
			{
				switch(t)
				{
				case 1: InitAQueue(p1);break;
				case 2: DestoryAQueue(p1);break;
				case 3: printf("1���յ�  0���ǿ�  %d\n\n",IsEmptyAQueue(p1));break;
				case 4: printf("1������  0��δ��  %d\n\n", IsFullAQueue(p1));break;
				case 5: flag=GetHeadAQueue(p1,data); if(flag) { if(key==1)printf("�ɹ���%d\n\n",*((int*)data));
							if(key==2)printf("�ɹ���%c\n\n",*((char*)data));};break;
				case 6: printf("%d\n\n",LengthAQueue(p1));break;
				case 7: printf("�������Ԫ������\n");scanf("%d",data);printf("1�ɹ� 2ʧ��  %d\n\n",EnAQueue(p1,data));break;
                case 8: printf("1�ɹ�  0ʧ��  %d\n\n",DeAQueue(p1));break;
				case 9: ClearAQueue(p1);break;
				default:printf("error\n\n");
				}
  				printf("����1����  2����  3�Ƿ�Ϊ�� 4�Ƿ����� 5�鿴��ͷԪ��  6��ȡ���� 7���  8����  9���  10����  11���  0����\n\n");
                scanf("%d",&t);
 	            c0=getchar();
			    if(c0!='\n') {printf("�벻Ҫ�������");t=c0;}	
			}
		}
	    printf("\n����1����ѭ�����в���  2������ʽ���в��� 0����\n");
	    scanf("%d",&t);
	    c0=getchar();
	    if(c0!='\n')  {printf("error");t=c0;}
	}
	getchar();
    return 0;
}
