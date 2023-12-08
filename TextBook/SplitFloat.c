//实现一个拆分实数的整数与小数部分的简单函数。

#include <stdio.h>

void splitfloat(float x, int *intpart, float *fracpart);

int main()
{
    float x, fracpart;
    int intpart;

    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);

    return 0;
}

void splitfloat(float x, int *intpart, float *fracpart)
{
    *intpart = (int)x;//注意
    *fracpart = x - *intpart;
}