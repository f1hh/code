//辗转相除法求最大公约数（FiractionCalculation.c使用递归）

#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    printf("%d", b); //将除数输出
    return 0;
}
