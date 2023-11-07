#include <stdio.h>
int main()
{
    int N, i, n, a;
    scanf("%d", &N);
    getchar(); //吃掉回车
    char data[N][21];
    for (i = 0; i < N; i++)
        gets(data[i]); //输入二维数组
    scanf("%d", &n);
    getchar();
    if (n > N)
        return 0;
    char num[n + 1]; //用于比较的数组
    for (i = 0; i < n; i++)
    {
        scanf("%c", &num[i]); //空格结束输入，输入号码
        getchar();
    }
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (num[i] == data[j][17])
            {
                for (int k = 0; k < 16; k++)
                {
                    printf("%c", data[j][k]);
                }
                printf(" %c\n", data[j][19]);
            }
        }
    }
    return 0;
}