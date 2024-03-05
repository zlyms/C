#include"game.h"
#include <stdlib.h>
#include <time.h>

void RenewBoard(char board[ROW][COL],int row,int col) 
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < row -1)
				printf("|");
		}	
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < ROW - 1)
					printf("|");

			}
		}
		
		printf("\n");
	}
}



void UserPlay(char board[ROW][COL], int row, int col)
{
	while (1) {
		int x = 0, y = 0;
		scanf("%d %d", &x, &y);
		if (x <= row && y <= col && x>=1 && y>=1)
		{
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
					break;
			}
			else 
			{
				printf("该位置以落子，重新输入");
			}
			
		}
		else
		{
			printf("输入非法,重新输入");
		}
	}
	
}
void ComputerPlay(char board[ROW][COL], int row, int col) {
	srand((unsigned)time(NULL));
	
	while(1)
	{
		int x = rand() % row;//取模得0到row-1
		int y = rand() % col;
		if (board[x][y] == ' ')
		{

			board[x][y] = '#';
			break;
		}
	}
	
	
	//int i, j;
	//for (i = 0; i < row; i++)
	//{
	//	for (j = 0; j < col; j++)
	//	{
	//		if (board[i][j] == ' ') 
	//		{
	//		
	//		}
	//	}

	//}
	

}
char* judgeWin(char board[ROW][COL],int row, int col)
	{
	int i, j;
	for (i = 1; i < row; i++)
	{
		for (j = 1; j < row; j++) {
			if (i > 0 && j > 0 && i < row - 1 && j < col - 1)
			{
				if (board[i][j] == board[i][j - 1] && board[i][j + 1] == ' ' && board[i][j] != ' ')//行
				{
					return &board[i][j + 1];
				}
				else if (board[i][j] == board[i][j + 1] && board[i][j - 1] == ' ' && board[i][j] != ' ')
				{
					return &board[i][j - 1];
				}
				else if (board[i][j - 1] == board[i][j + 1] && board[i][j] == ' ' && board[i][j - 1] != ' ')
				{
					return &board[i][j];
				}
				else if (board[i][j] == board[i - 1][j - 1] && board[i + 1][j + 1] == ' ' && board[i][j] != ' ') //斜
				{
					return &board[i + 1][j + 1];
				}
				else if (board[i + 1][j + 1] == board[i - 1][j - 1] && board[i][j] == ' ' && board[i + 1][j + 1] != ' ')
				{
					return &board[i][j];
				}
				else if (board[i][j] == board[i - 1][j + 1] && board[i + 1][j - 1] == ' ' && board[i][j] != ' ')
				{
					return &board[i + 1][j - 1];
				}
				else if (board[i + 1][j - 1] == board[i][j] && board[i - 1][j + 1] == ' ' && board[i][j] != ' ')
				{
					return &board[i - 1][j + 1];
				}
				else if (board[i][j] == board[i + 1][j + 1] && board[i - 1][j - 1] == ' ' && board[i][j] != ' ')
				{
					return &board[i - 1][j - 1];
				}
				else if (board[i + 1][j - 1] == board[i - 1][j + 1] && board[i][j] == ' ' && board[i + 1][j - 1] != ' ')
				{
					return &board[i][j];
				}

				else if (board[i][j] == board[i + 1][j] && board[i - 1][j] == ' ' && board[i][j] != ' ')//列
				{
					return &board[i - 1][j];
				}
				else if (board[i][j] == board[i - 1][j] && board[i + 1][j] == ' ' && board[i][j] != ' ')
				{
					return &board[i + 1][j];
				}
				else if (board[i + 1][j] == board[i - 1][j] && board[i][j] == ' ' && board[i + 1][j] != ' ')
				{
					return &board[i][j];
				}
			}
			


		}
		
			

		srand((unsigned)time(NULL));

			while (1)
			{
				int x = rand() % row;//取模得0到row-1
				int y = rand() % col;
				if (board[x][y] == ' ')
				{

					return &board[x][y];
				}
			}
			
	}
	
}
void ComputerPlay2(char board[ROW][COL], int row, int col)
{
	char* ret = judgeWin(board,row, col);
	*ret = '#';
}
char IsWin(char board[ROW][COL], int row, int col) 
{
	int i;
	int j;
	for (i = 0; i < row; i++) 
	{
		if (board[i][0] == board[i][1]&& board[i][1] == board[i][2]&& board[i][1]!=' ')
		{
			return 'W';

		}
		
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j]&& board[1][j] == board[2][j]&& board[1][j]!=' ')
		{
			return 'W';

		}
		
	}
	if (board[0][0] == board[1][1]&& board[1][1] == board[2][2]&& board[0][0]!=' ')
		return 'W';
	if (board[0][2] == board[1][1]&& board[1][1] == board[3][0]&& board[1][1]!=' ')
		return 'W';
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < col; j++) 
		{
			if (board[i][j] == ' ')
			{
				break;
			}
		}
		if (board[i][j] == ' ')
		{
			break;
		}
		else 
		{
			return 'P';
		
		}
	}
	return 'C';

}

