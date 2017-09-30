

/*
leetcode题目，将一个排序数组中的重复元素去除
2.1.1 Remove Duplicates from Sorted Array
  
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
 *
 */

#include <list>
#include <iostream>

using namespace std;


int remove_duplicate(int *in, int size)
{
    int i = 0, j = 1;
    int current_value;

    if (!in)
        return 0;

    current_value = in[0];

    for (i = 1; i < size; i++) {
        if (in[i] != current_value) {
            in[j++] = in[i];
            current_value = in[i];
        }
    }

    return j;
}

int main()
{
    int in[] = {1, 5, 9, 11, 11, 11, 11, 15, 19};
    int i;
    int ret_size;

    ret_size = remove_duplicate(in, 9);

    for (i = 0; i < ret_size; i++) {
        printf("%d, ", in[i]);
    }
    printf("\n");
    return 0L;
}


