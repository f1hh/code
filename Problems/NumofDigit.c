//对 N 中每一种不同的各位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

#include<stdio.h>
int main(void)
{
	int num[] = {0,0,0,0,0,0,0,0,0,0};
	char a[1001];
	int n,i=0,j;
	scanf("%s", a);
	while (a[i] != '\0') {
		n = a[i] - '0';
		num[n] += 1;
		i++;
	}
	for (j = 0; j <= 9; j++) {
		if (num[j] != 0) {
			printf("%d:%d\n", j, num[j]);
		}
	}
	getch();
}