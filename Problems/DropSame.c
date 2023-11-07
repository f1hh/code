// 本题要求你计算A−B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，剩下的字符组成的就是字符串A−B。
// 输入在2行中先后给出字符串A和B。两字符串的长度都不超过10，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。
//*******心得：切记字符串数组在末尾自动添加'\0'，因此要小心长度设定值。

#include <stdio.h>
#include <string.h>
    int
    main(void)
{
    char initial[10001], cut[10001], c;
    int i = 0, ni, a = 0;
    while ((c = getchar()) != '\n')
    {
        initial[a] = c;
        c = '0';
        a++;
    }
    a = 0;
    while ((c = getchar()) != '\n')
    {
        cut[a] = c;
        c = '0';
        a++;
    }
    ni = strlen(initial);
    while (cut[i] != '\0')
    {
        char c = cut[i];
        i++;
        for (int j = 0; j <= ni; j++)
        {
            if (initial[j] == c)
            {
                initial[j] = '\0';
            }
        }
    }
    for (int k = 0; k <= ni; k++)
    {
        if (initial[k] == '\0')
            continue;
        else
            printf("%c", initial[k]);
    }
    printf("\n");
}