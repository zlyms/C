#include <stdio.h>
#include <windows.h>

#define EASY_count 10  //�����Ѷ��µ��׵ĸ��� ��Ϊ10

#define ROW 9          //���̵�����
#define COL 9          //���̵�����

#define ROWS 11        //ʵ�ʶ����������������������
#define COLS 11        //�����˶�����Ϊ���Ų���ʱ����������Խ������


//��֮ǰ��ȣ�����һ���ж�ʤ���ķ���
int win_s;             //win_s���ڼ�¼����˶�����ȷ�ĵ���                      
                       //��win_s == EASY_countʱ������Ϸʤ��

void game();

//��ʼ������
void Intboard(char board[ROWS][COLS], int rows, int cols, char aim);

//��ӡ����
void Displayboard(char board[ROWS][COLS], int row, int col);

//������
void Setmine(char board[ROWS][COLS], int row, int col);

//�Ų���
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//�Ż��Ų���
void get_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col, int* p);

//�����
void Setnote(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col);