
/*
 * 常见题目：给定一个已排序数组，判断一个数是否在该数组中
 * 如果在，返回改数在数组中的下标，否则返回-1
 * 采用二分法查找
 */

#include <stdio.h>
#include <stdlib.h>

int binary_search(int *in, int size, int target)
{
    int left, right, mid;
    int i;
    
    left = 0;
    right = size - 1;

    while(left + 1 < right) {
        mid = left + ((right - left) >> 1);

        printf("left %d, mid %d, right %d\n", left, mid, right);
        if (in[mid] > target)
            right = mid;
        else if (in[mid] < target)
            left = mid;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int in[] = {1, 4, 6, 9, 10, 11, 16, 44, 56, 66, 88};
    int result;

    result = binary_search(in, 11, 19);
    printf("result %d\n", result);

    return 0L;
}

