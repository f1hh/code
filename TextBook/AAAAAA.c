#include <stdio.h>
int hcf(int u, int v)
{
    return v ? hcf(v, u % v) : u;
}

int lcd(int u, int v, int h)
{
    return u * v / h;
}

int main(void)
{
    int a, b;
    scanf("%d,%d", &a, &b);
    if (a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
    int h = hcf(a, b);
    int l = lcd(a, b, h);
    printf("H.C.F=%d\nL.C.D=%d\n", h, l);
}