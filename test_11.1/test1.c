#include<stdio.h>
void InsertSort()
{
	int arr[] = { 6,5,4,7,23,11,8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n - 1; ++i)
	{
		//��¼�����������һ��Ԫ�ص��±�
		int end = i;
		//�������Ԫ��
		int tem = arr[end + 1];
		//������
		while (end >= 0)
		{
			//�Ȳ��������������
			if (tem < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//�Ȳ������С������ѭ��
			else
			{
				break;
			}
		}
		//tem�ŵ��Ȳ������С�����ĺ���
		arr[end + 1] = tem;
		//����ִ�е���λ�����������:
		//1.������Ԫ���ҵ�Ӧ����λ�ã�break����ѭ�����ˣ�
		//2.������Ԫ�رȵ�ǰ���������е�����Ԫ�ض�С��whileѭ�������󵽴ˣ�
	}
}

void InsertSort1() 
{
	int arr[] = { 6,5,4,7,23,11,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int end = 0;
	int tem;
	while (end<len-1) 
	{
		
		for (int i = end; i>=0; i--) 
		{
			
			if (arr[i] > arr[i + 1]) 
			{
				tem = arr[i + 1];
				arr[i+1] = arr[i];
				arr[i] = tem;
				
			}
			else
			{
				
				end++;
				break;
			}
			
		}
		
		
	}
	for (int i = 0; i < len; i++) 
	{
		printf("%d,", arr[i]);
	}
	
}

int main() 
{

	InsertSort1();
	return 0;
}