//从键盘输入两个时间点(24小时制），输出两个时间点之间的时间间隔，时间间隔用“小时:分钟:秒”表示

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t1,t2,h1,m1,s1,h2,m2,s2,t,a,b,c;
    scanf("%d:%d:%d",&h1,&m1,&s1);
    scanf("%d:%d:%d",&h2,&m2,&s2);
    t1=h1*3600+m1*60+s1;
    t2=h2*3600+m2*60+s2;
    t=abs(t1-t2);
    a=t/3600;
    b=t/60%60;
    c=t%60;
    printf("%02d:%02d:%02d\n",a,b,c);
    getch();
}