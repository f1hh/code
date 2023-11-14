#include <stdio.h>
int main()
{
    char a[40] = {0}, b[20] = {0};
    int i = 0, j = 0, k = 0, m = 0;
    scanf("%s", a);
    scanf("%s", b);
    while (a[i] != '\0')
    {
        i++;
    }
    while (b[j] != '\0')
    {
        a[i++] = b[j++];
    }
    printf("%s\n", a);
    return 0;
}