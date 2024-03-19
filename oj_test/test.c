#include<stdio.h>
//多组输入，表示输出的行数,也表示反斜线与正斜线的长度
//例如：5
//输出
//  *   *
//   * *
//	  *
//   * * 
//	*   *


void Xshape(int n) 
{
	//*   *1 5
	//* *1 3
	//*1
	//* *1 3 
	//*   *1 5 

	//  *   *3 2
	//   * * 3 2
	//	  *  2 1
	//   * * 3 2
	//	*   *3 2 
		for (int i = 0; i < n; i++)
	{
			if (i<n/2)
			{
				for (int j = 0; j < i; j++)
				{
					printf(" ");

				}
				printf("*");
				for (int j = 0; j < n - (i + 1) * 2; j++)
				{
					printf(" ");

				}
				printf("*");
				printf("\n");
			}
			else if (n % 2 == 1 && i == n / 2 ) 
			{
				for (int j = 0; j < i; j++)
				{
					printf(" ");

				}
				printf("*");
				printf("\n");
			}
			else 
			{
				for (int j =n- i-1; j > 0; j--)
				{
					printf(" ");

				}
				printf("*");
				for (int j = (i-n/2) * 2-(n%2); j > 0; j--)
				{
					printf(" ");
				}
				printf("*");
				printf("\n");
			}
	}
	
}
void InsertSort(int arr[],int sz)
{
	int end=0;
	int temp = 0;
	for (int i = 0; i < sz; i++) 
	{
		for (int j = i; j > 0; j--) 
		{
			if (arr[j] < arr[j-1]) 
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			else { break; }
		}
		
		
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
	int n = 0;
	int x = 0;
	scanf_s("%d", &n);
	int arr[5] = {4,6,1,13,2};
	/*for (int i = 0; i < n; i++) 
	{
		scanf_s("%d", &x);
		arr[i]=x;
			
	}*/
	//InsertSort(arr, n);
	
	int temp = 0;	
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}


	}
	for (int i = 0; i < n; i++) 
	{
		printf("%d ", arr[i]);
	}
	return 1;
}