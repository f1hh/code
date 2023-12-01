#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct//定义一个存储学生信息的结构体
{
    char name[20];
    int id;
    float course1;
    float course2;
    float course3;
    float total;
    float avg;
} List;

List students[100];//初始化学生信息数组；
int n=0;//学生数

void addStudent(int m){//学生信息录入
    for (int i = n; i < n+m;i++){
        List s;
        printf("学生姓名：\n");
        scanf("%s", s.name);
        printf("学生学号：\n");
        scanf("%d", &s.id);
        printf("科目一：\n");
        scanf("%f", &s.course1);
        printf("科目二：\n");
        scanf("%f", &s.course2);
        printf("科目三：\n");
        scanf("%f", &s.course3);
        s.total = s.course1 + s.course2 + s.course3;
        s.avg = s.total / 3;
        students[i] = s;
        printf("-------------------------------\n");
    }
}

void deleteStudentById()//通过学号删除学生
{
    int num, i, flag = 0;
    printf("请输入要删除学生的学号：\n");
    scanf("%d", &num);
    for (i = 0; i < n;i++)
    {//查找该学生并记录索引
        if(students[i].id==num){
            flag = 1;
            break;
        }
    }
    if(!flag)
        printf("未找到该学生...");
    else 
    {
        for (int j = i; j < n - 1; j++) //通过后者前移覆盖来删除学生
        {
            students[j] = students[j + 1];
        }
    }
    n--;
}

