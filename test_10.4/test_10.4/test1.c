#include<stdio.h>
//ººÅµËş
int count = 0;
void hanota(int n,char a,char b,char c) {
	if (n == 1)
	{
		count++;
		printf("%d,%c->%c\n",count, a, c);

	}
	else 
	{
		
		hanota(n - 1, a, c, b);
		printf("%d,%c->%c\n", ++count, a, c);
		hanota(n - 1, b, a, c);
	}
}

int main()

{
	hanota(4,'A','B','C');
	return 0;
}