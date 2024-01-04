#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 10

void matrix(int mat[max][max], int order);
void print(int mat[max][max], int order);
void adjoint(int mat[max][max], int adj[max][max], int order);
int det(int mat[max][max], int n);
void getA(int mat[max][max], int temp[max][max], int p, int q, int n);

int main()
{
    int mat[max][max], adj[max][max];
    srand(time(NULL));
    int order = rand() % 10 + 1;
    matrix(mat, order);
    printf("原矩阵:\n");
    print(mat, order);
    adjoint(mat, adj, order);
    printf("\a伴随矩阵:\n");
    print(adj, order);

    return 0;
}

void matrix(int mat[max][max], int order)
{
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            mat[i][j] = rand() % 10; // 生成0到9的随机数
        }
    }
}

void print(int mat[max][max], int order)
{
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void adjoint(int mat[max][max], int adj[max][max], int order)
{
    if (order == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[max][max];
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            getA(mat, temp, i, j, order);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (det(temp, order - 1));
        }
    }
}

int det(int mat[max][max], int n)
{
    int D = 0;

    if (n == 1)
        return mat[0][0];
    int temp[max][max];
    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        getA(mat, temp, 0, f, n);
        D += sign * mat[0][f] * det(temp, n - 1);
        sign = -sign;
    }
    return D;
}

void getA(int mat[max][max], int temp[max][max], int p, int q, int n)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
