#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
int main() 
{
    Con myContacts;
    ConInit(&myContacts);
    int choice;
    int index;
    char targetName[100];
    PerInfo contact; // ����һ���µ���ϵ����Ϣʵ��
    while (1) 
    {
        printf("\n--- ͨѶ¼����ϵͳ ---\n");
        printf("1. �����ϵ�˵�ĩβ\n");
        printf("2. �����ϵ�˵���ͷ\n");
        printf("3. ɾ�����һ����ϵ��\n");
        printf("4. ɾ����һ����ϵ��\n");
        printf("5. ��ʾ������ϵ����Ϣ\n");
        printf("6. ����ͨѶ¼���ļ�\n");
        printf("7. ���ļ�����ͨѶ¼\n");
        printf("8. �޸�ָ����ϵ�˵���Ϣ\n");
        printf("9. ����ָ����ϵ�˵���Ϣ\n");
        printf("10. �˳�\n");
        printf("��ѡ��һ��������");
        int result = scanf("%d", &choice);
        if (result == 1) 
        {
            switch (choice)
            {
            case 1:
            {
                PerInfo newContact;
                printf("����������");
                scanf("%s", newContact.name);
                printf("�����Ա�");
                scanf("%s", newContact.gender);
                printf("�������䣺");
                scanf("%d", &newContact.age);
                printf("����绰��");
                scanf("%s", newContact.telephone);
                printf("�����ַ��");
                scanf("%s", newContact.address);
                ConPushBack(&myContacts, newContact);
                break;
            }
            case 2:
            {
                PerInfo newContact;
                printf("����������");
                scanf("%s", newContact.name);
                printf("�����Ա�");
                scanf("%s", newContact.gender);
                printf("�������䣺");
                scanf("%d", &newContact.age);
                printf("����绰��");
                scanf("%s", newContact.telephone);
                printf("�����ַ��");
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
                printf("������Ҫ�޸ĵ���ϵ��������");
                scanf("%d", &index);
                // �˴�����Ҫһ�ַ�������ȡ�µ���ϵ����Ϣ
                // ������һ������������ֱ���������ռ�
                printf("�����µ�������");
                scanf("%s", contact.name);
                printf("�����µ��Ա�");
                scanf("%s", contact.gender);
                printf("�����µ����䣺");
                scanf("%d", &contact.age);
                printf("�����µĵ绰��");
                scanf("%s", contact.telephone);
                printf("�����µĵ�ַ��");
                scanf("%s", contact.address);
                // ���޸�֮ǰȷ����������Ч��
                if (index >= 0 && index < myContacts.size) {
                    ConModify(&myContacts, index, contact);
                }
                else {
                    printf("��Ч��������\n");
                }
                break;
            case 9:
                printf("������Ҫ���ҵ���ϵ��������");
                scanf("%s", targetName);
                ConSearch(&myContacts, targetName);

                break;
            case 10:
                ConDestroy(&myContacts);
                printf("�˳�����\n");
                return 0;
            default:
                printf("��Чѡ�������ѡ��\n");
            }
        }
        else
        {
            // ��ȡʧ�ܣ�����������
            while (getchar() != '\n'); // ��ȡ������ֱ��һ������
            printf("������Ч��������һ�����֡�\n");
        }

    }
    return 0;
}
