#include "game.h"

void Description()
{
	int n;
	printf("��ӭ����C����ɨ����Ϸ���˴�Ϊ��Ϸ˵��\n����Ϸ�У���0����ʾ���ף���1����ʾ����\n");
	printf("'*'��ʾδ���Ų�����򣬡�@����ʾ�Լ�����ǵ��׵�λ��\n");
	printf("�������Ϥ֪���밴�������+�س�����ȷ����ʽ������Ϸѡ�����");
	scanf("%d", &n);
	system("cls");
}

void menu()
{
	printf("                              \n");
	printf("                              \n");
	printf("                              \n");
	printf("          ɨ����Ϸ            \n");
	printf("           1.��ʼ             \n");
	printf("           0.�˳�             \n");
	printf("                              \n");
	printf("                              \n");
	printf("                              \n");
}

void game()
{
	Sleep(1000);
	system("cls");
	char mine[ROWS][COLS] = { 0 };//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ

	//��ʼ������
	Intboard(mine, ROWS, COLS, '0');
	Intboard(show, ROWS, COLS, '*');

	//��ӡ����
	//Displayboard(mine, ROW, COL);���ڼ�����Ƿ���������
	Displayboard(show, ROW, COL);

	//������
	Setmine(mine, ROW, COL);
	//Displayboard(mine, ROW, COL);//��Ҫʱ��ʾ���̣����ڲ���

	//�Ų���
	Findmine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	Description();
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}