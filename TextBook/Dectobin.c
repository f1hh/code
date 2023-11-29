//用递归实现十进制转换为二进制。
#include <stdio.h>

void dectobin(int n);
int main()
{
    int n;
    scanf("%d", &n);
    dectobin(n);
    return 0;
}

void dectobin(int n)
{
    if (n < 2)
        printf("%d", n);
    else
    {
        dectobin(n / 2);//注意printf函数与递归入口的先后顺序
        printf("%d", n % 2);
    }
}

void dectobin(int n)
{
    if (n / 2 > 0)
        dectobin(n / 2);
    printf("%d", n % 2);
}