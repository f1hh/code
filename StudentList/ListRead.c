#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    char name[11];
    float course[3];
} Stu;

int main(void)
{
    FILE *fpr, *fpw;
    Stu stl[10];

    if ((fpr = fopen("student.txt", "r")) == NULL)
    {
        printf("File open error!");
        exit(0);
    }

    if ((fpw = fopen("student_new.txt", "w")) == NULL)
    {
        printf("File open error!");
        exit(0);
    }

    char c;
    while ((c = fgetc(fpr)) != '\n')
    {
    } // skip the first line
    c = fgetc(fpr);

    int i = 0;
    while (!feof(fpr))
    {
        fscanf(fpr, "%d", &stl[i].num);
        fscanf(fpr, "%s", stl[i].name);
        fscanf(fpr, "%f%f%f", &stl[i].course[0], &stl[i].course[1], &stl[i].course[2]);
        i++;
    }
    i--;
    printf("Add student's information:\n");
    scanf("%d", &stl[i].num);
    scanf("%s", stl[i].name);
    scanf("%f %f %f", &stl[i].course[0], &stl[i].course[1], &stl[i].course[2]);

    printf("\n\nNO.        Name      Score1      Score2      Score3\n\n");
    fprintf(fpw, "NO.        Name      Score1      Score2      Score3\n\n");
    for (int j = 0; j <= i; j++)
    {
        fprintf(fpw, "%d", stl[j].num);
        fprintf(fpw, "%11s", stl[j].name);
        fprintf(fpw, "%12.2f%12.2f%12.2f\n\n", stl[j].course[0], stl[j].course[1], stl[j].course[2]);
        printf("%d", stl[j].num);
        printf("%11s", stl[j].name);
        printf("%12.2f%12.2f%12.2f\n\n", stl[j].course[0], stl[j].course[1], stl[j].course[2]);
    }

    fclose(fpr);
    fclose(fpw);
    system("pause");
}