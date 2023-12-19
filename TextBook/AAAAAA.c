#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *add(int *a, int *b, int *temp)
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            *(temp + 3 * i + j) = *(a + 3 * i + j) + *(b + 3 * i + j);
    return temp;
}
int *plus(int *a, int *b, int *temp)
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            *(temp + 3 * i + j) = 0;
            for (int k = 0; k < 3; k++)
                *(temp + 3 * i + j) += *(a + 3 * i + k) * *(b + 3 * k + j);
        }
    return temp;
}
int *trans(int *a, int *temp)
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            *(temp + 3 * i + j) = *(a + 3 * j + i);
    return temp;
}
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", *(a + 3 * i + j));
        }
        printf("\n");
    }
}
int main()
{
    srand(time(NULL));
    int a[3][3], b[3][3], c[3][3], temp[3][3] = {0}, temp1[3][3] = {0}, temp2[3][3] = {0};
    int n = 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10 + 1;
            b[i][j] = rand() % 10 + 1;
            c[i][j] = rand() % 10 + 1;
        }
    printf("生成矩阵为\n");
    printf("矩阵A：\n");
    print(&a[0][0], n);
    printf("\n矩阵B：\n");
    print(&b[0][0], n);
    printf("\n矩阵C：\n");
    print(&c[0][0], n);
    printf("\n矩阵A(B+C)：\n");
    add(&b[0][0], &c[0][0], &temp[0][0]);
    plus(&a[0][0], &temp[0][0], &temp1[0][0]);
    print(&temp1[0][0], n);
    printf("\n矩阵AB+AC：\n");
    plus(&a[0][0], &b[0][0], &temp1[0][0]);
    plus(&a[0][0], &c[0][0], &temp2[0][0]);
    add(&temp1[0][0], &temp2[0][0], &temp[0][0]);
    print(&temp[0][0], n);
    printf("\n矩阵(AB)C：\n");
    plus(&temp1[0][0], &c[0][0], &temp[0][0]);
    print(&temp[0][0], n);
    printf("\n矩阵A(BC)：\n");
    plus(&b[0][0], &c[0][0], &temp1[0][0]);
    plus(&a[0][0], &temp1[0][0], &temp[0][0]);
    print(&temp[0][0], n);
    printf("\n矩阵(ABC)^T：\n");
    trans(&temp[0][0], &temp1[0][0]);
    print(&temp1[0][0], n);
    printf("\n矩阵C^T B^T A^T：\n");
    trans(&c[0][0], &temp1[0][0]);
    trans(&b[0][0], &temp2[0][0]);
    plus(&temp1[0][0],&temp2[0][0], &temp[0][0]);
    trans(&a[0][0], &temp1[0][0]);
    plus(&temp[0][0], &temp1[0][0], &temp2[0][0]);
    print(&temp2[0][0], n);
}