//static声明后，重复声明不会改变该变量的值，即代码中m。

#include <stdio.h>

void example(void)
{
    int n = 10;
    static int m = 10;

    printf("n=%d\n", n);
    n++;
    printf("n++=%d\n", n);

    printf("m=%d\n", m);
    m++;
    printf("m++=%d\n", m);
}
int main(void)
{
    example();
    printf("--------------------\n");
    example();
    printf("--------------------\n");
    example();
    return 0;
}
