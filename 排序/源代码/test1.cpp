#include<stdio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>



#define N1 10000
#define N2 50000
#define N3 200000
#define N4 100000
int main()
{
	 void InsertSort(int *s, int n);                 //插入排序
     void merging(int *list1,int list_size1,int *list2,int list_size2);   //归并之并
     void MergeSort(int *s,int n);                         //归并
     void CountSort(int *s,int n);                         //计数
     void RadixSort(int *index,int *a,int len);  
     void RadixCountSort(int *a,int len);                 //基数
     int partition(int arr[],int low,int high);
     void QSort_Recursion(int arr[],int start,int end);         //快排之递归  end=N-1
     void QSort(int* A,int n);                              //快排之非递归

	int i,j;
    int a[N1],b[N2],c[N3],d[N4];
	for(i=0;i<N1;i++)
		a[i]=rand();
	clock_t start11 =clock();
    InsertSort(a,N1);                   
	clock_t diff11=clock()-start11;         //10000插入排序时间

	for(i=0;i<N1;i++)
		a[i]=rand();
	clock_t start12=clock();
	MergeSort(a,N1);
	clock_t diff12=clock()-start12;        //10000归并排序时间

    for(i=0;i<N1;i++)
		a[i]=rand();
	clock_t start13=clock();
	QSort_Recursion(a,0,N1-1);
	clock_t diff13=clock()-start13;       //10000快排之递归时间


    for(i=0;i<N1;i++)
		a[i]=rand();
	clock_t start14=clock();
	QSort(a,N1);
	clock_t diff14=clock()-start14;       //10000快排之非递归时间


    for(i=0;i<N1;i++)
		a[i]=rand();
	clock_t start15=clock();
	CountSort(a,N1);
	clock_t diff15=clock()-start15;       //10000计数排序时间

    for(i=0;i<N1;i++)
		a[i]=rand();
	clock_t start16=clock();
	RadixCountSort(a,N1);
	clock_t diff16=clock()-start16;       //10000基数排序时间

    printf("10000  50000 200000 100次10万个数据排序时间\n");
	printf("\n1排序  插入\t归并\t快排递归\t快排非递归\t计数\t基数\n");
	printf("时间  %dms\t%dms\t%dms\t%dms\t%dms\t%dms\n\n",diff11,diff12,diff13,diff14,diff15,diff16);

	for(i=0;i<N2;i++)
		b[i]=rand();
	clock_t start51 =clock();
    InsertSort(b,N2);                   
	clock_t diff51=clock()-start51;         //50000插入排序时间

	for(i=0;i<N2;i++)
		b[i]=rand();
	clock_t start52=clock();
	MergeSort(b,N2);
	clock_t diff52=clock()-start52;        //50000归并排序时间

    for(i=0;i<N2;i++)
		b[i]=rand();
	clock_t start53=clock();
	QSort_Recursion(b,0,N2-1);
	clock_t diff53=clock()-start53;       //50000快排之递归时间

    for(i=0;i<N2;i++)
		b[i]=rand();
	clock_t start54=clock();
	QSort(b,N2);
	clock_t diff54=clock()-start54;       //50000快排之非递归时间

    for(i=0;i<N2;i++)
		b[i]=rand();
	clock_t start55=clock();
	CountSort(b,N2);
	clock_t diff55=clock()-start55;       //50000计数排序时间

    for(i=0;i<N2;i++)
		b[i]=rand();
	clock_t start56=clock();
	RadixCountSort(b,N2);
	clock_t diff56=clock()-start56;       //50000基数排序时间

	printf("时间  %dms\t%dms\t%dms\t%dms\t%dms\t%dms\n\n",diff51,diff52,diff53,diff54,diff55,diff56);

	for(i=0;i<N3;i++)
		c[i]=rand();
	clock_t start21 =clock();
    InsertSort(c,N3);                   
	clock_t diff21=clock()-start21;         //200000插入排序时间

	for(i=0;i<N3;i++)
		c[i]=rand();
	clock_t start22=clock();
	MergeSort(c,N3);
	clock_t diff22=clock()-start22;        //200000归并排序时间

    for(i=0;i<N3;i++)
		c[i]=rand();
	clock_t start23=clock();
	QSort_Recursion(c,0,N3-1);
	clock_t diff23=clock()-start23;       //200000快排之递归时间

    for(i=0;i<N3;i++)
		c[i]=rand();
	clock_t start24=clock();
	QSort(c,N3);
	clock_t diff24=clock()-start24;       //200000快排之非递归时间

    for(i=0;i<N3;i++)
		c[i]=rand();
	clock_t start25=clock();
	CountSort(c,N3);
	clock_t diff25=clock()-start25;       //200000计数排序时间

    for(i=0;i<N3;i++)
		c[i]=rand();
	clock_t start26=clock();
	RadixCountSort(c,N3);
	clock_t diff26=clock()-start26;       //200000基数排序时间

	printf("时间  %dms\t%dms\t%dms\t%dms\t%dms\t%dms\n\n",diff21,diff22,diff23,diff24,diff25,diff26);

	clock_t start1=clock();
	for(i=0;i<100;i++)
	{
		for(j=0;j<N4;j++)
			d[N4]=rand();
		InsertSort(d,N4);
	}
	clock_t end1=clock()-start1;         //100次10万插入

	clock_t start2=clock();
	for(i=0;i<100;i++)
	{
		for(j=0;j<N4;j++)
			d[N4]=rand();
		MergeSort(d,N4);
	}
	clock_t end2=clock()-start2;         //100次10万归并

	clock_t start3=clock();
	for(i=0;i<100;i++)
	{
		for(j=0;j<N4;j++)
			d[N4]=rand();
		QSort_Recursion(d,0,N4);
	}
	clock_t end3=clock()-start3;         //100次10万快排之递归

	clock_t start4=clock();
	for(i=0;i<100;i++)
	{
		for(j=0;j<N4;j++)
			d[N4]=rand();
		QSort(d,N4);
	}
	clock_t end4=clock()-start4;         //100次10万快排之非递归

	clock_t start5=clock();
	for(i=0;i<100;i++)
	{
		for(j=0;j<N4;j++)
			d[N4]=rand();
		CountSort(d,N4);
	}
	clock_t end5=clock()-start5;         //100次10万计数


	clock_t start6=clock();
	for(i=0;i<100;i++)
	{
		for(j=0;j<N4;j++)
			d[N4]=rand();
		RadixCountSort(d,N4);
	}
	clock_t end6=clock()-start6;         //100次10万基数




	printf("时间  %dms\t%dms\t%dms\t%dms\t%dms\t%dms\n\n",end1,end2,end3,end4,end5,end6);
	getchar();
	getchar();
	return 0;
}

