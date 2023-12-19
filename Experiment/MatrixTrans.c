#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    srand(time(NULL));
    int row, col;
    row = rand() % 10 + 1;
    col = rand() % 10 + 1;
    int **mat = malloc(row * sizeof(int));
    int **mat_t = malloc(col * sizeof(int));
    for (int i = 0; i < row;i++)
    {
        mat[i] = malloc(col * sizeof(int));
    }
    for (int i = 0; i < col; i++)
    {
        mat_t[i] = malloc(row * sizeof(int));
    }
    printf("原矩阵为：\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = (int)rand() % 10;
            mat_t[j][i] = mat[i][j];
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    printf("转置后的矩阵为：\n");
    for (int i = 0; i < col;i++)
    {
        for (int j = 0; j < row;j++)
        {
            printf("%5d", mat_t[i][j]);
        }
        printf("\n");
    }
}