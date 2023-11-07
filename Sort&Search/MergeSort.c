#include <stdio.h>
#define ArrLen 20//自定义变量可以方便修改数组大小
void printList(int arr[], int len)//打印数组数据
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
}
void merge(int arr[], int left, int mid, int right)//将两个有序数组合并
{                                                                  //传入无序数组，左、中、右位置
    int AtempArr[ArrLen];//定义一个用来拷贝数据并处理的替换数组
    int k = 0;
    int p_left = left;//记录分隔后左边数组起始位置
    int p_mid = mid + 1;//记录分隔后右边数组的起始位置
    while (p_left <= mid && p_mid <= right)//将两个数组合并起来，使其成为一个有序数组
    {               //对两数组中元素根据大小逐一压出
        if (arr[p_left] < arr[p_mid])
        {
            AtempArr[k++] = arr[p_left++];
        }
        else
        {
            AtempArr[k++] = arr[p_mid++];
        }
    }
    //对两数组处理完后有剩余元素的数组进行处理；只会执行一个while循环
    while (p_mid <= right)
        AtempArr[k++] = arr[p_mid++];
    while (p_left <= mid)
        AtempArr[k++] = arr[p_left++];
    //将处理后成为有序的替换数组中的元素重新放入arr数组中
    for (int i = 0, p_left = left; i < k; p_left++, i++)
    {
        arr[p_left] = AtempArr[i];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)//当只有一个元素时已经有序，直接返回
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);//分隔数组
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(void)
{
    int arr[] = {4, 7, 6, 5, 2, 1, 8, 2, 9, 1};
    mergeSort(arr, 0, 9);
    printList(arr, 10);
}