#include"contact.h"
#include<stdio.h>
void Initailizetxl(txl* p)
{
	p->sz = 0;
	p->capacity = 2;
	p->c = (contacter*)malloc(sizeof(contacter) * p->capacity);
	if (p->c == NULL) 
	{
		printf("申请失败");
		perror("Initailizetxl:");
	}

}
void Inputinformation(txl* p, int lc)
{
	printf("请输入名字：");
	scanf("%s", p->c[lc].name);
	printf("请输入性别：");
	scanf("%s", p->c[lc].sex);
	printf("请输入年龄：");
	scanf("%d", &(p->c[lc].age));
	printf("请输入地址：");
	scanf("%s", p->c[lc].address);
	printf("请输入电话：");
	scanf("%d", &(p->c[lc].number));
}
int  AddInformation(txl* p)
{

	if (p->sz == p->capacity)
	{
		contacter* ptr = (contacter*)realloc(p->c,sizeof(contacter) * p->capacity+AddCapacity);
		if (ptr != NULL) 
		{
			p->c = ptr;
			printf("扩容成功\n");
		}else
		{
			printf("扩容失败\n");
			perror("AddInformation:");
		}
		
	}
	

	

		Inputinformation(p, p->sz);
		p->sz++;
		return 1;
	

}
void PrintContact(txl* p)//打印通讯录中信息
{
	printf("%-20s\t", "姓名");
	printf("%-10s\t", "性别");
	printf("%-2s\t", "年龄");
	printf("%-10s\t", "地址");
	printf("%-5s\n", "号码");
	for (int i = 0; i < p->sz; i++)
	{
		printf("%-20s\t", (p->c)[i].name);
		printf("%-10s\t", (p->c)[i].sex);
		printf("%-2d\t", (p->c)[i].age);
		printf("%-10s\t", (p->c)[i].address);
		printf("%-2d\n", (p->c)[i].number);
	}
}
int DelegateInformation(txl* p)
{

	if (p->sz == 0) //sz为0说明其中没有数据
	{
		printf("通讯录中没有数据\n");
		return 0;
	}
	else
	{

		int ret = FindInformation(p);
		if (ret < 0)
		{
			return 0;
		}
		for (int i = ret; i < p->sz - 1; i++)
		{
			p->c[i] = p->c[i + 1];

		}
		printf("删除成功\n");
		p->sz--;
		return 1;
	}

}
int ModifyInformation(txl* p)//根据名字修改信息
{
	int ret = FindInformation(p);
	if (ret < 0)
	{

		return 0;
	}
	else
	{
		Inputinformation(p, ret);
		printf("修改成功\n");
		return 1;
	}


}
int FindInformation(txl* p)//根据名字查找信息
{
	if (p->sz == 0)
	{
		printf("通讯录中没有内容");
		return -1;
	}
	char namef[Name_Max] = { 0 };
	printf("请输入查找人姓名：");
	scanf("%s", namef);
	for (int i = 0; i < p->sz; i++)
	{
		if (strcmp(namef, p->c[i].name) == 0)
		{
			printf("已经找出：\n");
			printf("%-20s\t", (p->c)[i].name);
			printf("%-10s\t", (p->c)[i].sex);
			printf("%-2d\t", (p->c)[i].age);
			printf("%-10s\t", (p->c)[i].address);
			printf("%-2d\n", (p->c)[i].number);
			return i;
		}


	}
	printf("查无此人\n");
	return -1;
}
int cmp_struct_name(void* e1, void* e2) //为qsort实现比较函数
{
	contacter* p1 = (contacter*)e1;
	contacter* p2 = (contacter*)e2;
	return strcmp(p1->name, p2->name);
}
int  SortInformation(txl* p)//排序
{
	if (p->sz == 0)
	{
		return 0;
	}
	qsort(p->c, p->sz, sizeof(p->c[0]), cmp_struct_name);
}
void destoryInformation(txl* p) 
{
	free(p->c);
	p->sz = 0;
	p->capacity = 0;
	p->c = NULL;
}