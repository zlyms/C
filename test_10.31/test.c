//��һ�������ڴ���1�ĸ���
#include <stdio.h>
void test()
{
	int nums = 3;
	int count = 0;
	int i = 1;
	while (i <= nums)
	{
		if ((nums & i) == i)
		{
			count++;
		}
		i *= 2;
	}
	printf("���ڴ���1�ĸ���Ϊ%d", count);
}
void test2() 
{
	for (int i = 0; i < 10; ++i) 
	{
		printf("%d",i);
	}
}
int main() 
{
	int num = 10;
	 
	int count = 0;
	while (num) 
	{
		count += num % 2;
		num /= 2;
	}
	//printf("10���ڴ���1�ĸ���Ϊ%d",  count);
	//test();
	test2();
	return 0;
	
}
