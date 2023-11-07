//不同进制转换为十进制

#include<stdio.h>
#include<math.h>
#include<string.h>

int main(void)
{
	int o,end,length;/*char* str[30]*/char str[30];	 
	int Xchange(char* a,int xo,int le);		 
	int Normal(char* b,int xo,int le);		 
	int len(char* st);
	printf("请以 进制,数字 的形式输入：");			 
	scanf("%d,%s",&o,str);		//输入一个进制和对应数字 
	length=len(str);
	//length=strlen(str);
	if(o>=10){
		end=Xchange(str,o,length);  
	}
	else
		end=Normal(str,o,length);  
	printf("%d\n",end);
} 

int len(char *st)		//用于计算输入数字的长度			 
{						//可用strlen()函数替代 
	int l=0;
	while (st[l]!='\0'){
		l+=1;
		 
	}
	return l;
}

int Normal(char* a,int xo,int length)	//十以内进制计算		 
{
	int i,sum=0;
	//printf("len:%d",length);
	//puts("");
	for(i=0;i<length;i++){
		sum += (a[i] - '0')*pow(xo, length-1-i);
	}
	return sum;
}

int Xchange(char* b,int xo,int length)	//十外进制计算 
{
	int i;int sum=0;
	//printf("len:%d",length);
	//puts("");
	for(i=0;i<length;i++){
		if(b[i]>='0'&&b[i]<='9'){sum += (b[i] - '0')*pow(xo, length-1-i);}
		else if(b[i]>='A'&&b[i]<='Z'){sum+=(b[i]-'A'+10)*pow(xo,length-i-1);}	//转换进制字母为数字 
	}
	return sum;
	getch();
}