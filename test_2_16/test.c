#pragma warning(disable:4996)
#include<stdio.h>

//#define Print(X,S) printf("this is"#X S,a) ;
//int main()
//{
//	float a = 5;
//	Print(a," % f")
//	return 0;
//}

//int main() 
//{
//	FILE* fptr = fopen("test.txt","r");
//	fputc("b", fptr);
//	fclose(fptr);
//	return 0;
//}


#include <stdio.h>

int main() {
    FILE* fp;
    char ch;

    // �Զ����ƶ�ȡģʽ���ļ�
    fp = fopen("test.txt", "rb");

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        return 1;
    }
    // ���ļ��ж�ȡ�ַ�ֱ���ļ�ĩβ
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch); // ����ַ�
    }

    // �ر��ļ�
    fclose(fp);
    

    return 0;
}