/*
*插入排序
*/
void InsertSort(int *s,int n)                 //插入排序
{
	int i,j=0,t=0;
	for(i=1;i<n;i++)
	{
		t=*(s+i);
		j=i-1;
		while(j>=0&&t<*(s+j))
		{
			*(s+j+1)=*(s+j);
			j--;
		}
		*(s+j+1)=t;
	}
}
/*
*归并排序
*/

void merging(int *list1,int list_size1,int *list2,int list_size2)   //归并之并
{
	int i,j,k,m,size;
	i=j=k=0;
    size=list_size1+list_size2;
	int temp[200000];                                        //

	while(i<list_size1&&j<list_size2)
	{
		if(list1[i]<list2[j])
			temp[k++]=list1[i++];
		else
			temp[k++]=list2[j++];
	}
	while(i<list_size1)
		temp[k++]=list1[i++];
	while(j<list_size2)
		temp[k++]=list2[j++];
	for(m=0;m<size;m++)
		list1[m]=temp[m];
}

void MergeSort(int *s,int n)
{
    void merging(int *list1,int list_size1,int *list2,int list_size2);   
	int list_size1,list_size2;
	int *list1,*list2;
	if(n>1)
	{
	    list1=s;                        //数组分半
        list_size1=n/2;
		list2=s+n/2;
		list_size2=n-list_size1;

		MergeSort(list1,list_size1);    //递归拆分                     
		MergeSort(list2,list_size2);
		merging(list1,list_size1,list2,list_size2);              //并
	}
}
/*
*计数排序
*/
void CountSort(int *s,int n)                                   
{
	int i,j=0,t=0,min,max;
	min=max=s[0];
	for(i=1;i<n;i++)
	{
		if(s[i]<min)
			min=s[i];
		else if(s[i]>max)
			max=s[i];
	}
	int range=max-min+1;
	int *count=(int *)malloc(range*sizeof(int));
	for(i=0;i<range;i++)
		count[i]=0;
	for(i=0;i<n;i++)
		count[s[i]-min]++;
	for(i=min;i<=max;i++)
		for(j=0;j<count[i-min];j++)
			s[t++]=i;
	free(count);
}

