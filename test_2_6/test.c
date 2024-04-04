#include <stdio.h>

// ������������һ���ֽ�Ϊ��λ���н��������������������������
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
//�ȽϺ���
int cmp_int(void* e1, void* e2) {//void����ָ����Խ�����������
    return (*(int*)e1) - (*(int*)e2);
}

// ð��������
void bubbleSort(void *base, int sz,int l, int (*cmp_int)(const void* e1, const void* e2)) {//base����ʼλ�ã�sz�������С��l��Ԫ�س��ȣ�cmp_int���ȽϺ�����ָ��
    
    int i, j;
    for (i = 0; i < sz - 1; i++) {
        // ���� i ��Ԫ���Ѿ���λ������Ҫ�ٱȽ�
        for (j = 0; j < sz - i - 1; j++) {
            if (cmp_int( (char*)base + j * l, (char*)base + (j + 1) * l)>0 )
            {
                swap((char*)base + j * l, (char*)base + (j + 1) * l,l);
            }
            
        }
    }
}

// ��ӡ���麯�������������������
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ������
int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("ԭʼ����: \n");
    printArray(arr, sz);
    bubbleSort(arr, sz,4, cmp_int);
    printf("����������: \n");
    printArray(arr, sz);
    return 0;
}
