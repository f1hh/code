#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define USERSNUM 20
#define GOODSNUM 50
#define BASKETSNUM 50
#define STRLENGHT 10
#define PASSWORDLEN 6

#define FILENAME1 "D://code//eBusiness//GoodsInformation.txt"
#define FILENAME2 "D://code//eBusiness//ShoppingBasket.txt"
#define FILENAME3 "D://code//eBusiness//UserInformation.txt"

#define FILEFLAGGOODS "GOODS"
#define FILEFLAGUSERS "USERS"
#define FILEFLAGBASKETS "BASKETS"

struct User
{
    char cName[30];
    char cPassword[10];
    float fAccount;
    float fIntegration;
};

struct Goods
{
    char cId[10];
    char cName[30];
    float fPrice;
    char cClassify[30];
    int nStock;
    int nSales;
    float fEvaluate;
    int buynumber;
};

struct Baskets
{
    char nUsers_name[30];
    char cGoods_id[BASKETSNUM][100];
    char cGoods_name[BASKETSNUM][30];
    float fPrice[BASKETSNUM];
    int num;
};

struct User users[USERSNUM];  // �û�
struct Goods go[GOODSNUM];    // ��Ʒ
struct Baskets bas[USERSNUM]; // ���ﳵ

void Entrance_Menu();
void ReadGoodsFromFile(FILE *fp, struct Goods go[], int *);
void WriteGoodsFromFile(FILE *fp, struct Goods go[], int);
void ReadUsersFromFile(FILE *fp, struct User user[], int *);
void WriteUsersFromFile(FILE *fp, struct User user[], int);
void ReadBasketsFromFile(FILE *fp, struct Baskets bas[], int *);
void WriteBasketsFromFile(FILE *fp, struct Baskets bas[], int);
void RedeemPoints(struct User user[], int);
void Topup(struct User use[], int);
void PasswordChange(struct User user[], int);
void RegisterUser(struct User users[], int *);
void BuyGoods(struct User users[], struct Goods go[], struct Baskets bas[], int, int, int *);
void ShoppingBaskets(struct User users[], struct Goods go[], struct Baskets bas[], int, int);
void AddGoods(struct Goods goods[], int *);
void DisplayAllGoods(struct Goods goods[], int);
void PersonalIfo(int, int);
void ManagerLogIn(int *);
void UserSelections(int, int, int, int, int *, FILE *fp1, FILE *fp2, FILE *fp3);
int FindUserWithRetry(struct User users[], int);

int main()
{
    system("color f0");

    Entrance_Menu();

    return 1;
}

