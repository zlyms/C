//#include<stdio.h>
//int Digtal_sum(int n) 
//
//{
//	int tem = n % 10;//tem��ÿ��λ
//	if (n > 0) {
//		n /= 10;
//
//		return tem+ Digtal_sum(n);//Digtal_sum������һ��ĺ�
//	}
//	
//
//}
//int main() 
//{
//	int num = 1749;
//	
//	printf("sum=%d", Digtal_sum(num));
//}
#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char target) {

    if (n > 0) {
        //ͨ����������λ��ʵ��ת��
        // ��n-1�����Ӵ�Դ���ƶ���������
        hanoi(n - 1, source, target, auxiliary);//��ʼλ������λ��Ŀ��λ

        // �������һ�����Ӵ�Դ���ƶ���Ŀ����
        printf("%c, % c, %c|", source, auxiliary, target);
        printf("������ %d �� %c �ƶ��� %c\n", n, source, target);

        // ��n-1�����ӴӸ������ƶ���Ŀ����
        hanoi(n - 1, auxiliary, source, target);//ÿ�ζ���ݹ��������ס��Դ���ظ�����
    }
}

int main() {
    
    int n;
    printf("���������ӵ�������");
    scanf_s("%d", &n);
    printf("�ƶ����ӵĲ������£�\n");
    hanoi(n, 'A', 'B', 'C');
    return 0;
}