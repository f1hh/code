#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    char name[10];
    float course[3];
} Stu;

int main(void)
{
    FILE *fp;
    Stu stl[10];
    int n;
    if ((fp = fopen("student.txt", "w")) == NULL)
    {
        printf("File open error!");
        exit(0);
    }
    printf("The number of the student: ");
    scanf("%d", &n);
    printf("Add student information:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stl[i].num);
        scanf("%s", stl[i].name);
        scanf("%f %f %f", &stl[i].course[0], &stl[i].course[1], &stl[i].course[2]);
    }

    printf("NO.        Name      Score1      Score2      Score3\n\n");
    fprintf(fp, "NO.        Name      Score1      Score2      Score3\n\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d", stl[i].num);
        fprintf(fp, "%11s", stl[i].name);
        fprintf(fp, "%12.2f%12.2f%12.2f\n\n", stl[i].course[0], stl[i].course[1], stl[i].course[2]);
        printf("%d", stl[i].num);
        printf("%11s", stl[i].name);
        printf("%12.2f%12.2f%12.2f\n\n", stl[i].course[0], stl[i].course[1], stl[i].course[2]);
    }

    fclose(fp);
    system("pause");
}