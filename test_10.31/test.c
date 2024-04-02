//求一个数在内存中1的个数
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
	printf("在内存中1的个数为%d", count);
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
	//printf("10在内存中1的个数为%d",  count);
	//test();
	test2();
	return 0;
	
}
