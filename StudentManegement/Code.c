/**********************************************
�����ţ�1.1
�������ƣ�ѧ���ɼ�����ϵͳ     Student Score Management System
�ð汾ȥ�������е�ʵ�֣�ֻչʾ�˵�ϵͳ�Ŀ���
�����ܣ�1����ȡ�ļ�����ʾ,��ָ���ļ��������򴴽��ļ��������û��ֶ�¼�벢�������ļ���
          2��������ѧ����Ϣ�������ӡ�ɾ�����޸�
          3)�ɸ���ѧ��ѧ�š����ġ���ѧ��Ӣ�Ｐ�ܳɼ���������
          4���ɸ���ѧ�š�������ѯѧ����Ϣ���ɲ�ѯ����Ӣ�İ༶ƽ���ּ��������ηֲ�
�������룺ѧ���ɼ���Ϣ�����ļ�
����������Գ�����ʵ�ֵ���Ļ��ʾ���
����Ա��  ������ 1.0
���ʱ�䣺2016-08-16
�޸��ˣ�����
�޸�ʱ�䣺2022-01-18����Ҫ������ע�ͣ����˳������˵�ȫ����Ϊ0
          ȥ�������еĹ���ʵ��
�汾�ţ�  1.1
*************************************************/
/*�Կ⺯���Ķ���*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COURSENUM 3                                             // �γ�����
#define STRLENGTH 30                                            // �ַ�������
#define STUDENTNUM 100                                          // ѧ������
#define FILENAME "D:\\code\\StudentManegement\\studentlist.txt" // ȱʡ�����ļ���
#define FILEFLAG1 "STL"                                         // �����ļ���ʽ��ǣ�����ѧ�����ݱ�
#define FILEFLAG2 "STLSA"                                       // �����ļ���ʽ��ǣ�����ѧ�����ݱ�+�ܳɼ���ƽ���ɼ�

/* ѧ���ṹ�嶨�� */
struct student
{
    int nNumber;             // ѧ��,4λ
    char szName[STRLENGTH];  // ������2-3������
    float fScore[COURSENUM]; // ѧ�����ſεĳɼ�
    float fAveScore;         // ƽ����
    float fSumScore;         // �ܳɼ�
};
// ���������� ����������������20������*/

/*�˵���غ��� ����5��*/
// һ�����˵�ѡ����ʾ
void Select_MainMenu(struct student stu[], char szCourseName[][STRLENGTH], int *pNum);
/* �����˵�����Ϣ����ģ��˵�ѡ����ʾ  */
void Select_ManageMenu(struct student stu[], char szCourseName[][STRLENGTH], int *pNum);
/* �����˵����������˵�ѡ����ʾ */
void Select_SortMenu(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum);
/* �����˵���������ѯ�˵�ѡ����ʾ */
void Select_QueryMenu(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum);
/* �����˵����ļ�����˵�ѡ����ʾ */
void Select_SaveMenu(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum);
////////////////////////////////////////////////////////////////////////////////////////

/*�ļ���غ���������4��*/
// �����ļ����������е�����д���ļ�
int CreateFile(struct student stu[], int nStudentNum, int nFlag);
// ��������Ϊ�����ļ���
int CreateFileAs(struct student stu[], int nStudentNum, int nFlag);
// ��ȡ�ļ�������ȡ�ļ��е�Ԫ����Ϣ���浽ѧ���ṹ����
int ReadFromFile(FILE *fp, struct student stu[]);
// ����ǰ��ѧ����Ϣд���ļ�
void WriteToFile(FILE *fp, struct student stu[], int nStudentNum, int nFlag);
////////////////////////////////////////////////////////////////////////////////

/*��Ϣ������غ���������4��*/
// ���Ӹ�ѧ����Ϣ
int AddStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum);
// ���ѧ����Ϣ
void OutputStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int num, int flag, int nFrom, int nTo);
// ɾ��1��ѧ����Ϣ,��������ɾ���˻���û��ɾ��
int DeleteStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum);
/* �޸�ָ��ѧ���ĳɼ���Ϣ */
int ModifyStudentScore(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum);
/////////////////////////////////////////////////////////////////////////////////////////////

/* ���������غ���������4��  */
// ��ѧ����������
void SortOnNumAs(struct student stu[], int nStudentNum);
// ѡ��ʵ�ְ��ܳɼ���������
void SortOnSumDs(struct student stu[], int nStudentNum);
// �������ƽ���� */
void ComputeAverageScore(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum);
// ������Ƶĳɼ��ֲ�
void ComputeDistribution(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum);
/////////////////////////////////////////////////////////////////////////////////////////////

/*��ѯ��غ���������2��*/
/*��ѧ�Ų��� */
void FindByNumber(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum);
/*���������� */
void FindByName(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum);
/////////////////////////////////////////////////////////////////////////////////////////////

