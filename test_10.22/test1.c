#include<stdio.h>
static char board[3][5] = { { 'a','b','c','d','e'} ,{ 'a','b','c','d','e'}, { 'a','b','c','d','e'} };//全局变量，防止指针成野指针
char* pin()

{
	return &board[2][1];

}

int main()
{
	
	char* ret = pin(board);
	char a[] = "dsadas";
	 a[2] = *ret+1;
	
	printf("%c\n",a[2]);
	return 0;
}

