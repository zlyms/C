#include "game.h"

void Description()
{
	int n;
	printf("欢迎来到C语言扫雷游戏，此处为游戏说明\n在游戏中，‘0’表示无雷，‘1’表示有雷\n");
	printf("'*'表示未被排查的区域，‘@’表示自己所标记的雷的位置\n");
	printf("如果您已悉知，请按‘任意键+回车键’确定正式进入游戏选择界面");
	scanf("%d", &n);
	system("cls");
}

void menu()
{
	printf("                              \n");
	printf("                              \n");
	printf("                              \n");
	printf("          扫雷游戏            \n");
	printf("           1.开始             \n");
	printf("           0.退出             \n");
	printf("                              \n");
	printf("                              \n");
	printf("                              \n");
}

void game()
{
	Sleep(1000);
	system("cls");
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息

	//初始化棋盘
	Intboard(mine, ROWS, COLS, '0');
	Intboard(show, ROWS, COLS, '*');

	//打印棋盘
	//Displayboard(mine, ROW, COL);用于检测雷是否正常布置
	Displayboard(show, ROW, COL);

	//布置雷
	Setmine(mine, ROW, COL);
	//Displayboard(mine, ROW, COL);//必要时显示雷盘，便于测试

	//排查雷
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
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}