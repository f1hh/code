#include <stdio.h>
int a = 10;
int add(int b)
{
    a = a + b;
    printf("%d ", a);
    return a;
}
int main(void)
{
    int a = 20;
    int b = 2;
    int c = add(b);
    a = a + b;
    printf("%d", a);
    return 0;
}