void Entrance_Menu()
{

    FILE *fp1 = fopen(FILENAME1, "r+");
    if (fp1 == NULL)
    {
        printf("\t\tδ���ҵ���Ʒ��Ϣ....\n");
        system("PAUSE");
    }

    FILE *fp2 = fopen(FILENAME2, "r+");
    if (fp2 == NULL)
    {
        printf("\t\tδ���ҵ����ﳵ��Ϣ....\n");
        system("PAUSE");
    }

    FILE *fp3 = fopen(FILENAME3, "r+");
    if (fp3 == NULL)
    {
        printf("\t\tδ���ҵ��û���Ϣ....\n");
        system("PAUSE");
    }

    system("CLS");

    int GoodsNum = 0;
    int UsersNum = 0;
    int BasketsNum = 0;

    ReadGoodsFromFile(fp1, go, &GoodsNum);
    ReadUsersFromFile(fp3, users, &UsersNum);
    ReadBasketsFromFile(fp2, bas, &BasketsNum);

    printf("\n\n\n\t\t\t��ӭ��������ƽ̨!\n\n\t\t");

    printf("\n\n\t\t-------------1.�û���¼-------------");
    printf("\n\n\t\t------------2.����Ա��¼------------");
    printf("\n\n\t\t-------------3.�û�ע��-------------");
    printf("\n\n\t\t-------------4.��Ʒ���-------------");
    printf("\n\n\t\t-------------5.�˳�����-------------\n\n");

    int choice;

    printf("\n\n\n\t\t����������ѡ��1~5����");
    char c = getch();
    choice = c - '0';

    int NO = 0;

    switch (choice)
    {
    case 1:
        system("cls");
        NO = FindUserWithRetry(users, UsersNum);
        Sleep(1000);
        UserSelections(NO, GoodsNum, UsersNum, BasketsNum, &BasketsNum, fp1, fp2, fp3);
        break;
    case 2:
        system("cls");
        ManagerLogIn(&GoodsNum);
        WriteGoodsFromFile(fp1, go, GoodsNum);
        Entrance_Menu();
        break;
    case 3:
        system("cls");
        RegisterUser(users, &UsersNum);
        WriteUsersFromFile(fp3, users, UsersNum);
        system("pause");
        Entrance_Menu();
        break;
    case 4:
        system("cls");
        DisplayAllGoods(go, GoodsNum);
        Entrance_Menu();
        break;
    case 5:
        system("cls");
        printf("\n\n\t\t\t��ӭ�´ι��٣�\n\n\n\n\n");
        exit(0);
    default:
        system("cls");
        Entrance_Menu();
        break;
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

void UserSelections(int NO, int GoodsNum, int UsersNum, int BasketsNum, int *BNum, FILE *fp1, FILE *fp2, FILE *fp3)
{
    system("cls");
    printf("\n\n\t\t-------------1.ѡ����Ʒ-------------");
    printf("\n\n\t\t--------------2.���ﳵ--------------");
    printf("\n\n\t\t-----------3.������Ϣ����-----------");
    printf("\n\n\t\t---------------4.�ǳ�---------------\n\n\n");

    // printf("\n\t\t%d\n\n", bas[NO].num);

    int choice;
    printf("\n\t\t����������ѡ��1~4����");
    char c = getch();
    choice = c - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        DisplayAllGoods(go, GoodsNum);
        BuyGoods(users, go, bas, GoodsNum, NO, BNum);
        UserSelections(NO, GoodsNum, UsersNum, BasketsNum, BNum, fp1, fp2, fp3);
        break;
    case 2:
        ShoppingBaskets(users, go, bas, GoodsNum, NO);
        UserSelections(NO, GoodsNum, UsersNum, BasketsNum, BNum, fp1, fp2, fp3);
        WriteBasketsFromFile(fp2, bas, UsersNum);
        break;
    case 3:
        PersonalIfo(NO, GoodsNum);
        UserSelections(NO, GoodsNum, UsersNum, BasketsNum, BNum, fp1, fp2, fp3);
        break;
    case 4:
        WriteUsersFromFile(fp3, users, UsersNum);
        WriteGoodsFromFile(fp1, go, GoodsNum);
        WriteBasketsFromFile(fp2, bas, UsersNum);
        printf("\n\t\t�����˳���¼...");
        Sleep(2000);
        Entrance_Menu();
        break;
    default:
        UserSelections(NO, GoodsNum, UsersNum, BasketsNum, BNum, fp1, fp2, fp3);
    }
}

// ������Ʒ��Ӧ����
void ReadGoodsFromFile(FILE *fp, struct Goods go[], int *GoodsNum)
{
    int i = 0;
    char FileFlag[STRLENGHT];
    fscanf(fp, "%s", FileFlag);
    if (strcmp(FileFlag, FILEFLAGGOODS) != 0)
    {
        printf("��Ʒϵͳ���ִ���");
        exit(0);
    }

    while (!feof(fp))
    {
        fscanf(fp, "%s%s%f%s%d%d%f", go[i].cId, go[i].cName, &go[i].fPrice, go[i].cClassify, &go[i].nStock, &go[i].nSales, &go[i].fEvaluate);
        i++;
    }
    *GoodsNum = i;
}

void WriteGoodsFromFile(FILE *fp, struct Goods go[], int GoodsNum)
{
    rewind(fp);
    fprintf(fp, FILEFLAGGOODS);

    int i = 0;

    while (i < GoodsNum)
    {
        fprintf(fp, "\n%s %s %.2f %s %d %d %.2f", go[i].cId, go[i].cName, go[i].fPrice, go[i].cClassify, go[i].nStock, go[i].nSales, go[i].fEvaluate);
        i++;
    }

    fclose(fp);
}

// �����û�����
void ReadUsersFromFile(FILE *fp, struct User user[], int *UsersNum)
{
    int i = 0;
    char FileFlag[STRLENGHT];
    fscanf(fp, "%s", FileFlag);
    if (strcmp(FileFlag, FILEFLAGUSERS) != 0)
    {
        printf("�û�ϵͳ���ִ���");
        exit(0);
    }

    while (!feof(fp))
    {
        fscanf(fp, "%s%s%f%f", user[i].cName, user[i].cPassword, &user[i].fAccount, &user[i].fIntegration);
        i++;
    }
    *UsersNum = i;
}

void WriteUsersFromFile(FILE *fp, struct User user[], int UsersNum)
{
    rewind(fp);
    fprintf(fp, FILEFLAGUSERS);

    int i = 0;

    while (i < UsersNum)
    {
        fprintf(fp, "\n%s %s %.2f %.2f", user[i].cName, user[i].cPassword, user[i].fAccount, user[i].fIntegration);
        i++;
    }

    fclose(fp);
}

void ReadBasketsFromFile(FILE *fp, struct Baskets bas[], int *BasketsNum)
{
    int i = 0;
    char FileFlag[STRLENGHT];
    char flag[] = "END";
    fscanf(fp, "%s", FileFlag);
    if (strcmp(FileFlag, FILEFLAGBASKETS) != 0)
    {
        printf("���ﳵ���ִ���");
        exit(0);
    }

    while (!feof(fp))
    {
        char temp[30];
        fscanf(fp, "%s", temp);
        if (strcmp(temp, flag) == 0)
        {
            i++;
        }
        else
        {
            int j = 0;
            strcpy(bas[i].nUsers_name, temp);
            while (1)
            {
                fscanf(fp, "%s", bas[i].cGoods_id[j]);
                if (strcmp(bas[i].cGoods_id[j], flag) == 0)
                {
                    strcpy(bas[i].cGoods_id[j], "000");
                    break;
                }
                fscanf(fp, "%s%f ", bas[i].cGoods_name[j], &bas[i].fPrice[j]);
                fscanf(fp, "%d", &bas[i].num);
                j++;
            }
            i++;
        }
    }
    *BasketsNum = i;
}

void WriteBasketsFromFile(FILE *fp, struct Baskets bas[], int UsersNum)
{
    int i = 0;
    rewind(fp);
    fprintf(fp, FILEFLAGBASKETS);
    while (i < UsersNum)
    {
        int j = 0;
        fprintf(fp, " %s ", bas[i].nUsers_name);
        while (j < bas[i].num)
        {
            fprintf(fp, "%s %s %.2f ", bas[i].cGoods_id[j], bas[i].cGoods_name[j], bas[i].fPrice[j]);
            j++;
            if (bas[i].num != 0)
            {
                fprintf(fp, "%d ", bas[i].num);
            }
        }
        fprintf(fp, "END");
        i++;
    }

    fclose(fp);
}

// ���ֶһ�����  ���룺������Ϣ�ṹ��
void RedeemPoints(struct User user[], int NO)
{
    printf("\t\t---------------------------���ֶһ�ԭ��--------------------------------\n");
    printf("\t\t--------------1��ÿ����һԪǮ���ɻ��һ������--------------------------\n");
    printf("\t\t--------------2��ÿ�ܹ�20�����֣��ɶ�һԪǮ�������˻�------------------\n");

    int a;
    int money;
    printf("\n\t\t�����ڹ���%.2f����,���Զһ�%dԪ\n", user[NO].fIntegration, (int)user[NO].fIntegration / 20);
    printf("\n\t\t�Ƿ���Ҫ�һ�Ϊ�ֽ�(1.�� 2.��):");
    char c = getch();
    a = c - '0';

    if (a == 1)
    {
        if (user[NO].fIntegration < 20)
        {
            printf("\n\t\t��Ǹ�����Ļ��ֲ��㣬�޷��һ���\n");
            Sleep(2000);
        }
        else
        {
            money = (int)user[NO].fIntegration / 20;
            user[NO].fAccount += money;
            user[NO].fIntegration -= money * 20;
            printf("\n\t\t�һ��ɹ���");
            Sleep(3000);
        }
    }
    if (a == 0)
    {
        printf("\n\t\t�����ѱ���");
        Sleep(2000);
    }
}

// �˻���ֵ���� ���룺�û��ṹ��
void Topup(struct User user[], int NO)
{
    char password[PASSWORDLEN + 1];
    float bill;
    int i, n;
    printf("\n\t\t�������ֵ��");
    scanf("%f", &bill);
    while (1)
    {
        printf("\n\t\t����������:");
        for (i = 0; i < PASSWORDLEN; i++)
        {
            password[i] = getch();
            printf("*");
        }
        password[i] = '\0';
        if (strcmp(user[NO].cPassword, password) == 0)
        {
            user[NO].fAccount = bill + user[NO].fAccount;
            printf("\n\n\t\t��ֵ�ɹ�����ǰ�˻����%.2fԪ", user[NO].fAccount);
            Sleep(3000);
            break;
        }
        else
        {
            printf("\n\t\t�������!");
            n++;
        }
        if (n == 3)
        {
            printf("\n\t\t��������Σ������˳�����");
            Sleep(2000);
            exit(0);
        }
    }
}

// �����޸ķ����� ���룺�û��ṹ��
void PasswordChange(struct User user[], int NO)
{
    char pw_1[PASSWORDLEN + 1], pw_2[PASSWORDLEN + 1], pw_3[PASSWORDLEN + 1];
    int i;
    while (1)
    {
        printf("\n\t\t������ԭ���룺");
        for (i = 0; i < PASSWORDLEN; i++)
        {
            pw_1[i] = getch();
            printf("%c", pw_1[i]);
        }
        pw_1[i] = '\0';
        printf("\n");
        if (strcmp(user[NO].cPassword, pw_1) == 0)
        {
            while (1)
            {
                printf("\n\t\t�����������룺");
                for (i = 0; i < PASSWORDLEN; i++)
                {
                    pw_2[i] = getch();
                    printf("*");
                }
                pw_2[i] = '\0';
                printf("\n");
                printf("\n\t\t���ٴ����������룺");
                for (i = 0; i < PASSWORDLEN; i++)
                {
                    pw_3[i] = getch();
                    printf("*");
                }
                pw_3[i] = '\0';
                printf("\n");
                if (strcmp(pw_2, pw_3) == 0)
                {
                    printf("\n\t\t�����޸ĳɹ���\n");
                    strcpy(user[NO].cPassword, pw_3);
                    Sleep(2000);
                    break;
                }
                else
                {
                    printf("\t\t�����������벻ͬ");
                }
            }
            break;
        }
        else
        {
            printf("\t\t�����������\n");
        }
    }
}

// �û���¼���Һ���������ֵΪ�û��������е��±�
int FindUserWithRetry(struct User users[], int UsersNum)
{
    char username[USERSNUM + 1];
    char password[PASSWORDLEN + 1];
    int found = 0;
    int i;
    printf("\n\t\t��ӭ�����û���¼���棡\n\n\n");

    do
    {
        found = 0;

        printf("\t\t�����������û���: ");
        scanf("%s", username);

        fflush(stdin);

        printf("\n\t\t������%dλ����: ", PASSWORDLEN);
        for (i = 0; i < PASSWORDLEN; i++)
        {
            password[i] = getch();
            printf("*");
        }
        password[i] = '\0';

        for (i = 0; i < UsersNum; i++)
        {
            if (strcmp(users[i].cName, username) == 0)
            {
                if (strcmp(users[i].cPassword, password) == 0)
                {
                    found = 1;
                    printf("\n\n\t\t��¼�ɹ���");
                    break;
                }
                else
                {
                    found = -1; // ���벻��ȷ
                    printf("\n\n\t\t������������������˺�����\n\n");
                    break;
                }
            }
        }

        if (!found)
            printf("\n\t\tδ�ҵ��û���Ϣ��\n");

    } while (found == -1); // �������������������

    return i;
}

// ע��
void RegisterUser(struct User users[], int *UersNum)
{
    int flag = 0;
    char newName[USERSNUM + 1];

    printf("\t\t��ӭ�����û�ע����棡\n");

    do
    {
        flag = 0;

        printf("\n\t\t�������û���: ");
        scanf("%s", newName);
        getchar();

        for (int i = 0; i < *UersNum; i++)
        {
            if (strcmp(users[i].cName, newName) == 0)
            {
                flag = 1;
                printf("\n\t\t�û����Ѵ��ڣ����������룡\n");
                break;
            }
        }
    } while (flag);

    strcpy(users[*UersNum].cName, newName);

    do
    {
        char Pass[PASSWORDLEN + 1];
        int i = 0;
        printf("\n\t\t������%dλ����: ", PASSWORDLEN);
        for (i = 0; i < PASSWORDLEN; i++)
        {
            Pass[i] = getch();
            printf("*");
        }
        Pass[i] = '\0';

        char confirmPass[PASSWORDLEN + 1];
        printf("\n\t\t���ٴ�ȷ������: ");
        for (i = 0; i < PASSWORDLEN; i++)
        {
            confirmPass[i] = getch();
            printf("*");
        }
        confirmPass[i] = '\0';

        if (strcmp(Pass, confirmPass) != 0)
        {
            printf("\n\n\n\t\t������������벻һ�£��������������롣\n");
        }
        else
        {
            strcpy(users[*UersNum].cPassword, Pass);
            break;
        }

    } while (1);
    users[*UersNum].fAccount = 0.0;
    users[*UersNum].fIntegration = 0.0;
    printf("\n\n\n\n\t\tע��ɹ���\n\n\n\t\t");
    (*UersNum)++;
}

// NO�������ĳ���ڽṹ���λ��
void BuyGoods(struct User users[], struct Goods go[], struct Baskets bas[], int GoodsNum, int NO, int *BasketsNum)
{
    printf("\n\n\t\t��������ѡ��Ʒ��(��� ����):");
    char n[1000];
    int num;
    scanf("%s %d", n, &num);

    printf("\t\t1.ֱ�ӹ�����Ʒ  2.���빺�ﳵ(������1/2):");
    int t;
    char c = getch();
    t = c - '0';

    if (t == 1)
    {
        for (int i = 0; i < GoodsNum; i++)
        {
            if (strcmp(n, go[i].cId) == 0)
            {
                if (go[i].fPrice * num > users[NO].fAccount)
                {
                    printf("\n\n\t\t����,��ǰ���������ĳ�ֵ\n\t\t�Ѱ�������Ʒ����������ﳵ");
                    int flag = 0;
                    for (int i = 0; i < bas[NO].num; i++)
                    {
                        if (strcmp(bas[NO].cGoods_id[i], n) == 0)
                        {
                            flag = 1;
                        }
                    }
                    if (!flag)
                    {
                        strcpy(bas[NO].nUsers_name, users[NO].cName);
                        for (int i = 0; i < GoodsNum; i++)
                        {
                            if (strcmp(n, go[i].cId) == 0)
                            {
                                strcpy(bas[NO].cGoods_id[bas[NO].num], go[i].cId);
                                strcpy(bas[NO].cGoods_name[bas[NO].num], go[i].cName);
                                bas[NO].fPrice[bas[NO].num] = go[i].fPrice;
                                break;
                            }
                        }
                        bas[NO].num++;
                        (*BasketsNum)++;
                    }
                    else
                    {
                        printf("\n\n\t\t��Ʒ���ڹ��ﳵ��,��ֵ���ֱ��ǰ������");
                    }
                    Sleep(3000);
                    break;
                }
                else
                {
                    printf("\n\t\t���ζ��������˻��۷�%.2fԪ", go[i].fPrice * num);
                    char address[1000];
                    printf("\n\t\t�������ջ���ַ��");
                    scanf("%s", address);
                    printf("\n\t\t�����ύ��......");
                    Sleep(2000);
                    printf("\n\n\t\t��Ʒ����ɹ���");

                    go[i].nStock -= num;
                    go[i].nSales += num;
                    users[NO].fAccount -= go[i].fPrice * num;
                    users[NO].fIntegration += go[i].fPrice * num;
                    go[i].buynumber++;

                    printf("\n\n\t\t�����Ʒ��֣�0-10��:");
                    float score;
                    scanf("%f", &score);
                    if (go[i].fEvaluate == 0)
                        go[i].fEvaluate = score;
                    else
                        go[i].fEvaluate = (go[i].fEvaluate * (go[i].buynumber - 1) + score) / go[i].buynumber;
                    printf("\n\n\t\t��л���Ĺ���");
                    Sleep(2000);
                    break;
                }
            }
        }
    }
    else if (t == 2)
    {
        int flag = 0;
        for (int i = 0; i < bas[NO].num; i++)
        {
            if (strcmp(bas[NO].cGoods_id[i], n) == 0)
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            strcpy(bas[NO].nUsers_name, users[NO].cName);
            for (int i = 0; i < GoodsNum; i++)
            {
                if (strcmp(n, go[i].cId) == 0)
                {
                    strcpy(bas[NO].cGoods_id[bas[NO].num], go[i].cId);
                    strcpy(bas[NO].cGoods_name[bas[NO].num], go[i].cName);
                    bas[NO].fPrice[bas[NO].num] = go[i].fPrice;
                    break;
                }
            }
            bas[NO].num++;
            (*BasketsNum)++;

            printf("\n\n\t\t�����Ʒ�ɹ�!\n\t\t");
        }
        else
        {
            printf("\n\n\t\t��Ʒ���ڹ��ﳵ��");
        }
        Sleep(1500);
    }
}

void ShoppingBaskets(struct User users[], struct Goods go[], struct Baskets bas[], int GoodsNum, int NO) // ���ﳵ�ڲ���
{
    int i = 0;
    i = bas[NO].num;
    if (i == 0)
    {
        system("cls");
        printf("\n\t\t���ﳵΪ��!\n");
        Sleep(2000);
    }
    else
    {
        system("cls");
        printf("\n\t\t��Ʒ���\t��Ʒ����\t��Ʒ�۸�\n");
        printf("\t\t========================================\n");
        for (int j = 0; j < i; j++)
        {
            printf("\t\t%s\t\t%s\t\t%.2f\n", bas[NO].cGoods_id[j], bas[NO].cGoods_name[j], bas[NO].fPrice[j]);
        }
        printf("\t\t========================================\n");
        printf("\n\t\t1.����\n\t\t2.ɾ��\n\t\t3.�˳�\n\n\t\t(������1~3):");
        int t;
        char n[1000];
        char c = getch();
        t = c - '0';

        if (t == 1)
        {
            int num;
            printf("\n\n\t\t�����빺����Ʒ(��� ����):");
            scanf("%s %d", n, &num);
            for (int j = 0; j < GoodsNum; j++)
            {
                if (strcmp(n, go[j].cId) == 0)
                {
                    if (go[j].fPrice * num > users[NO].fAccount)
                    {
                        printf("\n\n\t\t����,��ǰ���������ĳ�ֵ");
                        Sleep(3000);
                        break;
                    }
                    else
                    {
                        printf("\n\t\t���ζ��������˻��۷�%.2fԪ", go[i].fPrice * num);
                        char address[1000];
                        printf("\n\t\t�������ջ���ַ��");
                        scanf("%s", address);
                        printf("\n\t\t�����ύ��......");
                        Sleep(2000);
                        printf("\n\n\t\t��Ʒ����ɹ���");

                        go[j].nStock -= num;
                        go[j].nSales += num;
                        users[NO].fAccount -= go[j].fPrice * num;
                        users[NO].fIntegration += go[j].fPrice * num;
                        go[j].buynumber++;

                        printf("\n\n\t\t�����Ʒ��֣�0-10��:");
                        float score;
                        scanf("%f", &score);
                        if (go[j].fEvaluate == 0)
                            go[j].fEvaluate = score;
                        else
                            go[j].fEvaluate = (go[j].fEvaluate * (go[j].buynumber - 1) + score) / go[j].buynumber;
                        printf("\n\n\t\t��л���Ĺ���");
                        Sleep(2000);
                        break;
                    }
                }
            }
        }
        else if (t == 2)
        {
            printf("\n\n\t\t������ɾ����Ʒ���:");
            scanf("%s", n);
            int flag = 0;
            for (int j = 0; j < i; j++)
                if (strcmp(bas[NO].cGoods_id[j], n) == 0)
                {
                    strcpy(bas[NO].cGoods_id[j], bas[NO].cGoods_id[j + 1]);
                    strcpy(bas[NO].cGoods_name[j], bas[NO].cGoods_name[j + 1]);
                    bas[NO].fPrice[j] = bas[NO].fPrice[j + 1];
                    bas[NO].num--;
                    flag = 1;
                }
            if (flag)
            {
                printf("\n\n\t\tɾ���ɹ���");
            }
            else
            {
                printf("\n\n\t\t����Ʒδ�ڹ��ﳵ�У�");
            }
            Sleep(1000);
        }
        else
        {
            printf("\n\n\t\t�����˳����ﳵ...");
            Sleep(1000);
        }
    }
}

void AddGoods(struct Goods goods[], int *GoodsNum)
{
    int n;

    printf("\t\t������Ʒ���������");
    scanf("%d", &n);

    printf("\t\t--------�����Ʒ��Ϣ--------\n");

    for (int i = 0; i < n; i++)
    {

        printf("\n\t\t��%d����ƷID: ", i + 1);
        scanf("%s", goods[*GoodsNum].cId);

        printf("\t\t��%d����Ʒ����: ", i + 1);
        scanf("%s", goods[*GoodsNum].cName);

        printf("\t\t��%d���۸�: ", i + 1);
        scanf("%f", &goods[*GoodsNum].fPrice);

        printf("\t\t��%d������: ", i + 1);
        scanf("%s", goods[*GoodsNum].cClassify);

        printf("\t\t��%d�����: ", i + 1);
        scanf("%d", &goods[*GoodsNum].nStock);

        goods[*GoodsNum].nSales = 0;

        goods[*GoodsNum].fEvaluate = 0;

        (*GoodsNum)++;
    }

    printf("\n\t\t--------��Ʒ��ӳɹ�!--------\n");
    Sleep(2000);
}

void DisplayAllGoods(struct Goods goods[], int GoodsNum)
{
    printf("\t\t������Ʒ��Ϣ���£�\n\n");
    printf("\n\t\t\t��Ʒ���\t��Ʒ����\t�۸�\t���\t���\t����\t���۷���");
    printf("\n\t\t\t=======================================================================");
    for (int i = 0; i < GoodsNum; i++)
    {
        printf("\n\t\t\t%s\t\t%s\t\t%.2f\t%s\t%d\t%d\t%.2f", goods[i].cId, goods[i].cName, goods[i].fPrice, goods[i].cClassify, goods[i].nStock, goods[i].nSales, goods[i].fEvaluate);
    }
    printf("\n\t\t\t=======================================================================");
}

void PersonalIfo(int NO, int GoodsNum)
{
    system("CLS");
    printf("\t\t��ӭ���������Ϣ����");
    printf("\n\n\t\t��ǰ�˻���%.2fԪ\t���֣�%.2f", users[NO].fAccount, users[NO].fIntegration);
    printf("\n\n\t\t---------1.�޸�����-------------");
    printf("\n\n\t\t---------2.�˻���ֵ-------------");
    printf("\n\n\t\t---------3.�һ�����-------------");
    printf("\n\n\t\t--------4.�˳���������----------");

    int choice1;
    printf("\n\n\t\t���������ѡ��(1~4):");
    char c = getch();
    choice1 = c - '0';

    switch (choice1)
    {
    case 1:
        system("cls");
        PasswordChange(users, NO);
        PersonalIfo(NO, GoodsNum);
        break;
    case 2:
        system("cls");
        Topup(users, NO);
        PersonalIfo(NO, GoodsNum);
        break;
    case 3:
        system("cls");
        RedeemPoints(users, NO);
        PersonalIfo(NO, GoodsNum);
        break;
    case 4:
        break;
    default:
        PersonalIfo(NO, GoodsNum);
        break;
    }
}

void ManagerLogIn(int *GoodsNum)
{
    printf("\t\t���������Ա��Կ:");
    char p[PASSWORDLEN + 1] = "@12345";
    char pw[PASSWORDLEN + 1];
    for (int i = 0; i < PASSWORDLEN; i++)
    {
        pw[i] = getch();
        printf("*");
    }
    if (strcmp(p, pw) == 0)
    {
        system("cls");
        printf("\n\t\t�Թ���Ա��ݵ�½\n");
        printf("\t\t������Ʒ��Ϣ\n");
        AddGoods(go, GoodsNum);
    }
    else
    {
        printf("��Կ����\n");
        system("PAUSE");
        Entrance_Menu();
    }
}
