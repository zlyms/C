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

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	//int n=1;
	//while (n) 
	//{
	//	scanf_s("%d", &n);
	//	Xshape(n);
	//}
	//int n = 0;
	//int x = 0;
	//scanf_s("%d", &n);
	//int arr[20] = { 0 };
	//for (int i = 0; i < n; i++)
	//{
	//	scanf_s("%d", &x);
	//	arr[i]=x;

	//}
	//scanf_s("%d", &x);
	//arr[n] = x;
	//int temp = 0;
	//for (int i = 1; i < n + 1; i++)
	//{
	//	for (int j = i; j > 0; j--)
	//	{
	//		if (arr[j] < arr[j - 1])
	//		{
	//			temp = arr[j];
	//			arr[j] = arr[j - 1];
	//			arr[j - 1] = temp;
	//		}
	//	}


	//}
	InsertSort();

	
	/*for (int i = 0; i < n+1; i++)
	{
		printf("%d ", arr[i]);
	}*/
	return 1;
}