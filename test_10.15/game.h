#pragma once
#define ROW 10
#define COL 10
#define ROWS ROW+2
#define COLS COL+2
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void RenewBoard(char board[ROW][COL], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void UserPlay(char board[ROW][COL], int row, int col);
void ComputerPlay(char board[ROW][COL], int x, int y);
char IsWin(char board[ROW][COL], int row, int col);