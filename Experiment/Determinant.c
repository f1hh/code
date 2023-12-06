#include<stdio.h>
int main(void)
{
    int det[3][3];
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            scanf("%d", &det[i][j]);
        }
    }
    int ans1,ans2,ans;
    ans1 = det[0][0] * det[1][1] * det[2][2] + det[0][1] * det[1][2] * det[2][0] + det[1][0] * det[2][1] * det[0][2];
    ans2 = det[0][2] * det[1][1] * det[2][0] + det[0][1] * det[1][0] * det[2][2] + det[0][0] * det[1][2] * det[2][1];
    ans = ans1 - ans2;
    printf("answer is:  %d", ans);
}