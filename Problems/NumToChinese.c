//输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字。
//在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。

#include<stdio.h>
#include<string.h>
void main()
{
    char num[50];
    scanf("%s",num);
    int n=strlen(num);
    if(num[0]=='-')printf("fu");
    for(int i=0;i<n;i++){
        switch(num[i]){
            case '1':printf("yi");break;
            case '2':printf("er");break;
            case '3':printf("san");break;
            case '4':printf("si");break;
            case '5':printf("wu");break;
            case '6':printf("liu");break;
            case '7':printf("qi");break;
            case '8':printf("ba");break;
            case '9':printf("jiu");break;
            case '0':printf("ling");break;
        }
        if(i<=n-2)printf(" ");
    }
}