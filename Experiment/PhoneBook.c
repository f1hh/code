#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 联系人结构体
typedef struct Contact
{
    char name[50];
    char phone[20];
    char address[100];
    struct Contact *next;
} Contact;

// 通讯录结构体
typedef struct
{
    Contact *head;
} AddressBook;

// 初始化通讯录
AddressBook *create(void)
{
    AddressBook *book = (AddressBook *)malloc(sizeof(AddressBook));
    book->head = NULL;
    return book;
}

// 添加联系人
void add(AddressBook *book, char *name, char *phone, char *address)
{
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->address, address);
    newContact->next = book->head;
    book->head = newContact;
}
// 显示所有联系人
void display(AddressBook *book)
{
    Contact *p = book->head;
    while (p != NULL)
    {
        printf("姓名: %s, 电话: %s, 地址: %s\n", p->name, p->phone, p->address);
        p = p->next;
    }
}
// 删除联系人
void delete(AddressBook *book, char *name)
{
    Contact *p = book->head;
    Contact *previous = NULL;

    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            if (previous == NULL)
            {
                book->head = p->next;
            }
            else
            {
                previous->next = p->next;
            }
            free(p);
            return;
        }
        previous = p;
        p = p->next;
    }
}

// 修改联系人信息
void updateContact(AddressBook *book, char *oldName, char *newName, char *newPhone, char *newAddress)
{
    Contact *p = book->head;
    while (p != NULL)
    {
        if (strcmp(p->name, oldName) == 0)
        {
            strcpy(p->name, newName);
            strcpy(p->phone, newPhone);
            strcpy(p->address, newAddress);
            return;
        }
        p = p->next;
    }
}
// 排序函数
void sortContacts(AddressBook *book)
{
    int swapped;
    Contact *ptr1;
    Contact *lptr = NULL;

    if (book->head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = book->head;

        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->name, ptr1->next->name) > 0)
            {
                char tempName[50];
                char tempPhone[20];
                char tempAddress[100];

                // 交换数据
                strcpy(tempName, ptr1->name);
                strcpy(tempPhone, ptr1->phone);
                strcpy(tempAddress, ptr1->address);

                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->phone, ptr1->next->phone);
                strcpy(ptr1->address, ptr1->next->address);

                strcpy(ptr1->next->name, tempName);
                strcpy(ptr1->next->phone, tempPhone);
                strcpy(ptr1->next->address, tempAddress);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
// 根据手机号查询联系人
void searchByPhone(AddressBook *book, char *phone)
{
    Contact *p = book->head;
    while (p != NULL)
    {
        if (strcmp(p->phone, phone) == 0)
        {
            printf("姓名: %s, 电话: %s, 地址: %s\n", p->name, p->phone, p->address);
            return;
        }
        p = p->next;
    }
    printf("未找到此人\n");
}

int main()
{
    AddressBook *book = create();
    int choice;
    char name[50], phone[20], address[100],name1[50],name2[50];

    while (1)
    {
        printf("\n----- 通讯录管理系统菜单 -----\n");
        printf("1. 添加联系人\n");
        printf("2. 显示所有联系人\n");
        printf("3. 删除联系人\n");
        printf("4. 修改联系人信息\n");
        printf("5. 排序联系人\n");
        printf("6. 根据手机号查询\n");
        printf("7. 退出\n");
        printf("选择操作 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("输入姓名: ");
            scanf("%s", name);
            printf("输入电话: ");
            scanf("%s", phone);
            printf("输入地址: ");
            scanf("%s", address);
            add(book, name, phone, address);
            break;
        case 2:
            display(book);
            break;
        case 3:
            printf("输入要删除的姓名: ");
            scanf("%s", name);
            delete(book, name);
            break;
        case 4:
            printf("输入要修改的联系人原姓名: ");
            scanf("%s", name1);
            printf("输入新姓名: ");
            scanf("%s", name2);
            printf("输入新电话: ");
            scanf("%s", phone);
            printf("输入新地址: ");
            scanf("%s", address);
            updateContact(book, name1, name2, phone, address);
            break;
        case 5:
            sortContacts(book);
            break;
        case 6:
            printf("输入要查询的电话号码: ");
            scanf("%s", phone);
            searchByPhone(book, phone);
            break;
        case 7:
            printf("退出系统.\n");
            exit(0);
        default:
            printf("无效选择，请重新输入.\n");
        }
    }

    return 0;
}
