// 在给定的区间 [m,n] 内，查找素数 p、q、r（p<q<r），使得 pq+r、qr+p、rp+q 均是素数。

#include <stdio.h>
#include <math.h>
int pr(int x)//质数判断函数
{
    int flag = 1;
    for (int r = 2; r <= sqrt(x); r++)
    {
        if (x % r == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main(void)
{
    int p[10000] = {0}, m, n, l = 0;
    scanf("%d %d", &m, &n);
    m = (m > 1) ? m : 2;
    for (int q = m; q <= n; q++)//在数组中记录区间内的质数
    {
        if (pr(q))
        {
            p[l] = q;
            l++;
        }
    }
    int sum = 0;
    for (int i = 0; i <= l - 1; i++)//遍历符合条件的数，初始化就j，k的值有讲究，可以防止重复
    {
        for (int j = i; j <= l - 1; j++)
        {
            for (int k = j; k <= l - 1; k++)
            {
                if (pr(p[i] * p[j] + p[k]) && pr(p[i] * p[k] + p[j]) && pr(p[k] * p[j] + p[i]))
                    sum++;
            }
        }
    }
    printf("%d\n", sum);
}

//此算法可以节约时间成本，原本使用暴力遍历，但数据过多。可以考虑先记录质数，再对记录的质数进行处理