/* ϵͳ����������ʼ�������õȹ��� */
int main()
{
    /* �������ݽṹ */

    // ����ѧ���ṹ�����飬�������һֱ��Ϊ��������Ҫ�ĺ���֮�䴫��
    struct student stu[STUDENTNUM];
    // �洢ѧ������ ���������һֱ��Ϊ��������Ҫ�ĺ���֮�䴫��
    int nStudentNum = 0;
    // ����γ�����
    char szCourseName[COURSENUM][STRLENGTH] = {"����", "��ѧ", "Ӣ��"};

    ///////////////////////////////////////////////////////////////////////////////
    /* ��ʾ�˵�ǰ��׼�� */
    system("color f0"); // �ı䱳��ǰ��ɫ

    // ��ѧ�������ļ�
    FILE *fp = fopen(FILENAME, "r"); // Ϊ��ϵͳ���ļ����ں궨���������

    // �������ļ������ڣ��½������ļ�
    if (fp == NULL)
    {
        printf("\t\tϵͳָ�������ļ�: %s �����ڣ���Ҫ�ֹ���������\n", FILENAME);
        // ��������ѧ����Ϣ����
        AddStudentInfo(stu, szCourseName, &nStudentNum);
        printf("\t\t�ѳɹ�����%d��ѧ������.......\n", nStudentNum);

        // ���ô��������ļ�����
        if (!CreateFile(stu, nStudentNum, 0))
            printf("\t\t���������ļ�: %s ʧ�ܣ����ӵ�����û�б����������ļ���\n", FILENAME);
        // ���������ļ�ʧ�ܲ�Ӱ���������ӣ�ֻ�Ǹ�֪�û�û�б����������ļ��о�������

    } // �����ļ�����

    // �������ļ��ֳ��У���ȡ���������ļ���Ϣ
    else
    { // ���ö�ȡ�����ļ�����
        nStudentNum = ReadFromFile(fp, stu);

        // �����ȡ�ļ�״̬
        if (nStudentNum > 0)
            printf("\t\t�ѳɹ��������ļ���%s��ȡ��%d��ѧ��������.......\n\t\t", FILENAME, nStudentNum);
        else
            printf("\t\t�����ļ�%sû�����ݻ��ʽ���ԣ���ʹ����Ϣ����������������.......\n\t\t", FILENAME);
        fclose(fp);

    } // �ر��ļ�

    // ���û�����س��������������
    system("pause");
    ///////////////////////////////////////////////////////////////////////////////
    /*���û���ʾ���˵�,��������ƽ������˵����Ƴ���*/
    Select_MainMenu(stu, szCourseName, &nStudentNum);
}

////////////////////////////////////////////////////////////////////////////////
/*�˵���غ���*/

/*
�������ܣ�һ�����˵�ѡ����ʾ
���������ѧ���ṹ�����飬�γ�������
���ز�����ѧ����������Ϊ����һֱ�ı䣬��ָ�����ʵ�֣�
*/
void Select_MainMenu(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum)
{
    int nMainchoose;
    // ���˵�����ѭ��
    while (1)
    {
        system("CLS"); // ϵͳ��Ļ���
        // ����˵�������
        printf("\t\t   ------------------------  \n");
        printf("\t\t|      ѧ���ɼ�����ϵͳ      |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|  1.��Ϣ��ʾ   2.��Ϣ����   |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|  3.�������   4.������ѯ   |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|  5.�ļ�����   0.�˳�ϵͳ   |\n");
        printf("\t\t   ------------------------  \n");
        // ���ݺ궨����ļ�����ѧ��������ʾ
        printf("\n\t�����ļ�%s��Ŀǰ����%d��ѧ�� \n\n", FILENAME, *npStudentNum);
        // ���û�����ѡ�������
        printf("\t\t   ��ѡ�������(0~5):");
        // �û����ݽ�����ʾ��������
        scanf("%d", &nMainchoose);
        // �����û���������ֿ�����ж�
        switch (nMainchoose)
        {
            // ��Ϣ��ʾ
        case 1:
            printf("\n");
            // �������ѧ����Ϣ����
            OutputStudentInfo(stu, szCourseName, *npStudentNum, 0, 0, *npStudentNum); // ת�������ʾ����
            system("PAUSE");
            break;
        // ת�������˵�����Ϣ����ģ��˵�ѡ����ʾ
        case 2:
            Select_ManageMenu(stu, szCourseName, npStudentNum);
            break;
        // ת�������˵�����������ģ��˵�ѡ����ʾ
        case 3:
            Select_SortMenu(stu, szCourseName, *npStudentNum);
            break;
        // ת�������˵���������ѯģ��˵�ѡ����ʾ
        case 4:
            Select_QueryMenu(stu, szCourseName, *npStudentNum);
            break;
        // ת�������˵����ļ�����ģ��˵�ѡ����ʾ
        case 5:
            Select_SaveMenu(stu, szCourseName, *npStudentNum);
            break;
        // �û�ѡ���˳�
        case 0:
            printf("\n\n\t\t��лʹ�����ǵ���������ӭ�´�������\n\n");
            exit(0);
            break;
        // �û�ѡ������
        default:
            printf("ѡ����������ѡ��\n");
        } // switch����
    }     // while(1)��������
} // Select_MainMenu��������

