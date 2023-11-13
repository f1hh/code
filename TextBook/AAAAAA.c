#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, t;
    x = y = 3;
    t = ++x || ++y;
    printf("%d", y);
    return 0;
}