#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
int My_Strlen(char* pa) //��ȡ�ڴ��ַ
{
	if (*pa != '\0')//������ȡֵ,���ó�������
	{

		return	 My_Strlen(pa + 1) + 1;//MS(str+3)->MS(str+2)->MS(str+1)ָ����,�ع�ִ���굱ǰ���

	}
	else {
		return  0;
	}
} 
int main()
{
	char arr[] = "bit";

	printf("%d", My_Strlen(arr));
	return 0;
}