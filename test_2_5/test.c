#include<stdio.h>
//字符串左旋
//实现一个函数左旋字符串中k个字符
//例如：ABCD左旋一个字符为BCDA
//      ABCD左旋两个字符为CDAB
void test1(char* arr, int s, int k)
{
	char temp;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < s -1; j++)
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}
}
//写一个判断字符串是不是左旋之后的字符串
//例如：给定S1=ABCDE，S2=BCDEA 返回1
//          S1=adsad,S2=d2dvfd 返回0

int judge_leftRevolve(char *s1,char *s2,int s) 
{
	
	char temp;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s - 1; j++)
		{
			temp = s1[j];
			s1[j] = s1[j + 1];
			s1[j + 1] = temp;
		}
		for (int j = 0; j < s; j++) 
		{
			if (s1[j] != s2[j]) 
			{
				break;
			}
			if (j == s - 1) 
			{
				return 1;
			}
		}
	}
	return 0;

}

int main() 
{
	//char arr[] = "ABCDE";
	//int s = 5;
	//int k = 2;
	//test1(arr,s,k);
	//for (int i=0; i < s; i++) 
	//{
	//	printf("%c", arr[i]);
	//}
	char arr1[] = "ABCDE";
	char arr2[] = "BCAEA";
	printf("%d", judge_leftRevolve(arr1, arr2,5));
	return 0;
}