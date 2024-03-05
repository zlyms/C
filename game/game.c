#include "game.h"

//初始化棋盘
void Intboard(char board[ROWS][COLS], int rows, int cols, char aim)
{
	int a, b;
	for (a = 0; a < rows; a++)
	{
		for (b = 0; b < cols; b++)
		{
			board[a][b] = aim;
		}
	}
}

//打印棋盘

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int a, b;
	for (a = 0; a <= col; a++)
	{
		if (a == 0)
			printf("    ");
		else
			printf("%d ", a);
	}
	printf("\n");
	for (a = 0; a <= col; a++)
	{
		if (a == 0)
			printf("    ");
		else
			printf("%c ", 'v');
	}
	printf("\n");
	for (a = 1; a <= row; a++)
	{
		printf("%d > ", a);
		for (b = 1; b <= col; b++)
		{
			printf("%c ", board[a][b]);
		}
		printf("\n");
	}
}


//布置雷
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


//排查周围八格总计的雷数
static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

//游戏排查雷的主函数
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//选择要进行排查雷或标记雷
	//输入要排查的坐标或要标记的坐标
	//判断输入的坐标是否合理
	int x = 0, y = 0, flag = 0, note = 0, win = 0;
	int* p = &win;
	while (1)
	{
		printf("请选择要：0.排查雷  1.标记雷\n");
		scanf("%d", &note);
		switch (note)
		{
		case 0:
		opt:
			printf("请输入要排查的雷\n坐标（行号 列号）：");
			scanf("%d %d", &x, &y);
			system("cls");
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					Displayboard(mine, row, col);
					do
					{
						printf("输入0进行下一步操作:");
						scanf("%d", &flag);
						if (flag == 0)
							goto exit;
						else
						{
							printf("输入错误，请重新输入\n");
							Displayboard(show, row, col);
						}
						Sleep(2500);
					} while (flag);
					break;
				}
				else
				{
					//用递归实现自动排查周围无雷的格子
					get_mine(mine, show, x, y, row, col, p);
					//显示排查的信息
					Displayboard(show, row, col);

				}
			}
			else
			{
				printf("坐标不合法，请重新输入\n");
				Displayboard(show, row, col);
				goto opt;
			}

			break;
		case 1:
			Setnote(mine, show, x, y, row, col);
			break;

		}
		if (win == row * col - EASY_count || win_s == EASY_count)
		{
			printf("恭喜你，排雷成功\n");
			win = 0;
			win_s = 0;
			Sleep(5000);
		exit:
			system("cls");
			break;
		}
	}
}

//定义递归函数
void get_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col, int* p)
{

	if (x > 0 && x <= row && y > 0 && y <= col)
	{					
		int count = get_mine_count(mine, x, y);
		if (count == 0)
		{																																																																																																																																																																
			(*p)++;
			int a, b;
			show[x][y] = '0';
			for (a = -1; a <= 1; a++)
			{
				for (b = -1; b <= 1; b++)
				{
					if (show[x + a][y + b] == '*')
						get_mine(mine, show, x + a, y + b, row, col, p);
				}
			}
		}
		else
		{
			(*p)++;
			show[x][y] = count + '0';
		}
	}
}

//标记雷的函数定义
void Setnote(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)
{
	while (1)
	{
		printf("请输入要标记的雷的坐标：");
		scanf("%d %d", &x, &y);
		system("cls");
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] != '0' && show[x][y] != '1')
		{
			show[x][y] = '@';
			if (mine[x][y] == '1')
				win_s++;
			break;
		}
		else
		{
			printf("输入坐标不合法，请重新输入\n");
			Displayboard(show, row, col);
		}
	}
	Displayboard(show, row, col);
}