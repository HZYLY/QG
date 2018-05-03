#include<stdio.h>
void ColorSort(int *s,int n)
{
	int i,j=0,t=0,k=n-1;
	int *p0,*p,*p2;                      //0指针p0   2指针p2
	p0=p=p2=s;
	for(i=1;p+i<p2+k;i++)
	{
		  if(p[i]==0)
		  {
			  t=p0[j];p0[j++]=p[i];p[i]=t;
			  if(p[i-1]!=0)                         //如果0的前一个不为0 则i--重复判断
				  i--;
			  else;
		  }
		  else if(p[i]==2)
		  {
			  t=p2[k];p2[k--]=p[i];p[i]=t;
			  i--;
		  }
	}
}
int main()
{
	int a[10]={0,0,2,1,2,1,0,2,0,2};
	int i;
	printf("排序前:  ");
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
	printf("\n\n排序后： ");
	ColorSort(a,10);
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
	getchar();
	getchar();
	return 0;
}


