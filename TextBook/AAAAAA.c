#include <stdio.h>
int f(int n){
    printf("%d", n);
    return 0;
}

int main(void)
{
    int (*p)(int);
    p = f;
    *p(2);
}