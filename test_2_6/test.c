#include <stdio.h>

// 交换函数，以一个字节为单位进行交换，交换趟数与数据类型相关
void swap(char* xp, char* yp,int l) {
    char temp ;
    for (int i = 0; i < l; i++) 
    {
        temp=*xp;
        *xp = *yp;
        *yp=temp;
        yp++;
        xp++;
    }
}
//比较函数
int cmp_int(void* e1, void* e2) {//void类型指针可以接受任意类型
    return (*(int*)e1) - (*(int*)e2);
}

// 冒泡排序函数
void bubbleSort(void *base, int sz,int l, int (*cmp_int)(const void* e1, const void* e2)) {//base：起始位置，sz：数组大小，l：元素长度，cmp_int：比较函数的指针
    
    int i, j;
    for (i = 0; i < sz - 1; i++) {
        // 最后的 i 个元素已经就位，不需要再比较
        for (j = 0; j < sz - i - 1; j++) {
            if (cmp_int( (char*)base + j * l, (char*)base + (j + 1) * l)>0 )
            {
                swap((char*)base + j * l, (char*)base + (j + 1) * l,l);
            }
            
        }
    }
}

// 打印数组函数，用于输出数组内容
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 主函数
int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("原始数组: \n");
    printArray(arr, sz);
    bubbleSort(arr, sz,4, cmp_int);
    printf("排序后的数组: \n");
    printArray(arr, sz);
    return 0;
}
