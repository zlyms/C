#define _CRT_SECURE_NO_WARNINGS 1 
#pragma warning(distable:4996) 
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main() {
    FILE* file;

    // ���Դ�һ�������ڵ��ļ�
    file = fopen("nonexistentfile.txt", "r");

    if (file == NULL) {
        // ����ļ���ʧ�ܣ������Ӧ�Ĵ�����Ϣ
        printf("Error message: %s\n", strerror(errno));
    }
    else {
        // ����ļ��ɹ��򿪣��ر��ļ�
        fclose(file);
    }

    return 0;
}