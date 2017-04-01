/* 
 * 借鉴快速排序的方式查找一个数组的中位数，可理解为“带特定位置的快排”
 * step1，给定数组：
 *                  y z x z x z x x x x，其中y为第一个数，z比y大，x比y小
 * step2: 遍历除y之外的数，大于y放到数组末尾，小于y放到数组起始
 *                  y x x x x x x z z z
 * step3: 交换y至中间位置
 *                  x x xxxxxxzzz       */



#include <stdio.h>
#include <stdlib.h>

//swap the data in postin l and k 
void swap(int *data, int l, int k) {
    int tmp;
    tmp = *(data + l);
    *(data + l) = *(data + k);
    *(data + k) = tmp;
}

int median(int *data, int size, int mid) {

    int i, j, k, tmp;
    int a = data[0];
    int marker;
    k = size;

    printf("size %d, mid %d\n", size, mid);

    for (k = 0; k < size; k++) {
        printf("%d, ", data[k]);
    }
    printf("\n");
    k = size;

    if (size <= 2)
        return 0;

    for (i = 1; i < k;) {
        if (a <= data[i]) {
            swap(data, i, k - 1);
            k = k - 1;
        } else {
            i ++;
        }
    }

    marker = i - 1;
    printf("re marker %d, data[marker] %d\n", marker, data[marker]);
    swap(data, 0, marker);

    for (k = 0; k < size; k++) {
        printf("%d, ", data[k]);
    }
    printf("\n");

    if (marker > mid)
        return median(data, marker, mid);
    else if (marker < mid)
        return (i + median(data + marker + 1, size - marker - 1, mid - marker - 1));
    else
        return marker;
}

int main()
{
    const int size = 10;
    int test[size] = {4, 100, 101, 102 , 103, 7, 10, 55, 66, 88};
    int i;
    int k = 0;
    int mid = size / 2 - 1;

    i = median(test, size, mid);

    printf("i %d, test[i] %d\n", i, test[i]);
    for (i = 0; i < size; i++) {
        printf("%d, ", test[i]);
    }
    printf("\n");
    return 0L;
}


