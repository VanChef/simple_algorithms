/* 多数投票算法
 *在一个数组中，元素个数为n（假设最多投票元素存在），输出元素出现次数大于n/2的数
 *
 *
 * 
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int Majority_Voting(int *input, int len) {

    int i;
    int cand = -1;
    int count = 0;

    for (i = 0; i < len; i++) {
        if (count == 0)
        {
            count = 1;
            cand = input[i];
        }
        else if (input[i] == cand)
            count++;  
        else 
            count--;
    }
    return cand;
}

int main()
{
    int a[10] = {4,6,4,7,4,10,4,22,4,4};

    printf("result %d\n", Majority_Voting(a, 10));
}

