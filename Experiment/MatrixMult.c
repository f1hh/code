#include<stdio.h>
#include<math.h>

int main(void)
{
    printf("请分别输入矩阵1的行列数：\n");
    int x1, y1;
    scanf("%d %d", &x1, &y1);
    int m1[x1][y1];
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
    int m2[x2][y2];
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
        for (int i = 0; i < fmin(x1, y2);i++)
        {
            for (int j = 0; j < y1;j++)
            {
                printf("%d  ", m1[i][j] * m2[j][i]);
            }
            printf("\n");
        }
    }
}