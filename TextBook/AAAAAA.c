#include<stdio.h>
#include<string.h>

struct Baskets
{
    char nUsers_name[30];
    char cGoods_id[3][100];
    char cGoods_name[3][30];
    float fPrice[3];
};

int main(void)
{
    FILE *fp;
    struct Baskets b;
    fp = fopen("D://code//TextBook//a.txt", "r+");

    if (!feof(fp))
    {
        {
            fscanf(fp, "%s", b.nUsers_name);
            for (int i = 0; i < 3; i++)
            {
                fscanf(fp, "%s%s%f", b.cGoods_id[i], b.cGoods_name[i], &b.fPrice[i]);
            }
        }
    }
    printf("%s", b.nUsers_name);
    for (int i = 0; i < 3; i++)
    {
        printf("%s%s%.0f", b.cGoods_id[i], b.cGoods_name[i], b.fPrice[i]);
    }
    fprintf(fp, "\n");
    fprintf(fp, "%s", b.nUsers_name);
    fprintf(fp, "\n");
    for (int i = 0; i < 3; i++)
    {
        fprintf(fp, "%s %s %.0f  ", b.cGoods_id[i], b.cGoods_name[i], b.fPrice[i]);
        fprintf(fp, "\n");
    }
}