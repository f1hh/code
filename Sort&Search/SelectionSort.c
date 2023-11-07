#include <stdio.h>
int main(void)
{
    int arr[10];
    printf("The orginal numbers:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        printf("%5d", arr[i]);
    }
    printf("\nThe sorted numbers:\n");
    for (int j = 0; j <= 9; j++)
    {
        int t = j;//选择用于比较的标准元素
        for (int k = j + 1; k <= 9; k++)
        {
            if (arr[k] < arr[t])//在后续元素中找到比标准元素小的元素
            {
                int temp = arr[k];//进行元素的交换
                arr[k] = arr[t];
                arr[t] = temp;
            }
        }
    }
    for (int k = 0; k <= 9; k++)
    {
        printf("%5d", arr[k]);
    }
}