#include<stdio.h>
void quicksort(int arr[],int p,int r){
    int q = p;//p为大小区域的划分指针，p-1之前的小，p之后的大，q为未知区域的指针
    if(p>q)
        return;
    else{
        if(arr[q]>arr[k]){
            p++;
            q++;
        }
        else{
            int temp = arr[q];
            arr[q] = arr[p];
            arr[p] = temp;
        }
    }
}