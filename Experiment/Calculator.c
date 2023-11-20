#include <stdio.h>
#include <math.h>

void add(double a, double b)//定义加法函数
{
    printf("结果是: %f\n", a + b);
}

void subtract(double a, double b)//定义减法函数
{
    printf("结果是: %f\n", a - b);
}

void multiply(double a, double b)//定义乘法函数
{
    printf("结果是: %f\n", a * b);
}

void divide(double a, double b)//定义除法函数
{
    if (b != 0)
    {
        printf("结果是: %f\n", a / b);
    }
    else
    {
        printf("除数不能为0\n");
    }
}

void power(double a, double b)//定义乘方函数
{
    printf("结果是: %f\n", pow(a, b));
}

int main()
{
    double a, b;
    int choice;

    while (1)           //开始菜单选择计算符号
    {
        printf("请选择操作：\n");
        printf("1. 加法\n");
        printf("2. 减法\n");
        printf("3. 乘法\n");
        printf("4. 除法\n");
        printf("5. 乘方\n");
        printf("6. 退出\n");
        scanf("%d", &choice);

        if (choice == 6)
            break;

        printf("输入第一个数: ");
        scanf("%lf", &a);
        printf("输入第二个数: ");
        scanf("%lf", &b);

        switch (choice)//调用函数计算
        {
        case 1:
            add(a, b);
            break;
        case 2:
            subtract(a, b);
            break;
        case 3:
            multiply(a, b);
            break;
        case 4:
            divide(a, b);
            break;
        case 5:
            power(a, b);
            break;
        default:
            printf("无效的选择\n");
        }
    }

    return 0;
}
