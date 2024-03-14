#include<stdio.h>
#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu() 
{
	printf("---------------扫雷--------------\n");
	printf("**************1.paly*************\n");
	printf("**************0.exit*************\n");
}
void game() 
{
	Renew(mine, ROWS, COLS, '0');
	Renew(show, ROWS, COLS, '*');
	Printboard(mine, ROWS, COLS);
	Printboard(show, ROWS, COLS);
	SetBoom(mine, ROW, COL);
	Printboard(mine, ROWS, COLS);
	int x, y;
	int flag = 1;
	JudgeBoom(mine, show);
		
			
		
	//while (flag)
	//{
	//	printf("输入坐标");
	//	scanf_s("%d %d",&x,&y);
	//	flag =ShowRoundBoom(mine,show,x,y);
	//}
}
int main() 
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	int n = 0;
	do {
		menu();
		
		scanf_s("%d", &n);
		switch (n) 
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出游戏\n");
			break;
		default:
			printf("请输入0或1\n");
			menu();
			break;
		}
			

	} while (n);
	
	
}