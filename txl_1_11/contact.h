#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Name_Max 20
#define SEX_MAX 10
#define Address_MAX 10
typedef struct
{
	char name[Name_Max];
	char sex[SEX_MAX];
	int age;
	char address[Address_MAX];
	int number;

}contacter;
typedef struct
{
	contacter c[1000];
	int sz;
}txl;

int  AddInformation(txl* p);
int DelegateInformation(txl* p);
int ModifyInformation(txl* p);
int FindInformation(txl* p);
int SortInformation(txl* p);
void PrintContact(txl* p);
void Initailizetxl(txl* p);
