#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
void InsertSort(int *s, int n);                 //��������

void merging(int *list1,int list_size1,int *list2,int list_size2);   //�鲢֮��
void MergeSort(int *s,int n);                         //�鲢


void CountSort(int *s,int n);                         //����

void RadixSort(int *index,int *a,int len);  
void RadixCountSort(int *a,int len);                 //����

int partition(int arr[],int low,int high);
void QSort_Recursion(int arr[],int start,int end);         //����֮�ݹ�  end=N-1

void QSort(int* A,int n);                              //����֮�ǵݹ�

#endif 
