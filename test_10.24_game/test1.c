#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

void click(int row, int col, int board[ROWS][COLS], bool visited[ROWS][COLS]) {
    // 检查点击位置是否越界或已经被访问过
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || visited[row][col]) {
        return;
    }

    // 标记当前位置为已访问
    visited[row][col] = true;

    // 如果当前位置为空白方块，继续扩散
    if (board[row][col] == 0) {
        // 在周围8个方向上递归地调用点击函数
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                click(row + i, col + j, board, visited);
            }
        }
    }
}

int main() {
    // 示例游戏地图
    int board[ROWS][COLS] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, -1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // 创建与游戏地图大小相同的访问标记数组
    bool visited[ROWS][COLS] = { {false} };

    // 执行点击扩散
    click(2, 2, board, visited);

    // 输出扩散结果
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