#include <stdio.h>
#include <string.h>
int main()
{
    char str[80];
    void insert(char[]);
    // printf("input four digits:");
    scanf("%s", str);
    insert(str);
    return 0;
}

void insert(char str[])
{
    int len = strlen(str);
    char a[80];
    for (int i = 0; i < len - 1; i++)
    {
        a[i*2] = str[i];
        a[i*2+1] = ' ';
    }
    a[2 * len - 2] = str[len - 1];
    a[len] = '\n';
    strcpy(str, a);
}