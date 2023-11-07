#include <stdio.h>

#define SIZE 6

//快速排序
void quick_sort(int num[], int low, int high)
{
    int i, j, temp;
    int tmp;

    i = low;
    j = high;
    tmp = num[low]; //任命为中间分界线，左边比他小，右边比他大,通常第一个元素是基准数

    if (i > j) //如果下标i大于下标j，函数结束运行
    {
        return;
    }

    while (i != j)
    {
        while (num[j] >= tmp && j > i)//从后往前找到第一个小于等于标准数的数
        {
            j--;
        }

        while (num[i] <= tmp && j > i)//从前往后找到第一个大于等于标准数的数
        {
            i++;
        }

        if (j > i)//交换这两个数
        {
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
    }
    //此时i与j指向同一个位置，且这个位置对应的数字小于标准数字

    num[low] = num[i];//tmp是最后一次交换所对应的数字，将标准数字放在i位置
    num[i] = tmp;

    quick_sort(num, low, i - 1);//递归调用函数
    quick_sort(num, i + 1, high);
}

int main(void)
{
    //创建一个数组
    int num[SIZE] = {0};
    int i;

    //输入数字
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &num[i]);
    }

    quick_sort(num, 0, SIZE - 1);

    for (i = 0; i < SIZE; i++)
    {
        printf(" %d ", num[i]);
    }

    return 0;
}