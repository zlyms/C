#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"//�����Լ������ͷ�ļ�
static char board[ROW][COL];
void game()
{
	
	RenewBoard(board, ROW, COL);//��ʼ������
	PrintBoard(board, ROW, COL);//��ӡ����
	char ret;
	while (1)
	{
		UserPlay(board, ROW, COL);//�������
		ret=IsWin(board, ROW, COL);
		if (ret == 'W')
		{
			printf("��ϲ��Ӯ��\n");
			PrintBoard(board, ROW, COL);
			break;
		}
		if (ret == 'P')
		{
			printf("ƽ��");
			break;
		}

		PrintBoard(board, ROW, COL);
		ComputerPlay2(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret == 'W')
		{
			printf("����Ӯ��\n");
			PrintBoard(board, ROW, COL);
			break;
		}
		PrintBoard(board, ROW, COL);
	}
}
	
void choose() 
{
	printf("************    game  *****************\n"); 
	printf("************1.��ʼ��Ϸ*****************\n");
	printf("************0.�˳���Ϸ*****************\n");
}
int main() 
{
	int a;
	choose();

	
	do
	{
		scanf_s("%d", &a);
		switch (a)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			game();
			break;

		default:
			printf("�������������0��1\n");
			break;
		}
	} while (a);
	return 0;
}