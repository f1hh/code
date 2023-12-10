#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int n=0;

int gcd(int x, int y) // 最大公约数计算
{
    return y ? gcd(y, x % y) : x;
}

int find(double **det,int i)//查找对角线一下非零元素位置
{
    for (int j = i+1; j < n;j++)
    {
        if(det[j][i]!=0)
            return j;
    }
    return -1;
}

void reset(double **det,int c)//将对角线一下元素置零
{
    int i = 0;
    for (i = c+1; i < n;i++)//行
    {
        double k;
        k = det[i][c] / det[c][c];
        for (int j = 0; j < n;j++)
        {
            det[i][j] += -k * det[c][j];
            //printf("%lf\n", det[i][j]);
        }
    }
}

int main(void)
{
    int x;
    printf("请输入行列式的阶数：\n");
    scanf("%d", &x);
    n = x;
    double **det = malloc(n * sizeof(double));
    for (int i = 0; i < n;i++)
    {
        det[i] = malloc(n * sizeof(double));
    }
    printf("请输入行列式:\n");
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            scanf("%lf", &det[i][j]);
        }
    }
    int sign = 1;
    for (int i = 0; i < n;i++)
    {
        if(det[i][i]==0)//处理对角线上的0
        {
            int r = find(det, i);
            if(r==-1)
            {
                printf("0");
                break;
            }
            for (int j = r; j > i;j--)
            {
                double *temp;
                temp = det[j];
                det[j] = det[j - 1];
                det[j - 1] = temp;
                sign = -sign;
            }
        }
        reset(det, i);
    }
    double ans=1;
    for (int i = 0; i < n;i++)
    {
        ans *= det[i][i];
    }
    printf("%.2lf", ans*sign);
    free(det);
}