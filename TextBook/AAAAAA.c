#include <stdio.h>
void Rev(int *x, int n);

int main()
{
    int i, a[10] = {3, 7, 9, 11, 0, 6, 7, 5, 4, 2};
    int *p;
    a++;
    Rev(a, 10);
    printf("The array has been reverted:\n");
    for (
        p = a; p < a + 10;
        p++)
        printf("%d,", *p);
    return 0;
}
