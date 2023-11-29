//递归的顺序可以理解成栈的思想，可以改变代码中的注释部分放置顺序，比较输入一个整数后结果的差异。
//递归接口后面的语句，可以理解成压出栈的时候可以执行的语句。只要不是return，后面的语句就可以执行。

#include <stdio.h>

void printdigits(int n);

int main()
{
    int n;

    scanf("%d", &n);
    printdigits(n);

    return 0;
}

void printdigits(int n)
{
    if (n < 10)
        printf("%d\n", n);
    else
    {
        printdigits(n / 10);
        printf("%d\n", n % 10);
        //printdigits(n / 10);
    }
}