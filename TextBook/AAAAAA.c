#include <stdio.h>
int main()
{
    void countAndOut(int *, int);
    int i, n, num[50];
    // printf("\ninput number of person: n=");
    scanf("%d", &n); //输入人数，不超过50
    for (i = 0; i < n; i++)
        num[i] = i + 1;
    countAndOut(num, n);
    return 0;
}

void countAndOut(int array[], int n)
{
    int flag = 0, i = 0, j, m = n;
    while (m - 1)
    {
        i = i % n;
        flag++;
        if (flag == 3 && array[i] != 0)
        {
            flag = 0;
            array[i] = 0;
            m--;
        }
        i++;
    }
    for (j = 0; j < n; j++)
    {
        if (array[j] != 0)
            break;
    }
    printf("The last one is NO.%d\n", array[j]);
}