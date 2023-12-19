#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    printf("请分别输入矩阵1的行列数：\n");
    int x1, y1;
    scanf("%d %d", &x1, &y1);
    int **m1=malloc(x1*sizeof(int));
    for (int i = 0; i < x1;i++){
        m1[i] = malloc(y1 * sizeof(int));
    }
        printf("请输入矩阵1：\n");
    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1;j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }
    printf("请分别输入矩阵2的行列数：\n");
    int x2, y2;
    scanf("%d %d", &x2, &y2);
    int **m2=malloc(x2*sizeof(int));
    for (int i = 0; i < x2; i++)
    {
        m2[i] = malloc(y2 * sizeof(int));
    }
    printf("请输入矩阵1：\n");
    for (int i = 0; i < x2; i++)
    {
        for (int j = 0; j < y2; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }
    if(y1!=x2)
        printf("矩阵无法相乘");
    else{
        printf("乘积是:\n");
        for (int i = 0; i < x1; i++)
        {
            for (int j = 0; j < y2;j++)
            {
                int sum = 0;
                for (int k = 0; k < x2;k++)
                {
                    sum += m1[i][k] * m2[k][j];
                }
                printf("%d ", sum);
            }
            printf("\n");
        }
    }
}