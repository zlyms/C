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

    // 以二进制读取模式打开文件
    fp = fopen("test.txt", "rb");

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        return 1;
    }
    // 从文件中读取字符直到文件末尾
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch); // 输出字符
    }

    // 关闭文件
    fclose(fp);
    

    return 0;
}