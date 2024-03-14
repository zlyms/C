#include<stdio.h>
#include"game.h"
void Renew(char board[ROWS][COLS], int row, int col,char a) //初始化棋盘
{
	int i, j;
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < col; j++) 
		{
			board[i][j] = a;
		}
	}
}
void Printboard(char board[ROWS][COLS], int row, int col) //打印棋盘
{
	int i, j;
	for (i = 0; i < row - 1; i++) 
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row-1; i++)
	{
		printf("%d ", i );
		for (j = 1; j < col-1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
		
	}
	printf("\n");
}
void SetBoom(char board[ROWS][COLS], int row, int col)
{
	srand((unsigned)time(NULL));
	
	
	int count=2;
	while (count) 
	{
		int x = rand(), y = rand();
		x %= row;
		y %= row;
		if (board[x+1][y+1] == '0') 
		{
			count--;
			board[x+1][y+1] = '1';
		}
	}
}
int ShowRoundBoom(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (mine[x][y] == '1') 
	{
		printf("BOOM");
		Printboard(mine, ROWS, COLS);
		return 0;
	}
	else
	{
		int a = mine[x - 1][y - 1] +
			mine[x - 1][y] +
			mine[x - 1][y + 1] +
			mine[x][y - 1] +
			mine[x][y + 1] +
			mine[x + 1][y - 1] +
			mine[x + 1][y] +
			mine[x + 1][y + 1] - 8 * '0';
		show[x][y] = '0' + a;
		Printboard(show, ROWS, COLS);
			return a;

	}

}
int JudgeBoom(char mine[ROWS][COLS], char show[ROWS][COLS])//判断输入位置合法或是炸弹，不是就扩散
{
	int flag = 1;
	int x, y;
	while (flag)
	{
		printf("输入坐标");
		scanf_s("%d %d",&x,&y);
		if (x<1 || y<1 || x>ROW || y>COL) 
		{
			if (mine[x][y] == '1')
			{
				printf("BOOM\n");
				Printboard(mine, ROWS, COLS);
				flag = 0;
			}
			else
			{

				ShowRoundBoom2(mine, show, x, y);
				Printboard(show, ROWS, COLS);
				flag = 1;

			}
		}
		else
		{
			printf("输入错误");
			flag = 1;
		}

	}
		
	
	

}
static int CountBoom(char mine[ROWS][COLS], int x, int y)//统计当前位置周围炸弹数量
{
	int a = mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
	return a;
}
int ShowRoundBoom2(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)//判断当前位置是否有炸弹没有就递下去并为周围置0再判断一下防止数据冗余
{
	int count = CountBoom(mine, x, y);
	
	
	
	if (count != 0) {
		show[x][y] = '0' + count;
		return count;
	}
	else if (count == 0)
	{
		show[x][y] = '0';
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (show[x + i][y + j] == '*')
				{
					ShowRoundBoom2(mine, show, x + i, y + j);
				}
				
			}
		}
		return 1;
	}
}
//void get_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col, int* p)
//{
//
//	if (x > 0 && x <= row && y > 0 && y <= col)
//	{
//		int count = get_mine_count(mine, x, y);
//		if (count == 0)
//		{
//			(*p)++;
//			int a, b;
//			show[x][y] = '0';
//			for (a = -1; a <= 1; a++)
//			{
//				for (b = -1; b <= 1; b++)
//				{
//					if (show[x + a][y + b] == '*')
//						get_mine(mine, show, x + a, y + b, row, col, p);
//				}
//			}
//		}
//		else
//		{
//			(*p)++;
//			show[x][y] = count + '0';
//		}
//	}
//}
//ShowRoundBoom2(mine, show, x - 1, y - 1);
//ShowRoundBoom2(mine, show, x - 1, y);
//ShowRoundBoom2(mine, show, x - 1, y + 1);
//ShowRoundBoom2(mine, show, x, y - 1);
//ShowRoundBoom2(mine, show, x, y + 1);
//ShowRoundBoom2(mine, show, x + 1, y - 1);
//ShowRoundBoom2(mine, show, x + 1, y);
//ShowRoundBoom2(mine, show, x + 1, y + 1);

//ShowRoundBoom2(mine, show, x - 1, y - 1);
//
//ShowRoundBoom2(mine, show, x - 1, y + 1);
//
//
//ShowRoundBoom2(mine, show, x + 1, y - 1);
//
//ShowRoundBoom2(mine, show, x + 1, y + 1);