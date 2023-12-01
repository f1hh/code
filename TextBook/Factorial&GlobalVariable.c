#include <stdio.h>
double fac();
int main(void)
{
    int i, n;
    double Sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        Sum += 1 / fac();
    }
    printf("S=1/1!+1/2!+...+1/%d!=%.15f", n, Sum);
    return 0;
}

double fac()
{
    static int m = 1;//利用全局变量计算阶乘，即使下次进入此函数，m仍会保留上次的值
    double d = 1;
    for (int i = 1; i <= m; i++)
    {
        d *= i;
    }
    m++;
    return d;
}