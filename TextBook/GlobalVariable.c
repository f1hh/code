//关注a变量在代码中的作用

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
    int a = 20;//这里的a无法在add函数中使用
    int b = 2;
    add(b);
    a = a + b;//局部变量和全局变量同名，范围内以局部变量为准
    printf("%d", a);
    return 0;
}