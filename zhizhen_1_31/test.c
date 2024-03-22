#include<stdio.h>
void test1(int arr[5]) 
{
	for (int i = 0; i < 5; i++) 
	{
	printf("%d", arr[i])	;
	}
}


int main() 
{
	int arr[] = { 1,2,3,4,5 };
		test(arr);
	return 0;
}
//int main() 
//{
//	//int a = 1;
//	//char* p = (char * ) & a;//对这块内存地址一个地址访问
//
//	//char arr1[] = "fsfferge";
//	//char arr2[] = "fsfferge";
//	//char* p1 = "fsfferge";
//	//char* p2 = "fsfferge";
//	//if(p1 == p2) 
//	//{
//	//	printf("p1 p2相同");
//	//}
//
//	//int arr1[] = { 1,2,5,6,2,5 };
//	//int arr2[] = { 2,3,4,6,1,5 };
//	//int arr3[] = { 5,2,5,8,2,7 };
//	//int* par[] = { arr1,arr2,arr3 };
//	//for (int i = 0; i < 3; i++) 
//	//{
//	//	for (int j = 0; j < 6; j++) 
//	//	{
//	//		printf("%d " ,* (par[i] + j));
//	//	}
//	//	printf("\n");
//	//}
//
//
//	//int arr[] = { 1,2,5,6,2,5 };
//	//int(*pa)[6] = &arr;//加括号声明一个指针变量，不加pa与[]结合成一个数组这与结合性有关不过多阐述
//
//	/*int arr2[][5] = { {2,3,1,4,5},{1,3,5,2,4},{5,2,1,4,3} };
//	int(*pa)[5] = arr2;
//	for (int i = 0; i < 3; i++) 
//	{
//		for (int j = 0; j < 5; j++) 
//		{
//			printf("%d ", *(*(pa + i) + j));
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", *(*(arr2 + i) + j));
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ",arr2[i][j]);
//		}
//		printf("\n");
//	}*/
//
//	int arr[] = { 1,2,3,4,5 };
//	test(arr);
//	return 0;
//}