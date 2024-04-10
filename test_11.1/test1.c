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