/*
�������ܣ�һ���˵�����Ϣ����ģ��˵�ѡ����ʾ
���������ѧ���ṹ�����飬�γ�������
���ز�����ѧ����������Ϊ����һֱ�ı䣬��ָ�����ʵ�֣�
*/
void Select_ManageMenu(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum)
{
    int nManageChoose;
    while (1)
    {
        system("CLS");
        printf("\t\t------------------------------\n");
        printf("\t\t|********��Ϣ����ģ��********|\n");
        printf("\t\t|                            |\n");
        printf("\t\t|        1.����ѧ����Ϣ      |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|        2.ɾ��ѧ����Ϣ      |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|        3.�޸�ѧ����Ϣ      |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|        0.�����ϼ��˵�      |\n");
        printf("\t\t|                            |\n");
        printf("\t\t   ------------------------  \n");
        printf("\n\t�����ļ�%s��Ŀǰ����%d��ѧ�� \n\n", FILENAME, *npStudentNum);
        printf("\t\t   ��ѡ�������(0~3):");
        // �����û�ѡ��
        scanf("%d", &nManageChoose);
        switch (nManageChoose)
        {
        case 1:
            AddStudentInfo(stu, szCourseName, npStudentNum);                          // ת������ѧ����Ϣ����
            OutputStudentInfo(stu, szCourseName, *npStudentNum, 0, 0, *npStudentNum); // ������û���һ��
            system("PAUSE");
            break;
        case 2:
            DeleteStudentInfo(stu, szCourseName, npStudentNum);                       // ת��ɾ��ѧ����Ϣ����
            OutputStudentInfo(stu, szCourseName, *npStudentNum, 0, 0, *npStudentNum); // ������û���һ��
            system("PAUSE");
            break;
        case 3:
            ModifyStudentScore(stu, szCourseName, *npStudentNum);                     // ת���޸�ѧ����Ϣ����
            OutputStudentInfo(stu, szCourseName, *npStudentNum, 0, 0, *npStudentNum); // ������û���һ��
            system("PAUSE");
            break;
        case 0:
            Select_MainMenu(stu, szCourseName, npStudentNum); // ����һ�����˵�����
            break;

        default:
            printf("\t\tѡ����������ѡ��\n");
        } // switch���� */
    }     // while(1)����

} // Select_ManageMenu��������

