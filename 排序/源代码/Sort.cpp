#include<stdio.h>
#include<stdlib.h>
#include "Sort.h"
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