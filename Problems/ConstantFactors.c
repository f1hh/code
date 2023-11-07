//一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

#include <stdio.h>
#include<math.h>
int isprime(int x){
    for (int i = 2; i <= sqrt(x);i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}

int main(void){
    int n;
    scanf("%d", &n);
    int st=0, end=0;
    if(!isprime(n)){
    for (int i = 2; i <= sqrt(n);i++){
        int temp;
        temp = n;
        int tempst = i;
        int tempend;
        if(n%i==0){
            for (int j = i; j <= n;j++){
                if(temp%j==0){
                    temp /= j;
                }
                else{
                    tempend = j - 1;
                    break;
                }
            }
            if (tempend - tempst > end - st)
            {
                st = tempst;
                end = tempend;
            }
        }
    }
    printf("%d\n", end - st + 1);
    for (int k = st; k <= end;k++){
        printf("%d", k);
        if(k!=end)
            printf("*");
    }
    }
    else
        printf("1\n%d", n);
}