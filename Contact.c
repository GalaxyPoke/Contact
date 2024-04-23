#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
//通讯录的初始化
void ConInit(Con* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//通讯录的扩容
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

//通讯录的销毁
void ConDestroy(Con* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//添加联系人信息到第一个位置
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

//添加联系人信息到最后一个位置
void ConPushBack(Con* ps, PerInfo newContact)
{
	assert(ps);
	ConCheckcapacity(ps);
	ps->arr[ps->size] = newContact;
	ps->size++;
}

//删除第一个联系人信息
void ConPopFront(Con* ps)
{
	assert(ps);
	if (ps->size == 0) 
	{
		printf("提示：这个联系人列表是空的，没有东西可以删除\n");
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
	printf("提示：第一个联系人删除成功\n");
}


//删除最后一个联系人信息
void ConPopBack(Con* ps)
{
	assert(ps);  // 确保通讯录指针不为空
	if (ps->size == 0) {
		printf("提示：通讯录为空，没有可以删除的联系人\n");
		return;
	}

	ps->size--;  // 减少通讯录的大小，移除最后一个元素
	printf("提示：最后一个联系人已成功删除\n");
}

//修改指定联系人的信息
void ConModify(Con* ps, int index, PerInfo updatedContact)
{
	assert(ps);
	if (index < 0 || index >= ps->size) {
		printf("输入的索引无效，无法修改联系人信息。\n");
		return;
	}
	// 更新指定索引处的联系人信息
	ps->arr[index] = updatedContact;
	//将新的联系人信息 updatedContact 赋值给 arr 数组的第 index 个位置。这个操作实质上是一个结构体赋值操作，它将 updatedContact 结构体的所有成员（包括姓名、性别、年龄、电话号码和地址等）复制到 arr[index] 所指向的结构体中。这意味着原来存储在该索引位置的联系人信息会被完全替换为新提供的信息。
	printf("联系人信息已成功更新：%s %s %d %s %s\n", updatedContact.name, updatedContact.gender, updatedContact.age, updatedContact.telephone, updatedContact.address);
}


//查找指定联系人的信息
void ConSearch(Con* ps, const char* targetName)
{
	assert(ps);  // 确保通讯录指针不为空
	int found = 0;  // 用于记录是否找到联系人

	for (int i = 0; i < ps->size; i++) {
		if (strcmp(ps->arr[i].name, targetName) == 0) {
			printf("找到联系人: 姓名：%s, 性别：%s, 年龄：%d, 电话：%s, 地址：%s\n",
				ps->arr[i].name, ps->arr[i].gender, ps->arr[i].age,
				ps->arr[i].telephone, ps->arr[i].address);
			found = 1;  // 标记为找到
		}
	}

	if (!found) {
		printf("未找到联系人：%s\n", targetName);
	}
}


// 打印所有联系人信息
void ConDisplayAll(Con * ps)
{
	assert(ps);  // 确保通讯录指针不为空
	if (ps->size == 0) {
		printf("通讯录为空，没有联系人信息可显示。\n");
		return;
	}

	printf("通讯录包含以下联系人：\n");
	for (int i = 0; i < ps->size; i++) {
		printf("%d. 姓名：%s, 性别：%s, 年龄：%d, 电话：%s, 地址：%s\n",
			i + 1,
			ps->arr[i].name,
			ps->arr[i].gender,
			ps->arr[i].age,
			ps->arr[i].telephone,
			ps->arr[i].address);
	}
}

// 保存所有联系人信息到文件
void ConSave(Con* ps, const char* filename)
{
	assert(ps);  // 确保通讯录指针不为空
	FILE* file = fopen(filename, "w");  // 打开文件用于写入
	if (file == NULL) {
		perror("无法打开文件");
		return;
	}

	// 写入通讯录大小，可用于加载数据
	fprintf(file, "%d\n", ps->size);
	for (int i = 0; i < ps->size; i++) {
		fprintf(file, "%s,%s,%d,%s,%s\n",
			ps->arr[i].name,
			ps->arr[i].gender,
			ps->arr[i].age,
			ps->arr[i].telephone,
			ps->arr[i].address);
	}

	fclose(file);  // 关闭文件
	printf("通讯录已成功保存到文件：%s\n", filename);
}

// 加载通讯录数据
void ConLoad(Con* ps, const char* filename)
{
	assert(ps);
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		perror("无法打开文件");
		return;
	}

	int size;
	fscanf(file, "%d\n", &size);  // 读取通讯录大小
	for (int i = 0; i < size; i++) {
		PerInfo info;
		fscanf(file, "%[^,],%[^,],%d,%[^,],%[^\n]\n",
			info.name,
			info.gender,
			&info.age,
			info.telephone,
			info.address);
		ConPushBack(ps, info);  // 将读取的信息添加到通讯录
	}

	fclose(file);
	printf("通讯录数据已从文件：%s 加载完成\n", filename);
}