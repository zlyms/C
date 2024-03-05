#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"//引用自己编译的头文件
static char board[ROW][COL];
void game()
{
	
	RenewBoard(board, ROW, COL);//初始化棋盘
	PrintBoard(board, ROW, COL);//打印棋盘
	char ret;
	while (1)
	{
		UserPlay(board, ROW, COL);//玩家下棋
		ret=IsWin(board, ROW, COL);
		if (ret == 'W')
		{
			printf("恭喜你赢了\n");
			PrintBoard(board, ROW, COL);
			break;
		}
		if (ret == 'P')
		{
			printf("平局");
			break;
		}

		PrintBoard(board, ROW, COL);
		ComputerPlay2(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret == 'W')
		{
			printf("电脑赢了\n");
			PrintBoard(board, ROW, COL);
			break;
		}
		PrintBoard(board, ROW, COL);
	}
}
	
void choose() 
{
	printf("************    game  *****************\n"); 
	printf("************1.开始游戏*****************\n");
	printf("************0.退出游戏*****************\n");
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
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;

		default:
			printf("输入错误请输入0或1\n");
			break;
		}
	} while (a);
	return 0;
}