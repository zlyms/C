#include<stdio.h>
//�ַ�������
//ʵ��һ�����������ַ�����k���ַ�
//���磺ABCD����һ���ַ�ΪBCDA
//      ABCD���������ַ�ΪCDAB
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
//дһ���ж��ַ����ǲ�������֮����ַ���
//���磺����S1=ABCDE��S2=BCDEA ����1
//          S1=adsad,S2=d2dvfd ����0

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