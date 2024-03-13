#include<stdio.h>
void InsertSort()
{
	int arr[] = { 6,5,4,7,23,11,8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n - 1; ++i)
	{
		//记录有序序列最后一个元素的下标
		int end = i;
		//待插入的元素
		int tem = arr[end + 1];
		//单趟排
		while (end >= 0)
		{
			//比插入的数大就向后移
			if (tem < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//比插入的数小，跳出循环
			else
			{
				break;
			}
		}
		//tem放到比插入的数小的数的后面
		arr[end + 1] = tem;
		//代码执行到此位置有两种情况:
		//1.待插入元素找到应插入位置（break跳出循环到此）
		//2.待插入元素比当前有序序列中的所有元素都小（while循环结束后到此）
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