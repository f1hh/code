//九九乘法表

#include <stdio.h>
int main(void)
{
    int i, j, k, sum = 0;
    for (i = 2; i <= 1000; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("%d,其因子为", i);
            for (k = 1; k < i; k++)
            {
                if (i % k == 0)
                    printf("%d ", k);
            }
            printf("\n");
        }
    }
}