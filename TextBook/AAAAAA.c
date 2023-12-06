#include <stdio.h>
void Rev(int *x, int n);

int main()
{
    int i, a[10] = {3, 7, 9, 11, 0, 6, 7, 5, 4, 2};
    int *p;

    Rev(a, 10);
    printf("The array has been reverted:\n");
    for (
        p = a; p < a + 10;
        p++)
        printf("%d,", *p);
    return 0;
}
void Rev(int *x, int n)
{
    int t, *p, *i, *j, m = (n - 1) / 2;
    i = x;
    j = x + n - 1;
    p = x + m;
    for (; i <= p; i++, j--)
    {
        t = *i;
        *i = *j;
        *j = t;
    }
}