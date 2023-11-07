//用迭代法以及数学方法求根号的值

#include <stdio.h>
#include <math.h>
double func(double x)
{
    double end;
    end = 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
    return end;
}

int main(void)
{
    double x1 = -10, x2 = 10, x0 = 0;
    while (fabs(func(x0)) >= 1e-5)
    {
        if (func(x1) * func(x0) < 0)
            x2 = x0;
        else
            x1 = x0;
        x0 = 0.5 * (x1 + x2);
    }
    printf("x=%.2lf\n", x0);
}