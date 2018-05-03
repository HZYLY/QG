#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
void InsertSort(int *s, int n);                 //插入排序

void merging(int *list1,int list_size1,int *list2,int list_size2);   //归并之并
void MergeSort(int *s,int n);                         //归并


void CountSort(int *s,int n);                         //计数

void RadixSort(int *index,int *a,int len);  
void RadixCountSort(int *a,int len);                 //基数

int partition(int arr[],int low,int high);
void QSort_Recursion(int arr[],int start,int end);         //快排之递归  end=N-1

void QSort(int* A,int n);                              //快排之非递归

#endif 
