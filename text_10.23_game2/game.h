#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define ROW 5
#define COL 5
#define ROWS ROW+2
#define COLS COL+2
void Renew(char board[ROWS][COLS], int row, int col, char a);
void Printboard(char board[ROWS][COLS], int row, int col);
void SetBoom(char board[ROWS][COLS], int row, int col);
int ShowRoundBoom(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int ShowRoundBoom2(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int JudgeBoom(char mine[ROWS][COLS], char show[ROWS][COLS]);
char mine[ROWS][COLS];
char show[ROWS][COLS];