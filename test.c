#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
int main() 
{
    Con myContacts;
    ConInit(&myContacts);
    int choice;
    int index;
    char targetName[100];
    PerInfo contact; // 创建一个新的联系人信息实例
    while (1) 
    {
        printf("\n--- 通讯录管理系统 ---\n");
        printf("1. 添加联系人到末尾\n");
        printf("2. 添加联系人到开头\n");
        printf("3. 删除最后一个联系人\n");
        printf("4. 删除第一个联系人\n");
        printf("5. 显示所有联系人信息\n");
        printf("6. 保存通讯录到文件\n");
        printf("7. 从文件加载通讯录\n");
        printf("8. 修改指定联系人的信息\n");
        printf("9. 查找指定联系人的信息\n");
        printf("10. 退出\n");
        printf("请选择一个操作：");
        int result = scanf("%d", &choice);
        if (result == 1) 
        {
            switch (choice)
            {
            case 1:
            {
                PerInfo newContact;
                printf("输入姓名：");
                scanf("%s", newContact.name);
                printf("输入性别：");
                scanf("%s", newContact.gender);
                printf("输入年龄：");
                scanf("%d", &newContact.age);
                printf("输入电话：");
                scanf("%s", newContact.telephone);
                printf("输入地址：");
                scanf("%s", newContact.address);
                ConPushBack(&myContacts, newContact);
                break;
            }
            case 2:
            {
                PerInfo newContact;
                printf("输入姓名：");
                scanf("%s", newContact.name);
                printf("输入性别：");
                scanf("%s", newContact.gender);
                printf("输入年龄：");
                scanf("%d", &newContact.age);
                printf("输入电话：");
                scanf("%s", newContact.telephone);
                printf("输入地址：");
                scanf("%s", newContact.address);
                ConPushFront(&myContacts, newContact);
                break;
            }
            case 3:
                ConPopBack(&myContacts);
                break;
            case 4:
                ConPopFront(&myContacts);
                break;
            case 5:
                ConDisplayAll(&myContacts);
                break;
            case 6:
                ConSave(&myContacts, "contacts.csv");
                break;
            case 7:
                ConLoad(&myContacts, "contacts.csv");
                break;
            case 8:
                printf("请输入要修改的联系人索引：");
                scanf("%d", &index);
                // 此处你需要一种方法来获取新的联系人信息
                // 可以是一个函数，或者直接在这里收集
                printf("输入新的姓名：");
                scanf("%s", contact.name);
                printf("输入新的性别：");
                scanf("%s", contact.gender);
                printf("输入新的年龄：");
                scanf("%d", &contact.age);
                printf("输入新的电话：");
                scanf("%s", contact.telephone);
                printf("输入新的地址：");
                scanf("%s", contact.address);
                // 在修改之前确保索引是有效的
                if (index >= 0 && index < myContacts.size) {
                    ConModify(&myContacts, index, contact);
                }
                else {
                    printf("无效的索引。\n");
                }
                break;
            case 9:
                printf("请输入要查找的联系人姓名：");
                scanf("%s", targetName);
                ConSearch(&myContacts, targetName);

                break;
            case 10:
                ConDestroy(&myContacts);
                printf("退出程序。\n");
                return 0;
            default:
                printf("无效选项，请重新选择。\n");
            }
        }
        else
        {
            // 读取失败，清理输入流
            while (getchar() != '\n'); // 读取并丢弃直到一个新行
            printf("输入无效，请输入一个数字。\n");
        }

    }
    return 0;
}