/*
*基数计数排序
*/

void RadixSort(int *index,int *a,int len)  
{  
    int i;  
    int *count=(int *)malloc(sizeof(int)*10);  

    for(i=0;i<10;i++)  
    {  
        count[i]=0;  
    }  

    for(i=0;i<len;i++)  
    {  
        count[index[i]] ++;  
    }  

    for(i=1;i<10;i++)  
    {  
        count[i]=count[i] + count[i - 1];  
    }  

    int *sort=(int *)malloc(sizeof(int)*len);  

    for(i=len-1;i>=0;i--)  
    {  
        count[index[i]] --;  
        sort[count[index[i]]] = a[i];  
    }  

    for(i=0;i<len;i++)  
    {  
        a[i]=sort[i];  
    }  

    free(sort);  
    free(count);  
}  

void RadixCountSort(int *a,int len)  
{  
    int i , x=1;  
    int tmp=1;  
    int *radix=(int *)malloc(sizeof(int)*len);  

    while(x)  
    {  
        tmp=tmp * 10;  
        x=0;  

        for(i=0;i<len;i++)  
        {  
            radix[i]=a[i] % tmp;  
            radix[i]=radix[i] / (tmp / 10);  
            if(a[i] / tmp > 0)  
            {  
                x = 1;  
            }  
        }  

        RadixSort(radix,a,len);  
    }  
    free(radix);  
} 

/*
*快速排序之递归版
*/
int partition(int arr[],int low,int high)
{
	int key;
	key=arr[low];
	while(low<high)
	{
		while(low<high&&arr[high]>=key)
			high--;
		if(low<high)
			arr[low++]=arr[high];
		while(low<high&&arr[low]<=key)
			low++;
		if(low<high)
			arr[high--]=arr[low];
	}
	arr[low]=key;
	return low;
}
void QSort_Recursion(int arr[],int start,int end)         //end=N-1
{
	int pos;
	if(start<end)
	{
		pos=partition(arr,start,end);
        QSort_Recursion(arr,start,pos-1);
        QSort_Recursion(arr,pos+1,end);
	}
}

/*
*快速排序之非递归版
*/
void QSort(int* A,int n)
{
	struct sbe
	{
		int start;
		int end;
	};
	sbe* arr = new sbe[n];
	int m=0;
	int p;
	int start,end,i,j,t=0;
    arr[0].start=0;
	arr[0].end=n-1;
	for( ; ; )
	{
		if(m<0)
			break;
		start=arr[m].start;
		end=arr[m--].end;
		if(start>=end)
			continue;

		p=A[start];
		i=start;
		j=end+1;
		for(;;)
		{
			while(++i<=end&&A[i]<p);
			while(A[--j]>p);
			if(i>j)
				break;
            t=A[i];A[i]=A[j];A[j]=t;
		}
        t=A[j];A[j]=A[start];A[start]=t;
		arr[++m].start=start;
		arr[m].end =j-1;
		arr[++m].start=j+1;
		arr[m].end=end;
	}

}

		