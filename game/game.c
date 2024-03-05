#include "game.h"

//��ʼ������
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

//��ӡ����

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


//������
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


//�Ų���Χ�˸��ܼƵ�����
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

//��Ϸ�Ų��׵�������
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//ѡ��Ҫ�����Ų��׻�����
	//����Ҫ�Ų�������Ҫ��ǵ�����
	//�ж�����������Ƿ����
	int x = 0, y = 0, flag = 0, note = 0, win = 0;
	int* p = &win;
	while (1)
	{
		printf("��ѡ��Ҫ��0.�Ų���  1.�����\n");
		scanf("%d", &note);
		switch (note)
		{
		case 0:
		opt:
			printf("������Ҫ�Ų����\n���꣨�к� �кţ���");
			scanf("%d %d", &x, &y);
			system("cls");
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					Displayboard(mine, row, col);
					do
					{
						printf("����0������һ������:");
						scanf("%d", &flag);
						if (flag == 0)
							goto exit;
						else
						{
							printf("�����������������\n");
							Displayboard(show, row, col);
						}
						Sleep(2500);
					} while (flag);
					break;
				}
				else
				{
					//�õݹ�ʵ���Զ��Ų���Χ���׵ĸ���
					get_mine(mine, show, x, y, row, col, p);
					//��ʾ�Ų����Ϣ
					Displayboard(show, row, col);

				}
			}
			else
			{
				printf("���겻�Ϸ�������������\n");
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
			printf("��ϲ�㣬���׳ɹ�\n");
			win = 0;
			win_s = 0;
			Sleep(5000);
		exit:
			system("cls");
			break;
		}
	}
}

//����ݹ麯��
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

//����׵ĺ�������
void Setnote(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)
{
	while (1)
	{
		printf("������Ҫ��ǵ��׵����꣺");
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
			printf("�������겻�Ϸ�������������\n");
			Displayboard(show, row, col);
		}
	}
	Displayboard(show, row, col);
}