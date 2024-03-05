#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

void click(int row, int col, int board[ROWS][COLS], bool visited[ROWS][COLS]) {
    // �����λ���Ƿ�Խ����Ѿ������ʹ�
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || visited[row][col]) {
        return;
    }

    // ��ǵ�ǰλ��Ϊ�ѷ���
    visited[row][col] = true;

    // �����ǰλ��Ϊ�հ׷��飬������ɢ
    if (board[row][col] == 0) {
        // ����Χ8�������ϵݹ�ص��õ������
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                click(row + i, col + j, board, visited);
            }
        }
    }
}

int main() {
    // ʾ����Ϸ��ͼ
    int board[ROWS][COLS] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, -1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // ��������Ϸ��ͼ��С��ͬ�ķ��ʱ������
    bool visited[ROWS][COLS] = { {false} };

    // ִ�е����ɢ
    click(2, 2, board, visited);

    // �����ɢ���
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (visited[row][col]) {
                printf("* ");
            }
            else {
                printf("%d ", board[row][col]);
            }
        }
        printf("\n");
    }

    return 0;
}