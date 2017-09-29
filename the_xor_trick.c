/*
 * 问题：两个数组，其中一个数组比另一个少了一个元素，其余元素相同，请找出
 * 要求：算法复杂度o(n)
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int find_missing(int *in1, int size1, int *in2, int size2)
{
    int xor_a = 0;
    int xor_b = 0;

    int xor_total = 0;
    int i = 0;

    for (i = 0; i < size1; i++) {
        xor_a = xor_a ^ in1[i];
    }

    for (i = 0; i < size2; i++) {
        xor_b = xor_b ^ in2[i];
    }

    xor_total = xor_a ^ xor_b;

    return xor_total;
}


int main()
{
    int in1[] = {10, 9, 5, 6, 111, 8, 20};
    int in2[] = {10, 9, 5, 6, 111, 8};
    int result;

    result = find_missing(in1, 7, in2, 6);


    printf("result %d\n", result);

    return 0L;
}



