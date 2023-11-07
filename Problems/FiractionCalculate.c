//用于分数的加减计算

#include <stdio.h>
long long gcd(long long x, long long y) // 最大公约数计算
{
    return y ? gcd(y, x % y) : x;
}

int main(void)
{
    long long n,sum1 = 0, sum2 = 1, g;
    scanf("%d", &n);                // 输入数字个数
    while(n--)
    {
        long long a = 0, b = 0;
        scanf("%lld/%lld", &a, &b);     // 继续输入数字
        sum1 = sum1 * b + sum2 * a; // 分子分母通分
        sum2 = sum2 * b;
        if(sum1!=0){
            g = (sum1 > sum2) ? gcd(sum1, sum2) : gcd(sum2, sum1);
            sum1 = sum1 / g;
            sum2 = sum2 / g;
        }
    }
   if (sum1 % sum2==0){//分情况输出，假分数，整数，真分数
            printf("%lld", sum1 / sum2);//整数
    }
    else{                          //假分数,真分数
            if (sum1 < sum2) {
                printf("%lld/%lld", sum1, sum2);
                }
            else{
                printf("%lld ", sum1 / sum2);
                printf("%lld/%lld", sum1%sum2, sum2);
            }
    }
}