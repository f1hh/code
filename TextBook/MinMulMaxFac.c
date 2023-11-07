//最大公因数与最小公倍数求值

#include<stdio.h>
int main(void)
{
    int a,b,c,d,max=0,min=0,i;
    scanf("%d %d",&a,&b);
    c=(a>b)?b:a;
    d=(a>b)?a:b;
    for(i=1;i<=c;i++)
    {
        if(a%i==0&&b%i==0&&i>max)max=i;
    }
    for(int j=d; ;j++)
    {
        if(j%a==0&&j%b==0){min=j;break;}
    }
    printf("%d %d\n",max,min);//最大公因数，最小公倍数
}