void deleteStudentByName()//通过姓名查删除学生
{ 
    int i, flag = 0;
    char xm[20];
    printf("请输入要删除学生的姓名：\n");
    scanf("%s", xm);
    for (i = 0; i < n; i++)
    { //查找该学生并记录索引
        if (strcmp(students[i].name,xm)==0)//通过函数比较名字是否相同
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
        printf("未找到该学生...");
    else
    { 
        for (int j = i; j < n - 1; j++) //通过后者前移覆盖来删除学生
        {
            students[j] = students[j + 1];
        }
    }
    n--;
}

void printStudents()//打印所有学生信息
{
    for (int i = 0; i < n;i++)
    {
        printf("姓名：%-5s", students[i].name);
        printf("学号：%-5d", students[i].id);
        printf("科目一：%-5.2f", students[i].course1);
        printf("科目二：%-5.2f", students[i].course2);
        printf("科目三：%-5.2f", students[i].course3);
        printf("平均分：%-5.2f", students[i].avg);
        printf("总分：%-5.2f\n", students[i].total);
    }
}

void searchStudentById()//通过学号查找某一位学生信息
{
    int i,num,flag=0;
    printf("输入要查找学生学号：\n");
    scanf("%d", &num);
    for (i = 0; i < n;i++)
    {
        if(students[i].id==num)
        {
            flag = 1;//找到该学生
            break;
        }
    }
    if(flag)//输出该学生对应信息
    {
        printf("姓名：%-5s", students[i].name);
        printf("学号：%-5d", students[i].id);
        printf("科目一：%-5.2f", students[i].course1);
        printf("科目二：%-5.2f", students[i].course2);
        printf("科目三：%-5.2f", students[i].course3);
        printf("平均分：%-5.2f", students[i].avg);
        printf("总分：%-5.2f\n", students[i].total);
    }
    else
        printf("查无该学生...\n");
}

void searchStudentByName() //通过姓名查找某一位学生信息
{
    int i, flag = 0;
    char xm[20];
    printf("输入要查找学生姓名：\n");
    scanf("%s", xm);
    for (i = 0; i < n; i++)
    {
        if (strcmp(students[i].name,xm)==0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("姓名：%-5s", students[i].name);
        printf("学号：%-5d", students[i].id);
        printf("科目一：%-5f", students[i].course1);
        printf("科目二：%-5f", students[i].course2);
        printf("科目三：%-5f", students[i].course3);
        printf("平均分：%-5f", students[i].avg);
        printf("总分：%-5f\n", students[i].total);
    }
    else
        printf("查无该学生...");
}

void sortByName()//根据学生姓名排序
{
    for (int i = 0; i < n-1;i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if(strcmp(students[j].name,students[j+1].name)>0)
            {
                List temp;
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByCourse1()//根据学生科目一成绩排序
{
    for (int i = 0; i < n - 1;i++)
    {
        for (int j = 0; j < n - 1 - i;j++)
        {
            if(students[j].course1<students[j+1].course1)
            {
                List temp;
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByCourse2() //根据学生科目二成绩排序
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i;j++)
        {
            if (students[j].course2 < students[j + 1].course2)
            {
                List temp;
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByCourse3() //根据学生科目三成绩排序
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i;j++)
        {
            if (students[j].course3 < students[j + 1].course3)
            {
                List temp;
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByTotal() //根据学生总成绩成绩排序
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i;j++)
        {
            if (students[j].total < students[j + 1].total)
            {
                List temp;
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByAvg() //根据学生平均成绩成绩排序
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (students[j].avg < students[j + 1].avg)
            {
                List temp;
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortById() //根据学生学号成绩排序
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (students[j].id > students[j + 1].id)
            {
                List temp;
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    printf("请先录入学生信息\n");
    int stop = 0,m;
    while(!stop)
    {
        int x;
        printf("请选择你的操作：\n1.学生录入\n2.删除学生\n3.查找学生\n4.查看排名\n5.查看全部\n6.退出程序\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("请输入本次录入学生数：\n");
            scanf("%d", &m);
            addStudent(m);
            n += m;//改变有存档的学生的总人数
            printf("学生成绩录入完毕！\n");
            break;
        case 2:
            printf("请选择删除方式：\n");
            printf("1.姓名\n2.学号\n");
            int y2;
            scanf("%d", &y2);
            switch(y2)
            {
                case 1:
                    deleteStudentByName();
                    break;
                case 2:
                    deleteStudentById();
                    break;
            }
            printf("学生删除完毕！\n");
            break;
        case 3:
            printf("请输入查找学生的方式：\n");
            printf("1.学号\n2.姓名\n");
            int y3;
            scanf("%d", &y3);
            switch(y3)
            {
                case 1:
                    searchStudentById();
                    break;
                case 2:
                    searchStudentByName();
                    break;
            }
            break;
        case 4:
            printf("请输入需要查看的排序：\n");
            printf("1.科目一\n2,科目二\n3.科目三\n4.总分\n5.平均分\n6.姓名\n7.学号\n");
            int y4;
            scanf("%d", &y4);
            switch(y4)
            {
                case 1:
                    sortByCourse1();
                    printStudents();
                    printf("最高分：\n");
                    for (int i = 0; i < n;i++)
                    {
                        if(students[i].course1==students[0].course1)
                            printf("%s    %.2f\n", students[i].name, students[i].course1);
                        else
                            break;
                    }
                    break;
                case 2:
                    sortByCourse2();
                    printStudents();
                    printf("最高分：\n");
                    for (int i = 0; i < n; i++)//将最高分对应的人全部输出，同高分用循环查找，下同
                    {
                        if (students[i].course2 == students[0].course2)
                            printf("%s    %.2f\n", students[i].name, students[i].course2);
                        else
                            break;
                    }
                    break;
                case 3:
                    sortByCourse3();
                    printStudents();
                    printf("最高分：\n");
                    for (int i = 0; i < n; i++)
                    {
                        if (students[i].course3 == students[0].course3)
                            printf("%s    %.2f\n", students[i].name, students[i].course3);
                        else
                            break;
                    }
                    break;
                case 5:
                    sortByAvg();
                    printStudents();
                    printf("最高分：\n");
                    for (int i = 0; i < n; i++)
                    {
                        if (students[i].avg == students[0].avg)
                            printf("%s    %.2f\n", students[i].name, students[i].avg);
                        else
                            break;
                    }
                    break;
                case 4:
                    sortByTotal();
                    printStudents();
                    printf("最高分：\n");
                    for (int i = 0; i < n; i++)
                    {
                        if (students[i].total == students[0].total)
                            printf("%s    %.2f\n", students[i].name, students[i].total);
                        else
                            break;
                    }
                    break;
                case 6:
                    sortByName();
                    printStudents();
                    break;
                case 7:
                    sortById();
                    printStudents();
                    break;
            }
            break;
        case 5:
            printStudents();
            break;
        case 6:
            stop = 1;
            break;
        default:
            printf("无效操作...");
            break;
        }
        printf("-------------------------------\n");
    }
}