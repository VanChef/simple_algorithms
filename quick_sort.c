

/*
 * 
 * 快速排序，用迭代的方法实现
 * 
 * */

#include <stdio.h>

void swap(int *in, int l, int n) {
    int tmp;

    tmp = *(in + l);
    *(in + l) = *(in + n);
    *(in + n) = tmp;
}

void quick_sort(int *in, int num)
{
    int l,n,i;
    l = 1;
    n = num;

    if (num <= 1) {
        return;
    }

    for (l = 1; l < n;)//遍历in中所有数据
    {
        if (*(in + l) > in[0]) {
            swap(in, l, n - 1);
            n--;
        } else {
            l ++;
        }
        if (l >= n) {
            break;
        }
    }
 
    swap(in, 0, l - 1);

    quick_sort(in, l - 1);
    quick_sort(in + l, num - l);
}

int main()
{
    int a[10] = {1,4,3,6,7,9,0,-1,-9,-8};
    int i;

    quick_sort(a, 10);

    printf("result :\n");
    for (i = 0; i < 10; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");

    return 0L;
}

