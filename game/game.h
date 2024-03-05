#include <stdio.h>
#include <windows.h>

#define EASY_count 10  //简易难度下的雷的个数 设为10

#define ROW 9          //雷盘的行数
#define COL 9          //雷盘的列数

#define ROWS 11        //实际定义雷盘数组的行数和列数
#define COLS 11        //往大了定义是为了排查雷时不出现数组越界的情况


//与之前相比，多了一种判定胜利的方法
int win_s;             //win_s用于记录标记了多少正确的的雷                      
                       //当win_s == EASY_count时，则游戏胜利

void game();

//初始化棋盘
void Intboard(char board[ROWS][COLS], int rows, int cols, char aim);

//打印棋盘
void Displayboard(char board[ROWS][COLS], int row, int col);

//布置雷
void Setmine(char board[ROWS][COLS], int row, int col);

//排查雷
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//优化排查雷
void get_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col, int* p);

//标记雷
void Setnote(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col);