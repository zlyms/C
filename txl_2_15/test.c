#include<stdio.h>
#include"contact.h"

int main()
{
	enum ctrl//ʹ��ö���ഴ��һ����������ĳ���
	{
		exit,
		print,
		modify,
		del,
		sort,
		add,
		find

	};
	txl t;
	int input = 0;
	Initailizetxl(&t);//��ʼ��
	do
	{
		printf("*******0.exit      1.print*******\n");
		printf("*******2.modify   3.del*******\n");
		printf("*******4.sort     5.add*******\n");
		printf("*******6.find          *******\n");

		scanf("%d", &input);//����ʾ����
		switch (input)//����������ú���
		{
		case add:
			AddInformation(&t);
			break;
		case print:
			PrintContact(&t);
			break;
		case modify:
			ModifyInformation(&t);
			break;
		case del:
			DelegateInformation(&t);
			break;
		case sort:
			SortInformation(&t);
		case find:
			FindInformation(&t);
			break;
		case exit:
			destoryInformation(&t);
			printf("���˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (input);



	return 0;
}


