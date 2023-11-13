//查找鞍点，一行中最大的，一列中最小的数

#include <stdio.h>
void main()
{
    int c, r, a[100][100];
    scanf("%d %d", &r, &c);//输入行列数
    for (int i = 0; i < r; i++)//输入二维数组数字
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int mi = 0, mj = 0, flag = 0;//分别记录可能数值所在位置，flag为标签
    for (int i = 0; i < r; i++)
    {
        int f = 1;//标签
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] > a[mi][mj])//先查找一行中的最大值
            {
                mi = i;
                mj = j;
            }
        }
        for (int k = 0; k < r; k++)//再遍历潜在数值对应列中，该数是否是最小的
        {
            if (a[k][mj] < a[mi][mj])//不是最小的，标签f置0
                f = 0;
        }
        if (f)
        {
            printf("a[%d][%d]=%d\n", mi, mj, a[mi][mj]);
            flag = 1;
        }
    }
    if (!flag)
        printf("不存在鞍点\n");
}