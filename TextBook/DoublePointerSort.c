//借用指向指针的指针进行排序

#include <stdio.h>
#include <string.h>
#define LINEMAX 20 //定义字符串的最大长度
int main()
{
    void sort(char **);
    int i;
    char **p, *pstr[5], str[5][LINEMAX];
    for (i = 0; i < 5; i++)
        pstr[i] = str[i]; //将第i个字符串的首地址赋予指针数组 pstr 的第i个元素
    for (i = 0; i < 5; i++)
        gets(pstr[i]);
    p = pstr;
    sort(p);
    printf("strings sorted:\n");
    for (i = 0; i < 5; i++)
        printf("%s\n", pstr[i]);
    return 0;
}

void sort(char **p)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (strcmp(*(p + j), *(p + j + 1)) > 0)//*(p+j)指向指针数组中的某一元素，其结果为指针
            {
                char *temp;//因为交换的内容为指针交换，所以第三变量为指针变量
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
}