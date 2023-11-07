#include <stdio.h>
int main(void)
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    int n;
    scanf("%d", &n);
    int l = 0, r = 9;
    while (l <= r)
    {
        if (a[(l + r) / 2] <= n)
        {
            r = (l + r) / 2 - 1;
        }
        else if (a[(l + r) / 2] > n)
        {
            l = (l + r) / 2 + 1;
        }
    }
    if (a[l] == n)
        printf("%d\n", l);
    else
        printf("无此数\n");
}