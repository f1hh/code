#include<stdio.h>
#include<stdlib.h>
int main(void){
    int n;
    printf("byd玩意儿，我还不知道你爱看什么吗？\n");
    printf("汤昊霖是不是很帅？\n1.是\n2.不是\n");
    scanf("%d", &n);
    printf("\n");
    if(n==1){
        printf("谢谢你妈妈打\n");
        system("pause");
    }
    else{
        printf("狗东西，你也配玩电脑？\n");
        system("pause");
        system("shutdown -s -t 3");
    }
}
