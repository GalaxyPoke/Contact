#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
//ͨѶ¼�ĳ�ʼ��
void ConInit(Con* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//ͨѶ¼������
void ConCheckcapacity(Con* ps)
{
	if (ps->size == ps->capacity)
	{
		assert(ps);
		int newcapacity = ps->capacity == 0 ? INIT_CAPACITY : ps->capacity * 2;
		PerInfo* temp = (PerInfo*)realloc(ps->arr, newcapacity * sizeof(PerInfo));
		if (temp == NULL)
		{
			perror("realloc:");
			exit(1);
		}
		else
		{
			ps->arr = temp;
			ps->capacity = newcapacity;
		}
	}
}

//ͨѶ¼������
void ConDestroy(Con* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//�����ϵ����Ϣ����һ��λ��
void ConPushFront(Con* ps, PerInfo newContact)
{
	assert(ps);
	ConCheckcapacity(ps);
	for (int i = ps->size - 1;i >= 0;i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = newContact;
	ps->size++;
}

//�����ϵ����Ϣ�����һ��λ��
void ConPushBack(Con* ps, PerInfo newContact)
{
	assert(ps);
	ConCheckcapacity(ps);
	ps->arr[ps->size] = newContact;
	ps->size++;
}

//ɾ����һ����ϵ����Ϣ
void ConPopFront(Con* ps)
{
	assert(ps);
	if (ps->size == 0) 
	{
		printf("��ʾ�������ϵ���б��ǿյģ�û�ж�������ɾ��\n");
		return;
	}
	else
	{
		for (int i = 0;i < ps->size - 1; i++)
		{
			ps->arr[i] = ps->arr[i + 1];
		}
		ps->size--;
	}
	printf("��ʾ����һ����ϵ��ɾ���ɹ�\n");
}


//ɾ�����һ����ϵ����Ϣ
void ConPopBack(Con* ps)
{
	assert(ps);  // ȷ��ͨѶ¼ָ�벻Ϊ��
	if (ps->size == 0) {
		printf("��ʾ��ͨѶ¼Ϊ�գ�û�п���ɾ������ϵ��\n");
		return;
	}

	ps->size--;  // ����ͨѶ¼�Ĵ�С���Ƴ����һ��Ԫ��
	printf("��ʾ�����һ����ϵ���ѳɹ�ɾ��\n");
}

//�޸�ָ����ϵ�˵���Ϣ
void ConModify(Con* ps, int index, PerInfo updatedContact)
{
	assert(ps);
	if (index < 0 || index >= ps->size) {
		printf("�����������Ч���޷��޸���ϵ����Ϣ��\n");
		return;
	}
	// ����ָ������������ϵ����Ϣ
	ps->arr[index] = updatedContact;
	//���µ���ϵ����Ϣ updatedContact ��ֵ�� arr ����ĵ� index ��λ�á��������ʵ������һ���ṹ�帳ֵ���������� updatedContact �ṹ������г�Ա�������������Ա����䡢�绰����͵�ַ�ȣ����Ƶ� arr[index] ��ָ��Ľṹ���С�����ζ��ԭ���洢�ڸ�����λ�õ���ϵ����Ϣ�ᱻ��ȫ�滻Ϊ���ṩ����Ϣ��
	printf("��ϵ����Ϣ�ѳɹ����£�%s %s %d %s %s\n", updatedContact.name, updatedContact.gender, updatedContact.age, updatedContact.telephone, updatedContact.address);
}


//����ָ����ϵ�˵���Ϣ
void ConSearch(Con* ps, const char* targetName)
{
	assert(ps);  // ȷ��ͨѶ¼ָ�벻Ϊ��
	int found = 0;  // ���ڼ�¼�Ƿ��ҵ���ϵ��

	for (int i = 0; i < ps->size; i++) {
		if (strcmp(ps->arr[i].name, targetName) == 0) {
			printf("�ҵ���ϵ��: ������%s, �Ա�%s, ���䣺%d, �绰��%s, ��ַ��%s\n",
				ps->arr[i].name, ps->arr[i].gender, ps->arr[i].age,
				ps->arr[i].telephone, ps->arr[i].address);
			found = 1;  // ���Ϊ�ҵ�
		}
	}

	if (!found) {
		printf("δ�ҵ���ϵ�ˣ�%s\n", targetName);
	}
}


// ��ӡ������ϵ����Ϣ
void ConDisplayAll(Con * ps)
{
	assert(ps);  // ȷ��ͨѶ¼ָ�벻Ϊ��
	if (ps->size == 0) {
		printf("ͨѶ¼Ϊ�գ�û����ϵ����Ϣ����ʾ��\n");
		return;
	}

	printf("ͨѶ¼����������ϵ�ˣ�\n");
	for (int i = 0; i < ps->size; i++) {
		printf("%d. ������%s, �Ա�%s, ���䣺%d, �绰��%s, ��ַ��%s\n",
			i + 1,
			ps->arr[i].name,
			ps->arr[i].gender,
			ps->arr[i].age,
			ps->arr[i].telephone,
			ps->arr[i].address);
	}
}

// ����������ϵ����Ϣ���ļ�
void ConSave(Con* ps, const char* filename)
{
	assert(ps);  // ȷ��ͨѶ¼ָ�벻Ϊ��
	FILE* file = fopen(filename, "w");  // ���ļ�����д��
	if (file == NULL) {
		perror("�޷����ļ�");
		return;
	}

	// д��ͨѶ¼��С�������ڼ�������
	fprintf(file, "%d\n", ps->size);
	for (int i = 0; i < ps->size; i++) {
		fprintf(file, "%s,%s,%d,%s,%s\n",
			ps->arr[i].name,
			ps->arr[i].gender,
			ps->arr[i].age,
			ps->arr[i].telephone,
			ps->arr[i].address);
	}

	fclose(file);  // �ر��ļ�
	printf("ͨѶ¼�ѳɹ����浽�ļ���%s\n", filename);
}

// ����ͨѶ¼����
void ConLoad(Con* ps, const char* filename)
{
	assert(ps);
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		perror("�޷����ļ�");
		return;
	}

	int size;
	fscanf(file, "%d\n", &size);  // ��ȡͨѶ¼��С
	for (int i = 0; i < size; i++) {
		PerInfo info;
		fscanf(file, "%[^,],%[^,],%d,%[^,],%[^\n]\n",
			info.name,
			info.gender,
			&info.age,
			info.telephone,
			info.address);
		ConPushBack(ps, info);  // ����ȡ����Ϣ��ӵ�ͨѶ¼
	}

	fclose(file);
	printf("ͨѶ¼�����Ѵ��ļ���%s �������\n", filename);
}