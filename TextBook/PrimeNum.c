//用于判断是否为质数

#include<stdio.h>
int main(void)
{
    int a,i;
    scanf("%d",&a);
    if(a==2)printf("Yes");
    else{
        for(i=2;i<=a;i++){
         if(a/i==0)break;
        }
        if(i!=a)printf("No");
        else printf("Yes");}
    getch();
}