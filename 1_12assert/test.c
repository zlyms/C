#include <assert.h>
#include<stdio.h>
int fib(int a) 
{
	if (a == 1) 
	{
		return 1;
	}
	if (a == 0) 
	{
		return 0;
	}
	return fib(a - 1) + fib(a - 2);
}
int main()
{
	int a = 10l;
	const int* p = &a;
	p = 10;	/*����������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬
	����(�)	E0137	���ʽ�����ǿ��޸ĵ���ֵ	1_12assert	D : \git\practice daily\1_12assert\test.c	6*/
	printf("%d",fib(8));
	return 0;
}

