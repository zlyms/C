#include<stdio.h>
void test1() 
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 2,13,4,5,1 };
	int c[] = { 1,4,6,871,1 };
	int arr2[][5] = { 1,2,3,4,5 ,2,13,4,5,1,1,4,6,871,1 };
	int* arr[] = { a,b,c };

}
void test2()
{
	int threeDArray[2][3][4] = {
	{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
	{{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
	};
	int(*ptr)[3][4] = threeDArray;
	printf("%d", (*ptr)[2][3]);

}
void test3() 
{


	
		// 声明和初始化三维数组
		int threeDArray[2][3][4] = {
			{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
			{{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
		};

		// 声明指向三维数组的指针
		
		int(*ptr)[3][4] = threeDArray;
		int* p = threeDArray;
		int* a[] = { &threeDArray[1][2][3],&threeDArray[1][2][3] };
		// 访问三维数组元素
		printf("%d\n", (*ptr)[0][0]);
		printf("%d\n", (*ptr)[2][3]); 
		printf("%d\n", ((*ptr)+1)[2][3]);
		printf("%d\n", (*ptr+1)[2][3]);
		printf("%d\n", *(  ptr + 1)[0][0]);
		return 0;
		//13  :0x006EFB50
	    //*ptr:0x006EFB20
//threeDArray ;0x006EFB20
	 //*ptr+1：0x006EFB30
}
void test4() 
{
	
	int threeDArray[2][3][4] = {
		{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
		{{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
	};

	int(*ptr)[3] = threeDArray;
	int(*ptr2)[4] = *ptr;
	printf("%d",(*ptr2)[0] );
	
	

	

}
int main() 
{
	test3();
	return 0;
}
