//#include<stdio.h>
//int Digtal_sum(int n) 
//
//{
//	int tem = n % 10;//tem储每号位
//	if (n > 0) {
//		n /= 10;
//
//		return tem+ Digtal_sum(n);//Digtal_sum保存上一层的和
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
        //通过交换变量位置实现转移
        // 将n-1个盘子从源柱移动到辅助柱
        hanoi(n - 1, source, target, auxiliary);//初始位，辅助位，目标位

        // 将最底下一个盘子从源柱移动到目标柱
        printf("%c, % c, %c|", source, auxiliary, target);
        printf("将盘子 %d 从 %c 移动到 %c\n", n, source, target);

        // 将n-1个盘子从辅助柱移动到目标柱
        hanoi(n - 1, auxiliary, source, target);//每次二层递归结束辅助住成源柱重复操作
    }
}

int main() {
    
    int n;
    printf("请输入盘子的数量：");
    scanf_s("%d", &n);
    printf("移动盘子的步骤如下：\n");
    hanoi(n, 'A', 'B', 'C');
    return 0;
}