#include<easyx.h>
#include<stdio.h>
int main(void) {
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	setbkcolor(RGB(164, 225, 202));
	cleardevice();
	setfillcolor(WHITE);
	int x = 0, y = 0;
	solidcircle(x, y, 50);

	while (1) {
		char c = getchar();
		switch (c) {
			case 'w':y += 50; break;
			case 'a':x -= 50; break;
			case 's':y -= 50; break;
			case 'd':x += 50; break;
		}
		cleardevice();
		solidcircle(x, y, 50);
	}
}