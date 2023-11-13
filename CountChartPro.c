//记录二维字符串数组中的字符个数
//笔记：在使用gers()函数时，记得将数组降维后再使用，使用scanf读入时，记得吃掉末尾的回车键
//具体scanf，gets，getchar函数区别参考网址https://zhuanlan.zhihu.com/p/440145616

#include "stdio.h"
void main()
{
    char a[4][11], c;
    int l = 0, u = 0, d = 0, o = 0, s = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            scanf("%c", &a[i][j]);
        }
        getchar();
        // gets(a[i]);//若用此函数则无需getchar
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            c = a[i][j];
            if (c >= 'a' && c <= 'z')
                l++;
            else if (c >= 'A' && c <= 'Z')
                u++;
            else if (c >= '0' && c <= 'z')
                d++;
            else if (c == ' ')
                s++;
            else
                o++;
        }
    }
    printf("upper case:%d\nlower case:%d\ndigit:%d\nspace:%d\nother:%d", u, l, d, s, o);
}