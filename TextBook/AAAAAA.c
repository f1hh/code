#include <stdio.h>
int main()
{
    int m[3][3];
    printf("矩阵：\n");
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            scanf("%d", &m[i][j]);
        }
    }
    printf("对角线和是：%d", m[1][1] + m[0][0] + m[2][2]);
}
