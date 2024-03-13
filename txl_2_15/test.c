#include<stdio.h>
#include"contact.h"

int main()
{
	enum ctrl//使用枚举类创造一堆象征意义的常量
	{
		exit,
		print,
		modify,
		del,
		sort,
		add,
		find

	};
	txl t;
	int input = 0;
	Initailizetxl(&t);//初始化
	do
	{
		printf("*******0.exit      1.print*******\n");
		printf("*******2.modify   3.del*******\n");
		printf("*******4.sort     5.add*******\n");
		printf("*******6.find          *******\n");

		scanf("%d", &input);//按提示输入
		switch (input)//根据输入调用函数
		{
		case add:
			AddInformation(&t);
			break;
		case print:
			PrintContact(&t);
			break;
		case modify:
			ModifyInformation(&t);
			break;
		case del:
			DelegateInformation(&t);
			break;
		case sort:
			SortInformation(&t);
		case find:
			FindInformation(&t);
			break;
		case exit:
			destoryInformation(&t);
			printf("已退出通讯录\n");
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}

	} while (input);



	return 0;
}


