#include"contact.h"
#include<stdio.h>
void Initailizetxl(txl* p)
{
	p->sz = 0;
	memset(p->c, 0, sizeof(p->c));

}
void Inputinformation(txl* p,int lc)
{
	printf("���������֣�");
	scanf("%s", p->c[lc].name);
	printf("�������Ա�");
	scanf("%s", p->c[lc].sex);
	printf("���������䣺");
	scanf("%d", &(p->c[lc].age));
	printf("�������ַ��");
	scanf("%s", p->c[lc].address);
	printf("������绰��");
	scanf("%d", &(p->c[lc].number));
}
int  AddInformation(txl* p)
{

	if (p->sz == 1000)
	{
		return 0;
	}
	else
	{
		Inputinformation(p,p->sz);
		p->sz++;
		return 1;
	}
}
void PrintContact(txl* p)//��ӡͨѶ¼����Ϣ
{
	printf("%-20s\t", "����");
	printf("%-10s\t", "�Ա�");
	printf("%-2s\t",  "����");
	printf("%-10s\t", "��ַ");
	printf("%-5s\n", "����");
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

	if (p->sz == 0) //szΪ0˵������û������
	{
		printf("ͨѶ¼��û������\n");
		return 0;
	}
	else 
	{
		
		int ret=FindInformation(p);
		if (ret < 0) 
		{
			return 0;
		}
		for (int i = ret; i < p->sz-1 ; i++) 
		{
			p->c[i] = p->c[i + 1];

		}
		printf("ɾ���ɹ�\n");
		p->sz--;
		return 1;
	}

}
int ModifyInformation(txl* p)//���������޸���Ϣ
{
	int ret=FindInformation(p);
	if (ret<0)
	{
		
		return 0;
	}
	else
	{
		Inputinformation(p, ret);
		printf("�޸ĳɹ�\n");
		return 1;
	}


}
int FindInformation(txl* p)//�������ֲ�����Ϣ
{
	if (p->sz == 0)
	{
		printf("ͨѶ¼��û������");
		return -1;
	}
	char namef[Name_Max] = { 0 };
	printf("�����������������");
	scanf("%s", namef);
	for (int i = 0;i < p->sz; i++) 
	{
		if (strcmp(namef, p->c[i].name) == 0)
		{
			printf("�Ѿ��ҳ���\n");
			printf("%-20s\t", (p->c)[i].name);
			printf("%-10s\t", (p->c)[i].sex);
			printf("%-2d\t", (p->c)[i].age);
			printf("%-10s\t", (p->c)[i].address);
			printf("%-2d\n", (p->c)[i].number);
			return i;
		}
		

	}
	printf("���޴���\n");
	return -1;
}
int cmp_struct_name(void* e1, void* e2) //Ϊqsortʵ�ֱȽϺ���
{
	contacter* p1 = (contacter*)e1;
	contacter* p2 = (contacter*)e2;
	return strcmp(p1->name, p2->name);
}
int  SortInformation(txl* p)//����
{
	if (p->sz == 0)
	{
		return 0;
	}
	qsort(p->c, p->sz, sizeof(p->c[0]), cmp_struct_name);
}