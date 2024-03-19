#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[20];
    char sex[10];
    int age;
    char address[20];
    int number;
} contacter;

contacter* addInformation(contacter* p, int capacity) {
    contacter* ptr = (contacter*)realloc(p, sizeof(contacter) * capacity);
    if (ptr != NULL) {
        p = ptr;
    }
    return p; // 返回重新分配后的指针
}

int main() {
    contacter* p = (contacter*)malloc(sizeof(contacter));
    if (p == NULL) {
        printf("申请空间失败");
        return 1;
    }
    int num;
    printf("请输入新的容量：");
    scanf("%d", &num);
    p = addInformation(p, num);
    free(p);
    p = NULL;
    return 0;
}

//int main() 
//{
//	int* p = (int*)malloc(sizeof(int)*10);
//	if (p == NULL) 
//	{
//		return 1;
//	}
//	for (int i = 0; i < 10; i++) 
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10; i++) 
//	{
//		printf("%d", p[i]);
//	}
//	free(p);
//	return 0;
//}

//int main() 
//{
//	int* p = (int*)calloc(10,sizeof(int) );
//	if (p == NULL)
//	{
//		return 1;
//	}
//	int* ptr = (int*)realloc(p, 12 * sizeof(int));
//		if (ptr != NULL) 
//	{
//		p = ptr;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ",p[i]);
//	}
//	//输出：0 0 0 0 0 0 0 0 0 0
//	free(p);
//	return 0;
//}