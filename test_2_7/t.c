#define _CRT_SECURE_NO_WARNINGS 1 
#pragma warning(distable:4996) 
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main() {
    FILE* file;

    // 尝试打开一个不存在的文件
    file = fopen("nonexistentfile.txt", "r");

    if (file == NULL) {
        // 如果文件打开失败，输出相应的错误消息
        printf("Error message: %s\n", strerror(errno));
    }
    else {
        // 如果文件成功打开，关闭文件
        fclose(file);
    }

    return 0;
}