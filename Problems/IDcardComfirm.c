//通过检测身份证的位数，中间是否有数字，以及校验码的正确性来检测身份证的合法性

#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, x[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};//各位数权重
    char check[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};//检测值
    scanf("%d", &n);
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 1;//是否合法标识符
        char id[19];
        scanf("%s", id);
        if (strlen(id) != 18)//长度
            flag = 0;
        for (int l = 0; l < 17; l++) // 判断前17位是否有非数字项
        {
            if (id[l] < '0' || id[l] > '9')//检测中间是否有数字
                flag = 0;
        }
        int sum = 0, z;
        for (int j = 1; j <= 17; j++)
        {
            sum += (id[j - 1] - '0') * x[j - 1];//计算权重
        }
        z = sum % 11;
        if (id[17] != check[z])
            flag = 0;
        if (flag == 0)
            printf("%s\n", id);//输出不符合要求的身份证
        else
            a++;
    }
    if (n == a)
        printf("All passed\n");//若全部都符合则输出全通过
}