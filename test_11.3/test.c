#include<stdio.h>
int main() 
{
	int a = 1, b = 2;
	int i = a || ++b;//左结合，已经为真不执行右侧语句
	printf("%d", b);
}
/* 运算符优先级和结合性：
   最高优先级 (左结合性)：
   - ()      圆括号、方括号
   - ->      成员选择（通过指针访问结构体成员）
   - .       成员选择（通过结构体变量访问成员）

   高优先级 (左结合性)：
   - ++, --  自增自减
   - (类型)  强制类型转换
   - !, ~, -  逻辑非、按位取反、负号
   - *, /, %  乘法、除法、取余
   - +, -    加法、减法

   相同优先级 (左结合性)：
   - <<, >>  位左移、位右移
   - <, <=, >, >=  关系运算：小于、小于等于、大于、大于等于
   - ==, !=  关系运算：等于、不等于
   - &       按位与
   - ^       按位异或
   - |       按位或
   - &&      逻辑与
   - ||      逻辑或

   低优先级 (右结合性)：
   - ?:      条件运算符
   - =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=  赋值运算符

   最低优先级 (左结合性)：
   - ,       逗号运算符
*/