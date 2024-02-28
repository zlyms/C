#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
int My_Strlen(char* pa) //获取内存地址
{
	if (*pa != '\0')//解引用取值,设置出口条件
	{

		return	 My_Strlen(pa + 1) + 1;//MS(str+3)->MS(str+2)->MS(str+1)指针下,回归执行完当前语句

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