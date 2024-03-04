#include<stdio.h>
void boble(int arr[], int sz) {
	int i;
	int j;
	int tem;
	for (i = sz - 1; i > 0; i--) 
	{
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) 
			{
				tem = arr[i];
				arr[i] = arr[j];
				arr[j] = tem;

			}
		}
	}

}
void boble2(int arr[], int sz) {
	int i;
	int j;
	int tem;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = i+1; j <sz - i -1; j++) {//不能这样写每一轮交换结束j就成12345前面的元素就访问不到
			if (arr[j-1] > arr[j])
			{
				tem = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tem;

			}
		}
	}
	
}
void boble3(int arr[], int sz) {
	int i;
	int j;
	int tem;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++) {
			if (arr[j] > arr[j + 1])
			{
				tem = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tem;

			}
		}
	}

}
int main()
{
	int arr[] = { 5,3,2,4,8,7,9,10,6,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//boble(arr,sz);
	boble2(arr, sz);
	int i;
	for (i = 0; i < sz; i++) {
		printf("%d\t", arr[i]);
	}
	
	return 0;
}
