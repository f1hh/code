//使数字反向输出
//递归调用的过程，参见convert函数

#include <stdio.h>
int main()
{
    void convert(int n);
    int number;
    // printf("input an integer: ");
    scanf("%d", &number);
    printf("output: ");
    if (number < 0)
    {
        putchar('-');
        putchar(' '); // 先输出一个‘-’号和空格
        number = -number;
    }
    convert(number);
    printf("\n");
    return 0;
}

void convert(int n)
{
    if (n > 10)
        convert(n / 10);
    printf("%c ", '0' + n % 10);
}