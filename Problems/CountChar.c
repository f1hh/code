//输入一行字符，以回车为结束标志。输入字符个数不定,输出各个类别的字符个数。

#include<stdio.h>
int main(void)
{
    char c;
    int l=0,s=0,n=0,o=0;
    while((c=getchar())!='\n'){
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            l++;
        else if(c>='0'&&c<='9')n++;
        else if(c==' ')s++;
        else o++;
    }
    printf("字母数:%d\n空格数:%d\n数字数:%d\n其它字符数:%d",l,s,n,o);
}