#include<stdio.h>
#include<string.h>

struct student
{
    int nNumber;             // 学号,4位
    char szName[20];  // 姓名，2-3个汉字
    float fScore[3]; // 学生几门课的成绩
    float fAveScore;         // 平均分
    float fSumScore;         // 总成绩
};
 int main(void){
     struct student a[2];
     a[0].nNumber = 1111;
     strcpy(a[0].szName,"大傻逼");
     a[0].fScore[0] = 99;
     a[0].fScore[1] = 99;
     a[0].fScore[2] = 99;
     a[1].fScore[0] = 99;
     a[1].fScore[1] = 99;
     a[1].fScore[2] = 99;
     strcpy(a[1].szName, "小傻逼");
     a[1].nNumber = 2222;
     char c[3][20] = {"语文", "数学", "英语" };
     printf("======================================\n");
     printf("学号  姓名");
     for (int i = 0; i < 3;i++){
         printf("\t%s", c[i]);
     }
     printf("\n");
 }