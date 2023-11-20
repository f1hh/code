#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    srand((unsigned int)time(NULL));//生成随机数种子
    int i,j=0,sum1=0,sum2=0;
    int wro[6]={0,0,0,0,0,0};              //存放错误的题号
    printf("请直接输入答案\n");
    for(i=1;i<=5;i++){
        int Symbol=0,x1=0,x2=0,a;
        Symbol=rand()%2;                 //随机生成0或1，0代表加法，1代表减法
        if (Symbol==0){                     //处理加法
            x1=1+rand()%8;                 //x1属于1~8
            x2=1+rand()%(9-x1);          //x2范围随x1变化
            printf("%d + %d = ?\n",x1,x2);
            scanf("%d",&a);
            if((a)==(x1+x2)){               //判断是否答对,正确则正确题数加一，错误则记录错误题号
                sum1+=1;
            }
            else{
                wro[sum2]=i;
                sum2+=1;
            }            
        }
        else{                               //处理减法
            x1=2+rand()%8;          //x1属于2~9
            x2=1+rand()%(x1-1);
            printf("%d - %d = ?\n",x1,x2);
            scanf("%d",&a);
            if(a==(x1-x2)){             //判断是否答对,正确则正确题数加一，错误则记录错误题号
                sum1+=1;
            }
            else{
                wro[sum2]=i;
                sum2+=1;
            }
        }                
    }
    printf("你的最终得分为：%d\n",sum1*20);//输出最终得分
    if(sum2!=0){                        //输出错误的题号
        printf("你的错误题号为：");
        while(wro[j]!=0){
        printf("%d  ",wro[j]);
        j++;
        }
    }
    printf("\n");
    getchar();
}