/*
�������ܣ������˵�������ͼ���˵�ѡ����ʾ
���������ѧ���ṹ�����飬�γ������飬ѧ������
����ֵ����
*/
void Select_SortMenu(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
{
    int nSortChoose;

    while (1)
    {
        system("CLS");
        printf("\t\t------------------------------\n");
        printf("\t\t|********�������ģ��********|\n");
        printf("\t\t|                            |\n");
        printf("\t\t|   1.��ѧ����������         |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|   2.�ܳɼ����㼰��������   |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|   3.����ƽ���ɼ�����       |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|   4.���Ƴɼ��ֲ�����       |\n");
        printf("\t\t|                            |\n");
        printf("\t\t|   0.�����ϼ��˵�           |\n");
        printf("\t\t|                            |\n");
        printf("\t\t------------------------------  \n");
        printf("\n\t�����ļ�%s��Ŀǰ����%d��ѧ�� \n\n", FILENAME, nStudentNum);
        printf("\t\t   ��ѡ�������(0~4):");
        // �����û�ѡ��
        scanf("%d", &nSortChoose);

        switch (nSortChoose)
        {
        case 1:
            SortOnNumAs(stu, nStudentNum); // ��ѧ����������
            // OutputStudentInfo(stu,szCourseName,nStudentNum,0,0,nStudentNum);//������û���һ��
            system("PAUSE");
            break;
        case 2:
            SortOnSumDs(stu, nStudentNum); // ���ܳɼ���������
            // printf("\n\t\t\t��������ܳɼ���ƽ���ɼ�......\n");
            // OutputStudentInfo(stu,szCourseName,nStudentNum,1,0,nStudentNum);//������û���һ��
            system("PAUSE");
            break;
        case 3:
            printf("\n\t\t\t�����ܳɼ���ƽ���ɼ�......\n");
            ComputeAverageScore(stu, szCourseName, nStudentNum); // ���ܳɼ���������
            system("PAUSE");
            break;
        case 4:
            printf("\n\t\t\t�������ƽ���ɼ����ֲ�......\n");
            ComputeDistribution(stu, szCourseName, nStudentNum); // ���ܳɼ���������
            system("PAUSE");
            break;
        case 0:
            Select_MainMenu(stu, szCourseName, &nStudentNum); // ����һ�����˵�ѡ����ʾ
            break;
        default:
            printf("\t\tѡ����������ѡ��\n");
        } // switch����
    }     // while(1)����
} // Select_SortMenu��������

/*
�������ܣ������˵�����Ϣ��ѯ�˵�ѡ����ʾ
���������ѧ���ṹ�����飬�γ������飬ѧ������
����ֵ����
*/

void Select_QueryMenu(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
{
    int nQueryChoose;
    while (1)
    {
        system("CLS");
        printf("\t\t---------------------------------------\n");
        printf("\t\t|*************��Ϣ��ѯģ��************|\n");
        printf("\t\t|                                     |\n");
        printf("\t\t|         1.����ѧ�Ų�ѯ��Ϣ          |\n");
        printf("\t\t|                                     |\n");
        printf("\t\t|         2.����������ѯ��Ϣ          |\n");
        printf("\t\t|                                     |\n");
        printf("\t\t|         0.�����ϼ��˵�              |\n");
        printf("\t\t|                                     |\n");
        printf("\t\t---------------------------------------\n");
        printf("\t\t                            \n");
        printf("\t\t   ��ѡ�������(0~2):");

        scanf("%d", &nQueryChoose);

        switch (nQueryChoose)
        {
        case 1:
            FindByNumber(stu, szCourseName, nStudentNum); // ��ѧ�Ų�ѯѧ����Ϣ
            system("PAUSE");
            break;
        case 2:
            FindByName(stu, szCourseName, nStudentNum); // ��������ѯѧ����Ϣ
            system("PAUSE");
            break;
        case 0:
            Select_MainMenu(stu, szCourseName, &nStudentNum); // ����һ�����˵�ѡ��
            break;
        default:
            printf("\t\tѡ����������ѡ��\n");
        } // switch����

    } // while����
} // ��Ϣ��ѯ�˵�����

/*
�������ܣ������˵����ļ�����ѡ����ʾ
���������ѧ���ṹ�����飬�γ������飬ѧ������
����ֵ����
*/
void Select_SaveMenu(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
{
    int nSaveChoose;
    while (1)
    {
        system("CLS");
        printf("\t\t---------------------------------------\n");
        printf("\t\t|*************�ļ�����ģ��************|\n");
        printf("\t\t|                                     |\n");
        printf("\t\t|         1.��ǰ�ļ�����              |\n");
        printf("\t\t|                                     |\n");
        printf("\t\t|         2.���������ļ�              |\n");
        printf("\t\t|                                     |\n");
        printf("\t\t|         3.����ƽ�����ܳɼ�          |\n");
        printf("\t\t|                                     |\n");
        printf("\t\t|         0.�����ϼ��˵�              |\n");
        printf("\t\t|                                     |\n");
        printf("\t\t---------------------------------------\n");
        printf("\t\t                            \n");
        printf("\t\t   ��ѡ�������(0~3):");
        scanf("%d", &nSaveChoose);
        switch (nSaveChoose)
        {
        case 1:
            // ���´��������ļ�
            CreateFile(stu, nStudentNum, 0);
            break;
        case 2: // ����Ϊ�����ļ�
            CreateFileAs(stu, nStudentNum, 0);
            break;
        case 3: // ����Ϊ�����ļ��������ܳɼ��������ɼ�
            CreateFileAs(stu, nStudentNum, 1);
            break;
        case 0:
            Select_MainMenu(stu, szCourseName, &nStudentNum); // ����һ�����˵�ѡ��
            break;
        default:
            printf("\t\tѡ����������ѡ��\n");
        } // switch����
        system("PAUSE");
    } // while����
} // �ļ�����˵�����

//////////////////////////////////////////////////////////////////////////////////////
/*�ļ���غ���*/
/*
�������ܣ������ļ����������е�����д���ļ�
���������ѧ���ṹ�����飬ѧ���������ļ���ʽ��־
          ע�������ִ洢�ļ���ʽ,1����û��ƽ���ɼ����ܳɼ���,1�����е�
          Ϊ�����������ļ���ʽ,���ļ���ʽ��־д�������ļ�����
         �ļ���ʽ��־��0 ��ʾ "STL" �Ǵ洢Ϊ����ѧ�����ݱ���Ϣ�ļ� (���ܳɼ���ƽ���ɼ�)
                       1 ��ʾ "STLSA" �ǻ���ѧ�����ݱ�+�ܳɼ���ƽ���ɼ�
           ***�ļ���ʽ��־Ϊ����Ա�Լ�����ģ��ü��±���studentlist.txt���Կ����洢��������
����ֵ��0: �����ɹ���1���������ɹ�
*/

int CreateFile(struct student stu[], int nStudentNum, int nFlag)
{
    // ����д���ļ�
    FILE *fp = fopen(FILENAME, "w");
    if (fp != NULL)
    {
        WriteToFile(fp, stu, nStudentNum, nFlag);
        printf("\t\t�ѳɹ���%d��ѧ������д�������ļ�%s.......\n", nStudentNum, FILENAME);
        // ���û���ʾĿǰ����Ϣ
        return 1;
    }

    else // �ļ��������ɹ�
        return 0;

} // �����ļ�����

/*
�������ܣ�����Ϊ�ļ����������е�����д���ļ�
���������ѧ���ṹ�����飬ѧ���������ļ���ʽ��־
         �ļ���ʽ��־��0 ��ʾ "STL" �Ǵ洢Ϊ����ѧ�����ݱ���Ϣ�ļ�
                       1 ��ʾ "STLSA" �ǻ���ѧ�����ݱ�+�ܳɼ���ƽ���ɼ�
           ***�ļ���ʽ��־Ϊ����Ա�Լ�����ģ��ü��±���dd.txt����
               Studentscore.data���Կ����洢��������
����ֵ��0: �����ɹ���1���������ɹ�
*/

int CreateFileAs(struct student stu[], int nStudentNum, int nFlag)
{
    char szFileName[STRLENGTH];
    if (nStudentNum < 1)
    {
        printf("\t\t��ǰû��ѧ�����ݣ��뵽��Ϣ����ģ���������ݣ�\n");
        return 0;
    }
    if (nFlag == 1 && stu[0].fSumScore < 1)
    {
        printf("\t\t��ǰû���ܳɼ���ƽ���ɼ���Ϣ���뵽�������ģ�����ɼ���\n");
        return 0;
    }

    while (1)
    {
        printf("\n\t\t�������Ᵽ����ļ���: ");

        scanf("%s", szFileName);
        if (strcmp(szFileName, FILENAME) == 0)
            printf("\n\t\t���ļ���Ϊϵͳ�ļ���������ʹ�ã�\n");
        else
            break;
    }
    // ����д���ļ�
    FILE *fp = fopen(szFileName, "w");
    if (fp != NULL)
    {
        WriteToFile(fp, stu, nStudentNum, nFlag);
        printf("\t\t�ѳɹ���%d��ѧ������д�������ļ�%s.......\n", nStudentNum, szFileName);
        fclose(fp);
        // ���û���ʾĿǰ����Ϣ
        return 1;
    }

    else // �ļ��������ɹ�
        return 0;

} // ��������Ϊ�ļ�����

/*
�������ܣ���ȡ�ļ�������ȡ�ļ��е�Ԫ����Ϣ���浽ѧ���ṹ����
   ע�⣺����������ļ��ж�������ʼ�ַ�����"STL" ��ʾ�ǻ���ѧ�����ݱ���Ϣ�ļ�
                          ���� "STLSA" �ǻ���ѧ�����ݱ�+�ܳɼ���ƽ���ɼ�
            ***�ļ���ʽ��־Ϊ����Ա�Լ��涨�ģ��ü��±���dd.txt����
                Studentscore.data���Կ����洢��������
����������ļ�ָ�룬ѧ���ṹ������

����ֵ��������ѧ����
*/

int ReadFromFile(FILE *fp, struct student stu[])
{
    int i = 0;
    char szFileFlag[STRLENGTH]; // �ȶ��ļ����
    fscanf(fp, "%s", szFileFlag);
    int nFlag = -1;
    if (strcmp(szFileFlag, FILEFLAG1) == 0)
        nFlag = 0;
    if (strcmp(szFileFlag, FILEFLAG2) == 0)
        nFlag = 1;
    if (nFlag == -1)
        return 0; // �����δ֪���ļ�ͷ������0
    do
    {
        int nReadNum = 0;
        // ��ѧ�ź�����
        nReadNum += fscanf(fp, "%d%s", &stu[i].nNumber, &stu[i].szName);
        // �����Ƴɼ�
        for (int j = 0; j < COURSENUM; j++)
            nReadNum += fscanf(fp, "%f", &stu[i].fScore[j]);
        // �����STLSA�����ܳɼ���ƽ���ɼ�
        if (nFlag == 1)
            fscanf(fp, "%f%f", &stu[i].fSumScore, &stu[i].fAveScore);
        // �ɹ���ȡ��������+1
        if (nReadNum == (COURSENUM + 2))
            i++;
        else
            break;
    } while (1);
    return i; // ���ض�����ѧ����
}
// ReadFromFile ��������

/*
�������ܣ���Ŀǰѧ���ṹ������ݣ�д��һ���ļ�
����������ļ�ָ�룬ѧ���ṹ�����飬ѧ���������ļ���ʽ��־
          �ļ���ʽ��־��0 ��ʾ "STL" �Ǵ洢Ϊ����ѧ�����ݱ���Ϣ�ļ�
                        1 ��ʾ "STLSA" �ǻ���ѧ�����ݱ�+�ܳɼ���ƽ���ɼ�
            ***�ļ���ʽ��־Ϊ����Ա�Լ�����ģ��ü��±���dd.txt����
                Studentscore.data���Կ����洢��������

����ֵ��������ѧ����
*/
void WriteToFile(FILE *fp, struct student stu[], int nStudentNum, int nFlag)
{
    // �������
    if (nFlag == 0)
        fprintf(fp, FILEFLAG1);
    else if (nFlag == 1)
        fprintf(fp, FILEFLAG2);
    fprintf(fp, "\n");
    for (int i = 0; i < nStudentNum; i++)
    {
        // д�������ļ�
        fprintf(fp, "%d %s ", stu[i].nNumber, stu[i].szName);
        // д���Ƴɼ�
        for (int j = 0; j < COURSENUM; j++)
            fprintf(fp, "%.2f ", stu[i].fScore[j]);
        if (nFlag == 1)
            fprintf(fp, "%.2f %.2f", stu[i].fSumScore, stu[i].fAveScore);
        fprintf(fp, "\n");

    } // forѭ������

} // Write to File ��������

///////////////////////////////////////////////////////////////////////////////
/*ѧ����Ϣ��������---���ӣ�ɾ�����޸�*/

/*
�������ܣ�������N��ѧ����Ϣ���������ӵ�ѧ���������޸�ѧ��Ŀǰ����Ŀ
���������ѧ���ṹ�����飬�γ���������
����ֵ��ѧ����������ָ��������أ���Ϊ���������仯
����ֵ�����ӵ�ѧ������
*/
int AddStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum)
{

    printf("\n\t\t\t����������ѧ����Ϣģ��\n");
    int n, m, nNewStudents, x = 0;
    printf("\t\t\t������Ҫ���ӵ�ѧ����Ŀ��");
    scanf("%d", &n);
    for (m = *npStudentNum; m < (*npStudentNum + n); m++)
    {
        printf("\t\t\t������Ҫ���ӵĵ�%d��ѧ������Ϣ\n", ++x);
        printf("\t\t\tѧ��:");
        scanf("%d", &stu[m].nNumber);
        printf("\t\t\t����:");
        scanf("%s", stu[m].szName);

        for (int j = 0; j < COURSENUM; j++)
        {
            printf("\t\t\t%s�ɼ���", szCourseName[j]);
            scanf("%f", &stu[m].fScore[j]);
        }
        // ����ÿ��ѧ����ƽ���ֺ��ܳɼ�
        stu[m].fSumScore = 0;
        for (int j = 0; j < COURSENUM; j++)
        {
            stu[m].fSumScore += stu[m].fScore[j];
        }
        stu[m].fAveScore = stu[m].fSumScore / COURSENUM;
    }

    *npStudentNum += n; // �޸ĵ�ǰѧ����Ŀ
    nNewStudents = n;
    printf("\n\t\t\tѧ����Ϣ���ӳɹ�!\n");
    return nNewStudents; // �������ӵ�ѧ����
} // AddSudentInfo��������

/*
�������ܣ����ѧ����Ϣ���� ������������֣�1������ƽ���ɼ����ܳɼ��ģ�1����û��
���������ѧ���ṹ�����飬�γ��������飬ѧ���������ļ���ʽ��־���Ƿ���ƽ���ɼ����ܳɼ���
          û��ƽ���ɼ����ܳɼ��ļ���־Ϊ 0����ƽ���ɼ����ܳɼ��ļ���־Ϊ 1
         nFrom ��ʾ�ӵڼ�����ʼ�����nTo��ʾ�䵽�ڼ�������
����ֵ����
*/

void OutputStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum, int nFlag,
                       int nFrom, int nTo)
{
    printf("\n\t\t\t��������ʾѧ����Ϣģ��\n\n");
    if (nStudentNum == 0)
    {
        printf("\t\t\tϵͳ��û��ѧ����Ϣ��\n");
        return;
    }
    if (nFlag)
    {
        printf("\t\t\tѧ�� \t���� \t���� \t��ѧ \tӢ�� \tƽ���� \t�ܳɼ�\n");
        printf("\t\t\t=====================================================\n");
        for (int i = nFrom; i < nTo; i++)
        {
            printf("\t\t\t%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", stu[i].nNumber, stu[i].szName, stu[i].fScore[0], stu[i].fScore[1], stu[i].fScore[2], stu[i].fAveScore, stu[i].fSumScore);
        }
        printf("\t\t\t=====================================================\n");
    }
    else
    {
        printf("\t\t\tѧ�� \t���� \t���� \t��ѧ \tӢ��\n");
        printf("\t\t\t======================================\n");
        for (int i = nFrom; i < nTo; i++)
        {
            printf("\t\t\t%d\t%s\t%.2f\t%.2f\t%.2f\n", stu[i].nNumber, stu[i].szName, stu[i].fScore[0], stu[i].fScore[1], stu[i].fScore[2]);
        }
        printf("\t\t\t======================================\n");
    }
}
// ���ѧ����Ϣ��������

/*
�������ܣ�ɾ��ĳλѧ����Ϣ�ĺ����������ڲ��Դ�����
���������ѧ���ṹ�����飬�γ���������
����ֵ��ѧ����������ָ�������ʽ����Ϊ������仯��
         nFrom ��ʾ�ӵڼ�����ʼ�����nTo��ʾ�䵽�ڼ�������
����ֵ���Ƿ�ɹ�ɾ����0Ϊû�ɹ�ɾ����1Ϊ�ɹ�ɾ��
*/
int DeleteStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum)
{
    printf("\n\t\t\t������ɾ��ѧ����Ϣģ��\n\n");
    char studentName[STRLENGTH];
    int flag = 0,n=*npStudentNum;
    printf("\t\t\t������Ҫɾ����Ϣ��ѧ��������");
    scanf("%s", studentName);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(stu[i].szName, studentName) == 0)
        {
            flag = 1;
            for (int j = i; j < n - 1; j++)
            {
                stu[j] = stu[j + 1];
                /*strcpy(stu[j].szName, stu[j + 1].szName);

                stu[j].fScore[1] = stu[j + 1].fScore[1];
                stu[j].fScore[2] = stu[j + 1].fScore[2];
                stu[j].fScore[3] = stu[j + 1].fScore[3];*/
            }
            (*npStudentNum)--;
            // ���ɾ����Ϣ���ѧ������
            printf("\n\t\t\t�ɹ�ɾ��%s����Ϣ!\n", studentName);
        }
    }
    if(!flag){
        printf("\t\t\t��ѧ����Ϣɾ������\n");
        return 0;
    }
    else
        return 1;
} // DeleteStudentInfo��������

        /*
        �������ܣ��޸�ĳλѧ���ĳɼ���Ϣ�������ڲ��Դ�����
        ���������ѧ���ṹ�����飬�γ��������飬ѧ������
        ����ֵ���Ƿ�ɹ��޸ģ�0Ϊû�ɹ��޸ģ�1Ϊ�ɹ��޸�
        */
        int ModifyStudentScore(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
        {

            printf("\n\t\t\t �������޸�ѧ����Ϣģ��\n\n");
            char studentName[STRLENGTH];
            char courseName[STRLENGTH];
            float newScore;

            printf("\t\t\t������Ҫ�޸ĳɼ���ѧ��������");
            scanf("%s", studentName);

            printf("\t\t\t������Ҫ�޸ĵĿγ����ƣ�");
            scanf("%s", courseName);

            printf("\t\t\t�������µĳɼ���");
            scanf("%f", &newScore);

            // ����ѧ�����飬����Ҫ�޸ĳɼ���ѧ��
            for (int i = 0; i < nStudentNum; i++)
            {
                if (strcmp(stu[i].szName, studentName) == 0)
                {
                    // �ڸ�ѧ���в���Ҫ�޸ĵĿγ�
                    for (int j = 0; j < COURSENUM; j++)
                    {
                        if (strcmp(szCourseName[j], courseName) == 0)
                        {
                            stu[i].fScore[j] = newScore;
                            printf("\n\t\t\t���޸�%s��%s�ɼ�Ϊ%.2f\n", studentName, courseName, newScore);
                            return 1; // �޸ĳɹ�
                        }
                    }
                    // û���ҵ�Ҫ�޸ĵĿγ�
                    printf("\t\t\t%s�޷��޸�%s�γ�\n", studentName, courseName);
                    return 0; // �޸�ʧ��
                }
            }

            // û���ҵ�Ҫ�޸ĳɼ���ѧ��
            printf("\t\t\tδ�ҵ�����Ϊ%s��ѧ��\n", studentName);
            return 0; // �޸�ʧ��

        } // ModifyScore��������

        //////////////////////////////////////////////////////////////////////////////////////
        /*���������غ���*/
        /*
        �������ܣ�ѡ��ʵ�ְ�ѧ����������
        ���������ѧ���ṹ�����飬ѧ������
        ����ֵ���޸Ĺ��õ�ѧ���ṹ������ÿ��ѧ����˳��
        */

        void SortOnNumAs(struct student stu[], int nStudentNum)
        {
            printf("\n\t\t\t�����ǰ�ѧ����������ģ��\n\n");
            int i, j;
            struct student t;
            for (i = 0; i < nStudentNum - 1; i++)
                for (j = i + 1; j < nStudentNum; j++)
                {
                    if (stu[i].nNumber > stu[j].nNumber)
                    {
                        t = stu[i];
                        stu[i] = stu[j];
                        stu[j] = t;
                    }
                }
            printf("\t\t\tѧ��\t ����\t ����\t ��ѧ\t Ӣ��\t \n");
            printf("\t\t\t========================================\n");
            for (i = 0; i < nStudentNum; i++)
            {
                printf("\t\t\t%d\t %s\t %.2f\t %.2f\t %.2f\t \n", stu[i].nNumber, stu[i].szName, stu[i].fScore[0], stu[i].fScore[1], stu[i].fScore[2]);
            }
            printf("\t\t\t=========================================\n");
        }
        // ��ѧ�������������

        /*
        �������ܣ�ѡ��ʵ�ְ��ܳɼ���������
        ���������ѧ���ṹ�����飬ѧ������
        ����ֵ���޸Ĺ��õ�ѧ���ṹ������ÿ��ѧ����˳��
        */
        void SortOnSumDs(struct student stu[], int nStudentNum)
        {
            printf("\n\t\t\t�����Ǽ����ܳɼ��������ܳɼ���������ģ��\n\n");
            int i, j;
            struct student t;
            for (i = 0; i < nStudentNum; i++)
            {
                stu[i].fSumScore = stu[i].fScore[0] + stu[i].fScore[1] + stu[i].fScore[2];
            }
            for (i = 0; i < nStudentNum - 1; i++)
                for (j = i + 1; j < nStudentNum; j++)
                {
                    if (stu[i].fSumScore < stu[j].fSumScore)
                    {
                        t = stu[i];
                        stu[i] = stu[j];
                        stu[j] = t;
                    }
                }
            printf("\t\t\tѧ��\t ����\t ����\t ��ѧ\t Ӣ��\t �ܳɼ�\t\n");
            printf("\t\t\t================================================\n");
            for (i = 0; i < nStudentNum; i++)
            {
                printf("\t\t\t%d\t %s\t %.2f\t %.2f\t %.2f\t %.2f\t\n", stu[i].nNumber, stu[i].szName, stu[i].fScore[0], stu[i].fScore[1], stu[i].fScore[2], stu[i].fSumScore);
            }
            printf("\t\t\t=================================================\n");
        }
        // �ܳɼ������������

        /*
        �������ܣ��������ƽ����
        ���������ѧ���ṹ�����飬�γ��������ݣ�ѧ������
        ����ֵ���޸Ĺ��õ�ѧ���ṹ�������ÿ����Ա��ƽ����
        */

        void ComputeAverageScore(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
        {
            printf("\n\t\t\t�����Ǽ���ѧ������ƽ������ģ��\n\n");
            int i;
            for (i = 0; i < nStudentNum; i++)
            {
                stu[i].fAveScore = (stu[i].fScore[0] + stu[i].fScore[1] + stu[i].fScore[2]) / 3;
            }
            printf("\t\t\tѧ��\t ����\t ����\t ��ѧ\t Ӣ��\t ƽ����\t\n");
            printf("\t\t\t===============================================\n");
            for (i = 0; i < nStudentNum; i++)
            {
                printf("\t\t\t%d\t %s\t %.2f\t %.2f\t %.2f\t %.2f\t\n", stu[i].nNumber, stu[i].szName, stu[i].fScore[0], stu[i].fScore[1], stu[i].fScore[2], stu[i].fAveScore);
            }
            printf("\t\t\t===============================================\n");
        }

        /*
        �������ܣ����㲢����༶���ĳɼ��������ηֲ����
            ����ѧ���ɼ��ֲ��ȼ����£�
            60�����£�fail
            60~70�� ��pass
            70~80�� ��good
            80~90�� ��great
            90�����ϣ�excellent
        ���������ѧ���ṹ�����飬�γ��������ݣ�ѧ������
        ����ֵ����
        */
        void ComputeDistribution(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
        {
            printf("\n\t\t\t�����Ǽ���������ηֲ�ģ��\n\n");
            printf("\t\t\t======================================================\n");
            printf("\t\t\tѧ��\tExcellent\tGreat\tGood\tPass\tFail\n");
            for (int i = 0; i < COURSENUM; i++)
            {
                printf("\t\t\t%s", szCourseName[i]);
                float n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
                for (int j = 0; j < nStudentNum; j++)
                {
                    if (stu[j].fScore[i] < 60)
                        n5++;
                    else if (stu[j].fScore[i] >= 60 && stu[j].fScore[i] < 70)
                        n4++;
                    else if (stu[j].fScore[i] >= 70 && stu[j].fScore[i] < 80)
                        n3++;
                    else if (stu[j].fScore[i] >= 80 && stu[j].fScore[i] <= 90)
                        n2++;
                    else
                        n1++;
                }
                printf(" \t%.1f%%\t\t%.1f%%\t%.1f%%\t%.1f%%\t%.1f%%\n", n1 / nStudentNum * 100, n2 / nStudentNum * 100, n3 / nStudentNum * 100, n4 / nStudentNum * 100, n5 / nStudentNum * 100);
            }
            printf("\t\t\t======================================================\n");
        } // ����ɼ��ֲ������������

        /////////////////////////////////////////////////////////////////////////////////
        // ��ѯ��غ��� ����2������ѧ�ţ�����������

        /*
        �������ܣ���ѧ�Ų��Ҳ����һ��ѧ���ľ�����Ϣ
        ���������ѧ���ṹ�����飬�γ��������ݣ�ѧ������
        ����ֵ����
        */

        void FindByNumber(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
        {
            printf("\n\t\t\t�����ǰ�ѧ�Ų���ѧ����Ϣģ��\n\n");
            printf("\t\t\t������Ҫ����ѧ����ѧ�ţ�");
            int num;
            scanf("%d", &num);
            int flag = 0;
            for (int i = 0; i < nStudentNum; i++)
            {
                if (num == stu[i].nNumber)
                {
                    flag = 1;
                    printf("\n\t\t\tѧ�� \t����");
                    for (int i = 0; i < COURSENUM; i++)
                    {
                        printf(" \t%s", szCourseName[i]);
                    }
                    printf("\n\t\t\t======================================\n");
                    printf("\t\t\t%d\t", stu[i].nNumber);
                    printf("%s\t", stu[i].szName);
                    for (int j = 0; j < COURSENUM; j++)
                    {
                        printf("%.2f\t", stu[i].fScore[j]);
                    }
                    printf("\n\t\t\t======================================\n\n\n");
                }
            }
            if (!flag)
            {
                printf("\n\t\t\tδ�ҵ���ѧ��...\n\n");
            }
        } // ��ѧ�Ų�ѯ����

        /*
        �������ܣ����������Ҳ����һ��ѧ���ľ�����Ϣ
        ���������ѧ���ṹ�����飬�γ��������ݣ�ѧ������
        ����ֵ����
        */
        void FindByName(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
        {
            printf("\n\t\t\t�����ǰ���������ѧ����Ϣģ��\n\n");
            printf("\t\t\t������Ҫ����ѧ����������");
            char name[STRLENGTH];
            scanf("%s", name);
            int flag = 0;
            for (int i = 0; i < nStudentNum; i++)
            {
                if (strcmp(stu[i].szName, name) == 0)
                {
                    flag = 1;
                    printf("\n\t\t\tѧ�� \t����");
                    for (int i = 0; i < COURSENUM; i++)
                    {
                        printf(" \t%s", szCourseName[i]);
                    }
                    printf("\n\t\t\t======================================\n");
                    printf("\t\t\t%d\t", stu[i].nNumber);
                    printf("%s\t", stu[i].szName);
                    for (int j = 0; j < COURSENUM; j++)
                    {
                        printf("%.2f\t", stu[i].fScore[j]);
                    }
                    printf("\n\t\t\t======================================\n\n\n");
                }
            }
            if (!flag)
            {
                printf("δ�ҵ���ѧ��...\n");
            }
        } // ��������ѯ����