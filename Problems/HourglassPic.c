//打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数

#include<stdio.h>
int main(void)
{
    int i, j, k, l, n, o, p, x,leftn;
    char c;
    scanf("%d %c", &n, &c);
    for (i = 1; i <= 31; i++) {		//calculate thr number of rows in the triangle
        if ((2 * i * i - 1) > n)break;
    }
    i = i - 1;

    leftn = n - (2 * i * i - 1);		//calculate the remaining number

    for (j = 0; j < i - 1; j++) {					//picture thr top triangle
        for (k = 1; k <= j; k++) { printf(" "); }
        for (l = 1; l <= (2 * i - 1 - 2 * j); l++) { printf("%c", c); }
        printf("\n");
    }

    for (x = 1; x <= i - 1; x++) { printf(" "); }		//deal with the mid one character
    printf("%c", c);
    printf("\n");

    for (n = i - 1; n > 0; n--) {				//picture the battom triangle
        for (o = 1; o <= n - 1; o++) { printf(" "); }
        for (p = 1; p <= 2 * i - 1 - (n - 1) * 2; p++) { printf("%c", c); }
        printf("\n");
    
    }
    printf("%d\n",leftn);
    getch();
}