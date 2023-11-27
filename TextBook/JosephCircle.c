//约瑟夫环问题

#include <stdio.h>
int main()
{
    void countAndOut(int *, int);
    int i, n, num[50];
    scanf("%d", &n); 
    for (i = 0; i < n; i++)
        num[i] = i + 1;
    countAndOut(num, n);
    return 0;
}

void countAndOut(int array[], int n)
{
    int flag = 0, i = 0, j, m = n;
    while (m - 1)       //控制循环至只剩下一个元素
    {
        i = i % n;
        if (array[i])       //当前值不为零，即未被踢出，所有报数操作的前提是报数人还在圆中
        {                       
            flag++;     //注意flag的位置，只有该元素没有被踢出时才可以对当前flag计数
            if (flag == 3)
            {
                flag = 0;
                array[i] = 0;
                m--;
            }
        }
        i++;
    }
    for (j = 0; j < n; j++)
    {
        if (array[j])
            break;
    }
    printf("The last one is NO.%d\n", array[j]);
}