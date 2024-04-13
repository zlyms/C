#include<stdio.h>
#define blue 2
union un {
    char a[5];
    int i;

};
struct MyStruct
{
    char a : 4;
    char b : 4;
    char c : 4;
    char d : 4;
};
enum color{
    red,
    green
};
int main()
{
   /* struct MyStruct s = { 2, 3, 4, 5 };
    enum color c = red;
    int a = red;
    int b = blue;*/
    union un u;
    printf("%p\n", &(u.a));
    printf("%p", &(u.i));
    return 0;
}
