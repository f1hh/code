#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>

int main(void)
{
    srand(time(NULL));
    for (int i = 0; i < 50;i++)
    {
        int choice = rand() % 10;
        char food[50];
        switch(choice){
            case 0:
                strcpy(food, "麦当劳");
                break;
            case 1:
                strcpy(food, "肯德基");
                break;
            case 2:
                strcpy(food, "c");
                break;
            case 3:
                strcpy(food, "d");
                break;
            case 4:
                strcpy(food, "e");
                break;
            case 5:
                strcpy(food, "f");
                break;
            case 6:
                strcpy(food, "g");
                break;
            case 7:
                strcpy(food, "h");
                break;
            case 8:
                strcpy(food, "i");
                break;
            case 9:
                strcpy(food, "j");
                break;
        }
        printf("%s\r", food);
        for (int j = 0; j < 20;j++){
            printf("  ");
        }
        printf("\r");
        Sleep(100);
    }
}